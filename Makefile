# Compiler settings - Can change based on compiler availability
CXX = g++
CC = gcc
CFLAGS = -O3 -I$(INC_DIR) -I$(BLAKE3_DIR)
CXXFLAGS = -std=c++11 -O3 -pthread -I$(INC_DIR) -I$(BLAKE3_DIR)
LDFLAGS += -pthread -L/usr/lib/aarch64-linux-gnu -lcpu_features

# Include and Source directories
INC_DIR = ./include
BLAKE3_DIR = ./blake3/c
SRC_DIR = ./src
OBJ_DIR = ./obj
BIN_DIR = ./bin

# Files
EXEC = $(BIN_DIR)/hashgen
SOURCES_CPP += $(wildcard $(SRC_DIR)/*.cpp) $(SRC_DIR)/cpu_features.cpp
SOURCES_C = $(wildcard $(BLAKE3_DIR)/blake3.c) $(wildcard $(BLAKE3_DIR)/blake3_dispatch.c) $(wildcard $(BLAKE3_DIR)/blake3_portable.c)

OBJECTS = $(SOURCES_CPP:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o) $(SOURCES_C:$(BLAKE3_DIR)/%.c=$(OBJ_DIR)/%.o)

# Default target
all: $(EXEC)

# Executable target
$(EXEC): $(OBJECTS)
	mkdir -p $(BIN_DIR)
	$(CXX) $(LDFLAGS) $^ -o $@

# To compile C++ source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INC_DIR)/%.h
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# To compile C source files
$(OBJ_DIR)/%.o: $(BLAKE3_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Phony targets
.PHONY: all clean
