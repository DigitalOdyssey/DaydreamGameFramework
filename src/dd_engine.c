#include "dd_decl.h"

DDengine* DD_engine_instance()
{
    return _engine_inst;
}

DDengine* DD_engine_create(DDapp app_info)
{
    if(DD_engine_instance() != NULL)
        return DD_engine_instance();

    DDengine* engine = malloc(sizeof(DDengine));
    memset(engine, 0, sizeof(DDengine));

    //engine->window = NULL;
    engine->is_running = true;
    engine->w_width = app_info.w_width;
    engine->w_height = app_info.w_height;
    engine->w_title = app_info.w_title;
    engine->w_framerate = app_info.w_framerate;
    engine->init = app_info.init;
    engine->update = app_info.update;
    engine->shutdown = app_info.shutdown;
    _engine_inst = engine;

    engine->init();
    return engine;
}

bool DD_engine_is_running()
{
    if(DD_engine_instance() == NULL)
        return false;

    return DD_engine_instance()->is_running;
}

void DD_engine_frame()
{
    DD_engine_instance()->update();
}

void DD_engine_destroy()
{
}

void DD_engine_quit()
{
    DD_engine_instance()->shutdown();
    DD_engine_instance()->is_running = false;
    DD_engine_destroy();
}
