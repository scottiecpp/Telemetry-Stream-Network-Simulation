/* File: groundUtil.h
 *
 * Contains main functionality for the ground station (server).
 *
 * Author: Richard Scott Gisondi
 * */

#ifndef GROUNDUTIL_H
#define GROUNDUTIL_H

/* runGroundStation()
 *
 * Utilizes helper functions from networkUtil.h to setup the server. Creates socket,
 * binds to a port, and listens for/accepts client connections. Provides error handling
 * for these capabilities. Once connection is secured, it receives serialized data
 * and logs results into log.csv. Cleans up sockets.
 *
 * Param: port - port to connect to. Currently uses localhost IP address.
 *
 * Return - void
 * */
void runGroundStation(int port);

#endif
