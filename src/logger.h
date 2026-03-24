#ifndef LOGGER_H
#define LOGGER_H

#include "telemetryPacket.h"
#include <string>

class logger {
public:
    logger(const std::string& filename);
    void log(const telemetryPacket& packet);

private:
    std::string filename;
};

#endif
