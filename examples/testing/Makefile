CC = gcc

INCLUDES = -I..\..\src -I$(glfw_inc) -I$(glew_inc)
LIBRARIES = -L..\.. -L$(glfw_lib) -L$(glew_lib)

glfw = ..\..\externals\glfw
glfw_inc = $(glfw)\include
glfw_lib = $(glfw)\lib64

glew = ..\..\externals\glew
glew_inc = $(glew)\include
glew_lib = $(glew)\lib

CFLAGS = -Wall -ggdb -O3 $(INCLUDES)
LDFLAGS = $(LIBRARIES) -ldaydream -lglfw3 -lopengl32 -lgdi32 -lglew32

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
