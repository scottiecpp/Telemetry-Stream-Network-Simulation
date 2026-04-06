/* File: satelliteUtil.cpp
 *
 * Contains the implementation of satelliteUtil.h
 *
 * Author: Richard Scott Gisondi
 * */

#include "satelliteUtil.h"
#include "telemetryGenerator.h"
#include "networkUtil.h"

#include <iostream>
#include <unistd.h>

void runSatellite(const std::string& ip, int port) {
    int sock = connectToServer(ip, port);
    if (sock < 0) {
        std::cerr << "Failed to connect\n";
        return;
    }

    std::cout << "Connected to ground station..." << std::endl;

    for (int i = 0; i < 10; i++) {
        telemetryPacket packet = telemetryGenerator::generate();
        std::string data = packet.toString();

        std::cout << "Sending: " << data << std::endl;

        if (!sendAll(sock, data)) {
            std::cerr << "Send failed" << std::endl;
            break;
        }

        sleep(1);
    }

    closeSocket(sock);
}
