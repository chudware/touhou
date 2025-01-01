# Directories
SRC_DIR = src
BUILD_DIR = build

# Compiler and linker flags
GBDK = /Users/anon/Downloads/gbdk
CC = $(GBDK)/bin/lcc
CFLAGS = -Wa-l -Wl-m -Wl-j
LDFLAGS = -Wm-yc

# Source files
SOURCES := $(wildcard $(SRC_DIR)/*.c)
OBJECTS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SOURCES))

# Target
TARGET = $(BUILD_DIR)/_touhou.gb

all: $(TARGET)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

clean:
	rm -rf $(BUILD_DIR)
