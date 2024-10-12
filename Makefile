# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Directories
SRC_DIR = src
TEST_DIR = test
BUILD_DIR = build

# Source and test files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
TEST_FILES = $(wildcard $(TEST_DIR)/*.c)

# Executable names
MAIN_EXEC = $(BUILD_DIR)/main
TEST_EXEC = $(BUILD_DIR)/test

# Default target
all: | $(BUILD_DIR) $(MAIN_EXEC)

# Compile the main executable
$(MAIN_EXEC): $(SRC_FILES)
	$(CC) $(CFLAGS) -o $@ $^

# Compile the test executable
test: | $(BUILD_DIR) $(TEST_EXEC)

$(TEST_EXEC): $(SRC_FILES) $(TEST_FILES)
	$(CC) $(CFLAGS) -DTEST_MODE -o $@ $(SRC_FILES) $(TEST_FILES)

# Create the build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $@

# Clean up
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all test clean
