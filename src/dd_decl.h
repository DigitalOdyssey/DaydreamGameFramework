#ifndef DD_DECL_H
#define DD_DECL_H

/* INCLUDES */
#ifndef DAYDREAM_H
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* MACROS */
typedef _Bool bool;
#define false 0
#define true 1


/* ENGINE */
typedef struct
{
    uint32_t w_width;
    uint32_t w_height;
    char* w_title;
    bool w_isfullscreen;
    float w_framerate;

    void(*init)();
    void(*update)();
    void(*shutdown)();
} DDapp;

extern DDapp DD_main(int32_t argc, char** argv);

#ifdef DAYDREAM_H
    typedef void DDengine;
#else
    typedef struct
    {
        GLFWwindow* window;
        bool is_running;
        uint32_t w_width;
        uint32_t w_height;
        char* w_title;
        float w_framerate;

        void(*init)();
        void(*update)();
        void(*shutdown)();
    } DDengine;
#endif

#ifndef DAYDREAM_H
static DDengine* _engine_inst = NULL;
#endif
extern DDengine* DD_engine_instance();
extern DDengine* DD_engine_create(DDapp app_info);
extern bool DD_engine_is_running();
extern void DD_engine_frame();
extern void DD_engine_destroy();
extern void DD_engine_quit();

/* window */ // TODO
extern int32_t DD_get_width(); // Gets the width of the window
extern int32_t DD_get_height(); // Gets the height of the window
extern char* DD_get_title(); // Gets the title of the window
extern void DD_set_width(); // Sets the width of the window
extern void DD_set_height(); // Sets the height of the window
extern void DD_set_title(); // Sets the title of the window

// TODO: input

/* graphics */
// TODO: enable/disable auto clearing
#ifndef DAYDREAM_H
GLFWwindow* DD_window_create(DDapp app_info);
#endif
extern void DD_clear_color(float r, float g, float b, float a); // Sets the clear color of the window

#endif
