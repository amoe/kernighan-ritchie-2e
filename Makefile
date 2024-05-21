# Directories containing the source files
EXERCISES_DIR := exercises
MISC_DIR := misc-programs
BUILD_DIR := build

# Find all C files in the specified directories
EXERCISES_SRCS := $(wildcard $(EXERCISES_DIR)/*.c)
MISC_SRCS := $(wildcard $(MISC_DIR)/*.c)

# Define the executables by replacing the .c extension with no extension and placing them in the build directory
EXERCISES_EXES := $(patsubst $(EXERCISES_DIR)/%.c,$(BUILD_DIR)/%,$(EXERCISES_SRCS))
MISC_EXES := $(patsubst $(MISC_DIR)/%.c,$(BUILD_DIR)/%,$(MISC_SRCS))

# Combine all source files and executables
SRCS := $(EXERCISES_SRCS) $(MISC_SRCS)
EXES := $(EXERCISES_EXES) $(MISC_EXES)

# Compiler and flags
CC := clang
CFLAGS := -Wall -Wextra -O2 -std=c89

# Default target to build all executables
all: $(EXES)

# Create build directory if it does not exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Rule to build each executable from exercises
$(BUILD_DIR)/%: $(EXERCISES_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $<

# Rule to build each executable from misc-programs
$(BUILD_DIR)/%: $(MISC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $<

# Clean target to remove all executables
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
