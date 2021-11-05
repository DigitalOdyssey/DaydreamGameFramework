CC = gcc

INCLUDES = -I..\..\src
LIBRARIES = -L..\..

CFLAGS = -Wall -ggdb -O3 $(INCLUDES)
LDFLAGS = $(LIBRARIES) -ldaydream

TARGET = test.exe

c_files = $(wildcard src/*.c) $(wildcard src/*/*.c)
objects = $(addprefix bin/, $(notdir $(c_files:.c=.o)))

all: $(TARGET)

$(TARGET): $(objects)
	$(CC) -o $@ $^ $(LDFLAGS)

bin/%.o: src/%.c | bin
	$(CC) $< -c $(CFLAGS) -o $@

bin/%.o: src/*/%.c | bin
	$(CC) $< -c $(CFLAGS) -o $@
