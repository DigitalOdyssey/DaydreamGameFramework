#include "dd_decl.h"

DDengine* DD_engine_instance()
{
    return _engine_inst_;
}

DDengine* DD_engine_create(DDapp app_info)
{
    if(DD_engine_instance() != NULL)
        return _engine_instance_;

    DDengine* engine = malloc(sizeof(DDengine));
    memset(engine, 0, sizeof(DDengine));

    engine->app_info = app_info;
    engine->is_running = true;
    _engine_instance_ = engine;

    engine->app_info.init();
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
    DD_engine_instance()->app_info.update();
}

void DD_engine_destroy()
{
}

void DD_engine_quit()
{
    DD_engine_instance()->is_running = false;
    DD_engine_destroy();
}
