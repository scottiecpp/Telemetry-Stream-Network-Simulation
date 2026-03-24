#include "groundUtil.h"
#include "telemetryPacket.h"
#include "networkUtil.h"
#include "logger.h"

#include <iostream>

void runGroundStation(int port) {
    int server_fd = setupServerSocket(port);
    if (server_fd < 0) {
        std::cerr << "Server setup failed" << std::endl;
        return;
    }

    std::cout << "Waiting for satellite..." << std::endl;

    int client_fd = acceptClient(server_fd);
    if (client_fd < 0) {
        std::cerr << "Accept failed" << std::endl;
        return;
    }

    std::cout << "Satellite connected!" << std::endl;

    logger lgr("logs/log.csv");

    while (true) {
        std::string line = recvLine(client_fd);

        if (line.empty()) {
            std::cout << "Connection closed" << std::endl;
            break;
        }

        telemetryPacket packet = telemetryPacket::fromString(line);

        if (packet.isValid()) {
            std::cout << "Received: " << packet.toString() << std::endl;
            lgr.log(packet);
        } else {
            std::cout << "Invalid packet: " << line << std::endl;
        }
    }

    closeSocket(client_fd);
    closeSocket(server_fd);
}
