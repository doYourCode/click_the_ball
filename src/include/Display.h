#pragma once

#define GLEW_STATIC

#include <stdio.h>
#include <stdint.h>
#include <assert.h>

#include "../include/GL/glew.h"
#include "../include/SDL.h"

#include "Defines.h"


struct Display
{
	int width;
	int height;
	char* title;

	SDL_Window* window;
	SDL_GLContext context;

	Color bg_color;
};

typedef struct Display Display;

void CreateDisplay(Display* display, int width, int height, const char* title);

void DeleteDisplay(Display* display);

void ShowDisplay(Display* display);

void SetClearColor(Display* display, float r, float g, float b, float a);
