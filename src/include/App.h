#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Display.h"
#include "TextRenderer.h"
#include "Viewport.h"
#include "Defines.h"


struct App
{
	Display display;
    Viewport viewport;
	TextRenderer text_renderer;

    boolean quit;
    SDL_Event _event;
};
typedef struct App App;

struct AppCfg
{
    const char* version;
    const char* title;
    int width;
    int height;

    float Bg_r;
    float Bg_g;
    float Bg_b;
    float Bg_a;

    float Fg_r;
    float Fg_g;
    float Fg_b;
    float Fg_a;
};
typedef struct AppCfg AppCfg;

void CreateApp(App* app, const char* file_name);

void Run(App* app);

void DeleteApp(App* app);

static int handler(void* user, const char* section, const char* name, const char* value);
