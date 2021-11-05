CC = gcc
AR = ar

INCLUDES = -I$(glfw_inc) -I$(glew_inc)
LIBRARIES = -L$(glfw_lib) -$(glew_lib)

glfw = externals\glfw
glfw_inc = $(glfw)\include
glfw_lib = $(glfw)\lib64

glew = externals\glew
glew_inc = $(glew)\include
glew_lib = $(glew)\lib

CFLAGS = -Wall -ggdb -O3 $(INCLUDES)
LDFLAGS = $(LIBRARIES) -lglfw3 -opengl32 -lgdi32 -lglew32

TARGET = libdaydream.a
c_files = $(wildcard src/*.c) $(wildcard src/*/*.c)
objects = $(addprefix bin/, $(notdir $(c_files:.c=.o)))

all: $(TARGET)

$(TARGET): $(objects)
	$(AR) rcs $@ $(objects)

bin/%.o: src/%.c | bin
	$(CC) $< -c $(CFLAGS) -o $@

bin/%.o: src/*/%.c | bin
	$(CC) $< -c $(CFLAGS) -o $@
