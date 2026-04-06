/* File: telemetryGenerator.cpp
 *
 * Contains implementation of telemetryGenerator.h
 *
 * Author: Richard Scott Gisondi
 * */

#include "telemetryGenerator.h"

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cstdio>

telemetryPacket telemetryGenerator::generate() {
    telemetryPacket packet;

    //Seed once
    static bool seeded = false;
    if (!seeded) {
        srand(static_cast<unsigned int>(time(nullptr)));
        seeded = true;
    }

    int hour = rand() % 24;
    int minute = rand() % 60;
    char buffer[9];
    snprintf(buffer, sizeof(buffer), "%02d:%02d", hour, minute);
    packet.timestamp = buffer;

    packet.temperature = -100.0 + static_cast<double>(rand()) / RAND_MAX * 300.0;
    packet.battery     = static_cast<double>(rand()) / RAND_MAX * 100.0;
    packet.voltage     = static_cast<double>(rand()) / RAND_MAX * 5.0;

    return packet;
}
