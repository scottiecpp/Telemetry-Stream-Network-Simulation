#include "networkUtil.h"

#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <iostream>



//client
int connectToServer(const std::string& ip, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        return -1;
    }

    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);

    if(inet_pton(AF_INET, ip.c_str(), &serverAddr.sin_addr) <= 0) {
        perror("invalid address");
        return -1;
    }

    if (connect(sock, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("connect failed");
        close(sock);
        return -1;
    }

    return sock;
}

//server
int setupServerSocket(int port) {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket failed");
        return -1;
    }

    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("bind failed");
        close(server_fd);
        return -1;
    }

    if (listen(server_fd, 10) < 0) {
        perror("listen failed");
        close(server_fd);
        return -1;
    }    

    return server_fd;
    
}

int acceptClient(int server_fd) {
    int client_fd = accept(server_fd, nullptr, nullptr);
    if (client_fd < 0) {
        perror("accept failed");
        return -1;
    }

    return client_fd;
}

//data transfer
bool sendAll(int sock, const std::string& data) {
    std::string msg = data + "\n";

    size_t totalSent = 0;
    size_t length = msg.size();

    while (totalSent < length) {
        ssize_t sent = send(sock, msg.c_str() + totalSent, length - totalSent, 0);
        if (sent <= 0) {
            perror("send failed");
            return false;
        }
        totalSent += sent;
    }

    return true;
}

std::string recvLine(int sock) {
    std::string result;
    char c;

    while (true) {
        ssize_t bytes = recv(sock, &c, 1, 0);

        if (bytes <= 0) {
            return "";
        }

        if (c == '\n') {
            break;
        }

        result += c;
    }

    return result;
}

//cleanup
void closeSocket(int sock) {
    close(sock);
}
