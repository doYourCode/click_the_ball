#include "../vendor/include/Inih.h"

#include "../src/include/App.h"

#include "../src/include/Globals.h"


void CreateApp(App* app, const char* file_name)
{
    AppCfg config;

    if (ini_parse(file_name, handler, &config) < 0) {
        printf("Couldn't load %s'\n", file_name);
        return;
    }
    printf("Config loaded from '%s': App version = %s\n", file_name, config.version);

    CreateDisplay(&app->display, config.width, config.height, config.title);
    SetClearColor(&app->display, config.Bg_r, config.Bg_g, config.Bg_b, config.Bg_a);

    CreateViewport(&app->viewport, 0, 0, config.width, config.height);

    CreateTextRenderer(&app->text_renderer, &app->viewport);
}

void Run(App* app)
{
    app->quit = FALSE;

    while (!app->quit)
    {
        while (SDL_PollEvent(&app->_event) != 0)
        {
            if (app->_event.type == SDL_MOUSEMOTION)
            {
                mouse_x = app->_event.motion.x;
                mouse_y = app->_event.motion.y;
            }

            if (app->_event.type == SDL_QUIT)
            {
                app->quit = TRUE;
            }

            switch (app->_event.key.keysym.sym)
            {
            case SDLK_ESCAPE: app->quit = TRUE; break;
            }
        }

        UseViewport(&app->viewport);

        glClearColor(app->display.bg_color.r, app->display.bg_color.g, app->display.bg_color.b, app->display.bg_color.a);
        glClear(GL_COLOR_BUFFER_BIT);

        DrawTextRenderer(&app->text_renderer);

        ShowDisplay(&app->display);
    }

    DeleteApp(app);
}

void DeleteApp(App* app)
{
    DeleteDisplay(&app->display);

    DeleteTextRenderer(&app->text_renderer);
}

static int handler(void* user, const char* section, const char* name, const char* value)
{
    AppCfg* pconfig = (AppCfg*)user;

    #define MATCH(s, n) strcmp(section, s) == 0 && strcmp(name, n) == 0

    if (MATCH("Application", "Version")) { pconfig->version = _strdup(value); }
    else if (MATCH("Application", "Title")) { pconfig->title = _strdup(value); }
    else if (MATCH("Application", "Width")) { pconfig->width = atoi(value); }
    else if (MATCH("Application", "Height")) { pconfig->height = atoi(value); }
    else if (MATCH("Application", "Bg_r")) { pconfig->Bg_r = strtof(value, NULL); }
    else if (MATCH("Application", "Bg_g")) { pconfig->Bg_g = strtof(value, NULL); }
    else if (MATCH("Application", "Bg_b")) { pconfig->Bg_b = strtof(value, NULL); }
    else if (MATCH("Application", "Bg_a")) { pconfig->Bg_a = strtof(value, NULL); }
    else if (MATCH("Application", "Fg_r")) { pconfig->Fg_r = strtof(value, NULL); }
    else if (MATCH("Application", "Fg_g")) { pconfig->Fg_g = strtof(value, NULL); }
    else if (MATCH("Application", "Fg_b")) { pconfig->Fg_b = strtof(value, NULL); }
    else if (MATCH("Application", "Fg_a")) { pconfig->Fg_a = strtof(value, NULL); }
    else { return 0; } /* unknown section/name, error */
    return 1;
}
