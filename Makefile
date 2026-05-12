# Compiler
CXX = g++

# Compiler Flags
CXXFLAGS = -Wall -Wextra -O2

# Targets
SERVER = server
CLIENT = client

# Source Files
SERVER_SRC = server.cpp
CLIENT_SRC = client.cpp

# Default Target: Build Both and Run
all: $(SERVER) $(CLIENT) run

# Build Server
$(SERVER) : $(SERVER_SRC)
	$(CXX) $(CXXFLAGS) $(SERVER_SRC) -o $(SERVER)

# Build Client
$(CLIENT) : $(CLIENT_SRC)
	$(CXX) $(CXXFLAGS) $(CLIENT_SRC) -o $(CLIENT)

# Clean generated binaries
clean:
	@rm -f $(SERVER) $(CLIENT)

# Run Server First Than Client
run: $(SERVER) $(CLIENT)
	./$(SERVER) & SERVER_PID=$$!; \
	sleep 1; \
	./$(CLIENT); \
	kill $$SERVER_PID