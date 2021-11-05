#ifndef DAYDREAM_H
#define DAYDREAM_H

#include "dd_decl.h"

#ifndef DD_NO_HIJACK_MAIN
int main(int32_t argc, char** argv)
{
    DDengine* instance = DD_engine_create(DD_main(argc, argv));
    if(instance == NULL)
        return -1;
    while(DD_engine_is_running())
    {
        DD_engine_frame();
    }
    free(instance);
}
#endif

#endif
