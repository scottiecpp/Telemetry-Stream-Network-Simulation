/* File - telemetryPacket.h
 * 
 * This file contains the definition of the telemetryPacket struct, which represents
 * a single transmission of telemetry data including a timestamp, temperature, 
 * battery level, and voltage.
 *
 * Author - Richard Scott Gisondi
 */

#ifndef TELEMETRYPACKET_H
#define TELEMETRYPACKET_H

#include <string>

/* telemetryPacket - struct
 *
 * This struct stores telemetry info including timestamp, 
 * temperature, battery, and voltage. In addition, it provides utility functions
 * for serialization/deserialization and validation.
 */
struct telemetryPacket {
    //data being stored in object
    std::string timestamp;
    double temperature;
    double battery;
    double voltage;

    /* toString()
     *
     * Converts telemetryPacket object into a formatted string, suitable for
     * transmission.
     *
     * return - a string representation of a telemetryPacket object.
     * */
    std::string toString() const;

    /* fromString()
     *
     * Parses a formatted string and creates a telemetryPacket object.
     * 
     * param - line: a formatted string to be parsed and deserialized into an object.
     * return - a telemetryPacket object
     * */
    static telemetryPacket fromString(const std::string& line);

    /* isValid()
     *
     * Checks if the telemetryPacket object contains valid data within expected ranges
     *
     * return - True if data is valid, false if data is not.
     * */
    bool isValid() const;
};

#endif

