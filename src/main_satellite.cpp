/* File: main_satellite.cpp
 *
 * Entry point for satellite (client) executable.
 *
 * Author: Richard Scott Gisondi
 * */

#include "satelliteUtil.h"

/* main()
 *
 * Entry point for 'satellite' executable. Calls helper function from satelliteUtil.h.
 * Uses localhost and port 8080 currently.
 *
 * Return - 0.
 * */
int main() {
    runSatellite("127.0.0.1", 8080);
    return 0;
}
