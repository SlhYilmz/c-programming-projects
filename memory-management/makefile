# Makefile for compiling C code

# Compiler
CC := gcc

# Compiler flags
CFLAGS := -std=c17 -Wall -Wextra -pedantic -D_DEFAULT_SOURCE

# Linker flags
LDFLAGS :=  #-pthread -lrt

# Source Files
SOURCES := main.c

# Object files
OBJECTS := $(SOURCES:.c=.o)

# Executables
TARGET := main

# Phony targets (targets that are not associated with files)
.PHONY: all clean

# Default target
all: $(TARGET)

# Rule for generating the executable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)

# Rule for compiling C source files
%.o: %.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c -o $@ $<

# Cleanup target
clean:
	rm -f $(TARGET) $(OBJECTS)