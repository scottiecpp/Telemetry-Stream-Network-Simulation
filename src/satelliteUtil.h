/* File: satelliteUtil.h
 *
 * Contains the main functionality of the satellite (client)
 *
 * Author: Richard Scott Gisondi
 * */

#ifndef SATELLITEUTIL_H
#define SATELLITEUTIL_H

#include <string>

/* runSatellite()
 *
 * Utilizes client helper functions from networkUtil.h to connect to server,
 * performs error checking, and constructs and sends ten telemetryPacket objects
 * over a TCP socket connection.
 *
 * Param: ip - ip address to connect to (IPv4)
 *        port - server port
 *
 * return - void
 * */
void runSatellite(const std::string& ip, int port);

#endif
