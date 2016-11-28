CC=gcc
TARGET_DIR=build
OBJECTS_DIR=$(TARGET_DIR)/obj
LIBS_DIR=libs
EXECUTABLE=$(TARGET_DIR)/bin/main

SOURCES=$(wildcard *.c)
OBJECTS=$(addprefix $(OBJECTS_DIR)/, $(notdir $(SOURCES:.c=.o)))

CFLAGS+=-I./ -Ilibs/ -g
LDFLAGS=-L$(LIBS_DIR) -llist

all: build_dir $(EXECUTABLE)

$(OBJECTS_DIR)/%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) -o $@ $^ $(LDFLAGS)
	
clean:
	find build -name '*.o' | xargs rm

build_dir:
	mkdir -p build
	mkdir -p build/bin
	mkdir -p build/libs
	mkdir -p build/obj
	
.PHONY: all clean clean_all build_dir

