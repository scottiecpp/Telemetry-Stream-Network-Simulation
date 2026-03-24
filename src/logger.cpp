#include "logger.h"
#include <fstream>

logger::logger(const std::string& filename) : filename(filename) {}

void logger::log(const telemetryPacket& packet) {
    std::ofstream file(filename, std::ios::app);

    file << packet.toString() << std::endl;
    /*file << packet.timestamp << ", "
         << packet.temperature << ", "
         << packet.battery << ", "
         << packet.voltage << "\n";
    */
}

