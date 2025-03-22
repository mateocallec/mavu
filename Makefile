# Variables
CXX = g++
CXXFLAGS = -std=c++17 -Iinclude -Wall -Wextra -pedantic

# Source and binary directories
SRC_DIR = src
BUILD_DIR = build
TARGET = $(BUILD_DIR)/mavu

# Find all .cpp files in src/ and its subdirectories
SRC_FILES := $(shell find $(SRC_DIR) -name '*.cpp')
OBJ_FILES := $(SRC_FILES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Create build directory (if it doesn't exist)
$(shell mkdir -p $(BUILD_DIR))

# Default rule: compile the executable
$(TARGET): $(OBJ_FILES)
	$(CXX) $(OBJ_FILES) -o $(TARGET)

# Rule to compile each .cpp file to an object .o file
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to clean generated files
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Rule to remove object files and executable
distclean: clean
	rm -f $(TARGET)

.PHONY: clean distclean
