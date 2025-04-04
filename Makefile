CXX = g++
CXXFLAGS = -std=c++17 -Iinclude -I/usr/include -Wall -Wextra -pedantic -O2
LDFLAGS = -L/usr/local/lib -static -lmagic -lz -llzma -lbz2

SRC_DIR = src
BUILD_DIR = build
TARGET = $(BUILD_DIR)/mavu

SRC_FILES := $(shell find $(SRC_DIR) -name '*.cpp')
OBJ_FILES := $(SRC_FILES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

$(shell mkdir -p $(BUILD_DIR))

$(TARGET): $(OBJ_FILES)
	$(CXX) $(OBJ_FILES) $(LDFLAGS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

distclean: clean
	rm -f $(TARGET)

.PHONY: clean distclean
