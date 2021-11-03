#include "daydream.h"

DDtexture* texture;
DDshader* shader; 
DDsprite* sprite;

void init()
{
    texture = DD_texture_create("sprite.png");
    shader = DD_shader_create("shader.dds");
    sprite = DD_sprite_create(DD_vec2f(500, 500), DD_vec2f(100, 100), DD_vec4f(255, 255, 0, 255), texture, shader);
}

void update()
{
    DD_clear(dd_vec4f(0, 0, 0, 255));
    DD_draw_sprite(sprite);
    DD_draw_sprite_warped();
    DD_draw_sprite_tinted();
}

void shutdown()
{
    DD_texture_free(texture);
    DD_shader_free(shader);
    DD_sprite_free(sprite);
}

dd_app_t DD_main(int32_t argc, char** argv)
{
    return (dd_app_t)
    {
        w_width = 800,
        w_height = 800,
        w_title = "Program",
        w_fullscreen = false,
        w_framerate = 60.f,

        a_init = init,
        a_update = update,
        a_shutdown = shutdown,
    };
}
