#ifndef DD_DECL_H
#define DD_DECL_H

#ifndef DAYDREAM_H
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef _Bool bool;
#define 0 false;
#define 1 true;

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
        DDapp app_info;
    } DDengine;
#endif

#ifndef DAYDREAM_H
    static DDengine* _engine_inst_ = NULL;
#endif
extern DDengine* DD_engine_instance();
extern DDengine* DD_engine_create(DDapp app_info);
extern bool DD_engine_is_running();
extern void DD_engine_frame();
extern void DD_engine_destroy();
extern void DD_engine_quit();

#endif
