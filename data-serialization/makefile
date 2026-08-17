CC := gcc

CPPFLAGS := -Iinc -Isrc -D_DEFAULT_SOURCE -MMD -MP
CFLAGS := \
	-std=c99 \
	-g \
	-pedantic \
	-Wall \
	-Wextra \
	-Werror \
	-Wpointer-arith \
	-Wshadow \
	-Wuninitialized \
	-Wunused-function \
	-Wmissing-declarations \
	-Wmissing-prototypes \
	-Wstrict-prototypes \
	-Wconversion \
	-Wsign-conversion \
	-Wcast-align \
	-fno-builtin \
	-fno-common \
	-finput-charset=UTF-8 \
	-Werror=date-time
LDFLAGS :=
LDLIBS :=

BUILD_DIR := build
OBJ_DIR := $(BUILD_DIR)/obj
BIN_DIR := $(BUILD_DIR)/bin

ifeq ($(OS),Windows_NT)
EXEEXT := .exe
endif

TARGET := $(BIN_DIR)/logbook$(EXEEXT)

# main.c remains at the project root; implementation files are discovered
# automatically whenever a .c file is added to src/.
SOURCES := main.c $(sort $(wildcard src/*.c))
OBJECTS := $(addprefix $(OBJ_DIR)/,$(notdir $(SOURCES:.c=.o)))
DEPS := $(OBJECTS:.o=.d)

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CC) $(LDFLAGS) $(OBJECTS) $(LDLIBS) -o $@

$(OBJ_DIR)/main.o: main.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	$(TARGET)

clean:
	rm -rf $(BUILD_DIR)

-include $(DEPS)
