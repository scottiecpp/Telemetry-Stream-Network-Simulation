# Telemetry Stream Simulation <br>
This project simulates real-time telemetry data transmission from a satellite to a ground station. It is a C++ TCP-based client-server system. The purpose of this system is to demonstrate low-level socket programming, data serialization, 
file manipulation (logging), and a modular software design. This was done using C++ and POSIX sockets in a Linux environment (Ubuntu) <br>
## Project Overview <br>
### Satellite (Client) <br>
  - Generates telemetry packets at fixed intervals
  - Serializes packet data into a string format
  - Sends over TCP connection to ground station
### Ground Station (Server) <br>
  - Listens for incoming TCP connections
  - Recieves telemetry packets (newline-delimited)
  - Parses and validates incoming data
  - Deserializes and logs valid data into CSV file (log.csv)
## Project Structure <br>
```
TelemetryStream/
│
├── src/
│   ├── main_satellite.cpp
│   ├── main_ground.cpp
│   ├── telemetryPacket.h / .cpp
│   ├── telemetryGenerator.h / .cpp
│   ├── networkUtil.h / .cpp
│   ├── logger.h / .cpp
│   ├── satelliteUtil.h / .cpp
│   └── groundUtil.h / .cpp
│
├── logs/
│   └── telemetry_log.csv
│
├── Makefile
└── README.md
```
## How to Run <br>
### Prerequisites <br>
  - Linux Environment (tested on Ubuntu)
  - g++ with C++17 support
  - make <br>
### 1. Clone Repository
  - git clone https://github.com/scottiecpp/Telemetry-Stream-Network-Simulation
  - cd TelemetryStream
### 2. Build
  - make
This will compile two executables: ground (server) and satellite (client).
### 3. Run the Ground Station
  - ./ground <br>
The server will start and listen for incomming connections.
### 4. Run the Satellite
  - ./satellite <br>
The client will connect to the ground station and start sending telemetry data.
### Example Output:
Satellite: <br>
Sending: TIME:12:01 TEMP:23.4 BAT:95.6 VOLT:3.7 <br>
Ground Station: <br>
Received: TIME:12:01 TEMP:23.4 BAT:95.6 VOLT:3.7 <br>
### Notes
  - Run the server before the client
  - Default connection uses 127.0.0.1 and port 8080
  - These values can be changed in main_satellite.cpp and main_ground.cpp
  - Currently, the client will send 10 packets before closing, but this number can be changed or the for loop can be modified to a while (true)
to continue looping without limitations in satelliteUtil.cpp
## Takeaway
When doing network programming using TCP, it is important to ensure all data is being sent/received. Although, TCP ensures all data will be sent,
it does not guarantee that it will be done in one function call. I tracked the number of bytes sent succesfully, and continued sending until the
was equal to the expected length of the data. This required careful buffer management, ensuring each subsequent send operation started from the
correct offset to avoid retransmitting duplicate data. When receiving data I used a newline (\n) to mark the end of the transmission.
## Future Improvements
  - Multi-client support using threads/forking
  - Command-line configuration for IP and port
