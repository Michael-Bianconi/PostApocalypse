# Build PixelFoundry

CC := gcc
VALGRIND := valgrind

# File extensions
SRC_EXT := c
OBJ_EXT := o

# Various directories
INC_DIR := -I ./include
SRC_DIR := ./src
OBJ_DIR := ./obj
BUILD_DIR := ./build
BIN_DIR := ./bin

RAYLIB_INC_DIR := -I /opt/raylib/src
RAYLIB_LFLAGS := /opt/raylib/release/libs/linux
RAYLIB_LIBS := -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

RM := rm

# Target executable
EXE_NAME := exec
TARGET := $(BIN_DIR)/$(EXE_NAME)

# Get all of the source files in /src
SRCS = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/*/*.c)

# Rule to compile sources into objects
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

# -g Enable debugging
# -Wall Enable verbose warnings
# -std=c99 Use the 99 version of C, compatible with Raylib
CFLAGS := -std=c99 -g -Wall -fno-stack-protector
DONOTLINK := -c

INC := $(RAYLIB_INC_DIR) $(INC_DIR)
LFLAGS := -L$(RAYLIB_LFLAGS)
LIBS := $(RAYLIB_LIBS)

DOCUMENTATION_GENERATOR := doxygen
BROWSER = google-chrome
PATH_TO_DOCS = docs/html/index.html

# default: when only "make" is typed, compile and run the main program
default: main

# compile and then run
main: compile run

# builds the object files
compile: $(OBJS)
	$(CC) $^ -o $(TARGET) $(CFLAGS) $(INC) $(LFLAGS) $(LIBS)

# rule for turning sources into objects
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

# executes the executable
run:
	$(TARGET)

# removes all objects from build, also removes the executable
clean:
	$(RM) $(BUILD_DIR)/*.o $(TARGET)

# build and open the documentation
docs:
	$(DOCUMENTATION_GENERATOR)
	$(BROWSER) $(PATH_TO_DOCS)

valgrind:
	valgrind --leak-check=yes --log-file="val.txt" $(TARGET)
