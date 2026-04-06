/* File: networkUtil.h
 *
 * Provides utility functions for TCP socket communication. Includes helper functions
 * for client connection and server setup, data transmission, and socket cleanup.
 *
 * Author: Richard Scott Gisondi
 * */

#ifndef NETWORKUTIL_H
#define NETWORKUTIL_H

#include <string>

//client functions

/* connectToServer()
 *
 * Establishes a TCP connection to a server.
 *
 * param: ip - The server IP address (IPv4).
 *        port - The server port number.
 *
 * return - Socket file descriptor on success, -1 on failure.
 * */
int connectToServer(const std::string& ip, int port);

//server functions

/* setupServerSocket()
 *
 * Creates, binds, and listens on a server socket.
 *
 * Param: port - the port number to bind to and listen on.
 *
 * Return - Server socket file descriptor on success, -1 on failure.
 * */
int setupServerSocket(int port);

/* acceptClient()
 *
 * Accepts an incoming client connection.
 *
 * Param: server_fd - The server socket file descriptor.
 *
 * Return - Client socket file descriptor on success, -1 on failure.
 * */
int acceptClient(int server_fd);

//data transfer functions

/* SendAll()
 *
 * Sends the full message over a socket connection.
 *
 * Param: sock - the socket's file descriptor.
 *        data - The data being sent.
 *
 * Return - True if full message was sent successfully, false if not.
 * */
bool sendAll(int sock, const std::string& data);

/* recvLine()
 *
 * Receives a line of text from a socket. Reads one byte at a time until a
 * newline (\n) is received.
 *
 * Param: sock - The socket's file descriptor.
 *
 * Return - The received string without the newline, or an empty string on failure.
 * */
std::string recvLine(int sock);

//cleanup function

/* closeSocket()
 *
 * Closes a socket connection.
 *
 * Param: sock - the socket to be closed.
 * */
void closeSocket(int sock);

#endif

