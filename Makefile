CC = gcc
CFLAGS = -Wall -Wextra -std=c11

SRC_DIR = src
TEST_DIR = test
BUILD_DIR = build

SRC_FILES = $(shell find $(SRC_DIR) -name '*.c')
TEST_FILES = $(shell find $(TEST_DIR) -name '*.c')

MAIN_EXEC = $(BUILD_DIR)/main
TEST_EXEC = $(BUILD_DIR)/test

all: | $(BUILD_DIR) $(MAIN_EXEC)

$(MAIN_EXEC): $(SRC_FILES)
	$(CC) $(CFLAGS) -o $@ $^

test: | $(BUILD_DIR) $(TEST_EXEC)

$(TEST_EXEC): $(SRC_FILES) $(TEST_FILES)
	$(CC) $(CFLAGS) -DTEST_MODE -o $@ $(SRC_FILES) $(TEST_FILES)

$(BUILD_DIR):
	mkdir -p $@

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all test clean
