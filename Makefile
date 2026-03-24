CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

SRC = src

COMMON = $(SRC)/telemetryPacket.cpp \
         $(SRC)/telemetryGenerator.cpp \
         $(SRC)/networkUtil.cpp \
         $(SRC)/logger.cpp

GROUND = $(SRC)/main_ground.cpp \
         $(SRC)/groundUtil.cpp \
         $(COMMON)

SATELLITE = $(SRC)/main_satellite.cpp \
            $(SRC)/satelliteUtil.cpp \
            $(COMMON)

all: ground satellite

ground:
	$(CXX) $(CXXFLAGS) $(GROUND) -o ground

satellite:
	$(CXX) $(CXXFLAGS) $(SATELLITE) -o satellite

clean:
	rm -f ground satellite
