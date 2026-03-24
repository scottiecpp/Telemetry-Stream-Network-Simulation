#ifndef TELEMETRYPACKET_H
#define TELEMETRYPACKET_H

#include <string>

struct telemetryPacket {
    std::string timestamp;
    double temperature;
    double battery;
    double voltage;


    std::string toString() const;

    static telemetryPacket fromString(const std::string& line);

    bool isValid() const;
};

#endif

