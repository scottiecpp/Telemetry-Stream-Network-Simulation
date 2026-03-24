#include "telemetryPacket.h"

#include <sstream>
#include <iomanip>
#include <stdexcept>

std::string telemetryPacket::toString() const {
    std::ostringstream oss;

    oss << "TIME:" << timestamp
        << " TEMP:" << std::fixed << std::setprecision(1) << temperature
        << " BAT:" << std::fixed << std::setprecision(1) << battery
        << " VOLT:" << std::fixed << std::setprecision(1) << voltage;

    return oss.str();
}

telemetryPacket telemetryPacket::fromString(const std::string& line) {
    telemetryPacket packet;

    std::istringstream iss(line);
    std::string temp;

    try {

        //Parse TIME
        if (!(iss >> temp) || temp.find("TIME:") != 0)
            throw std::invalid_argument("Missing TIME field");
        packet.timestamp = temp.substr(5);

        //Parse TEMP
        if (!(iss >> temp) || temp.find("TEMP:") != 0)
            throw std::invalid_argument("Missing TEMP field");
        packet.temperature = std::stod(temp.substr(5));

        //Parse BAT
        if (!(iss >> temp) || temp.find("BAT:") != 0)
            throw std::invalid_argument("Missing BAT field");
        packet.battery = std::stod(temp.substr(4));

        //Parse VOLT
        if (!(iss >> temp) || temp.find("VOLT:") != 0)
            throw std::invalid_argument("Missing VOLT field");
        packet.voltage = std::stod(temp.substr(5));
    } catch (const std::exception& e) {
        packet.timestamp = "";
        packet.temperature = 0;
        packet.battery = 0;
        packet.voltage = 0;
    }

    return packet;

}

bool telemetryPacket::isValid() const {
    if (timestamp.empty())
        return false;

    if (temperature < -100.0 || temperature > 200)
        return false;

    if (battery < 0.0 || battery > 100.0)
        return false;

    if (voltage < 0.0 || voltage > 5.0)
        return false;

    return true;
}
