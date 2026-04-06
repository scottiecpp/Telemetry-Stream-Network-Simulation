/* File: telemetryGenerator.h
 *
 * Contains functionality to create telemetryPacket objects.
 *
 * Author: Richard Scott Gisondi
 * */

#ifndef TELEMETRYGENERATOR_H
#define TELEMETRYGENERATOR_H

#include "telemetryPacket.h"

/* telemetryGenerator - struct
 *
 * Contains generate() function to create telemetryPacket objects.
 * */
struct telemetryGenerator {
    /* generate()
     *
     * Constructs a telemetryPacket object using random data confined to
     * specific ranges.
     *
     * return - a telemetryPacket object.
     * */
    static telemetryPacket generate();
};

#endif //TELEMETRYGENERATOR_H
