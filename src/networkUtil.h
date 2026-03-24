#ifndef NETWORKUTIL_CPP
#define NETWORKUTIL_CPP

#include <string>

//client
int connectToServer(const std::string& ip, int port);

//server
int setupServerSocket(int port);
int acceptClient(int server_fd);

//data transfer
bool sendAll(int sock, const std::string& data);
std::string recvLine(int sock);

//cleanup
void closeSocket(int sock);

#endif

