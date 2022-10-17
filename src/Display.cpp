#define GLT_IMPLEMENTATION
#include "../vendor/include/glText.h"

#include "../src/include/Display.h"


void CreateDisplay(Display* display, int width, int height, const char* title)
{

	SDL_InitSubSystem(SDL_INIT_VIDEO);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);;

	display->width = width;
	display->height = height;

	display->window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_OPENGL);
	display->context = SDL_GL_CreateContext(display->window);
	SDL_GL_MakeCurrent(display->window, display->context);

	glewInit();
}

void DeleteDisplay(Display* display)
{
	SDL_GL_DeleteContext(display->context);
	SDL_DestroyWindow(display->window);
}

void ShowDisplay(Display* display)
{
    SDL_GL_SwapWindow(display->window);
}

void SetClearColor(Display* display, float r, float g, float b, float a)
{
	display->bg_color.r = r;
	display->bg_color.g = g;
	display->bg_color.b = b;
	display->bg_color.a = a;
}