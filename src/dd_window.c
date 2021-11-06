#include "dd_decl.h"

GLFWwindow* DD_window_create(DDapp app_info)
{
    if(!glfwInit())
        return NULL;

    GLFWwindow* window = glfwCreateWindow(app_info.w_width, app_info.w_height, app_info.w_title, NULL, NULL);
    if(!window)
    {
        glfwTerminate();
        return NULL;
    }

    glfwMakeContextCurrent(window);

    return window;
}

int32_t DD_get_width()
{
    return 0;
}

int32_t DD_get_height()
{
    return 0;
}

char* DD_get_title()
{
    return NULL;
}

void DD_set_width()
{
}

void DD_set_height()
{
}

void DD_set_title()
{
}

void DD_clear_color(float r, float g, float b, float a)
{
    glClearColor(r, g, b, a);
}
