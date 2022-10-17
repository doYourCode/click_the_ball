#pragma once

#include "../src/include/Viewport.h"


struct TextRenderer
{
	Viewport* viewport;
};

typedef struct TextRenderer TextRenderer;

void CreateTextRenderer(TextRenderer* textRenderer, Viewport* viewport);

void DeleteTextRenderer(TextRenderer* textRenderer);

void DrawTextRenderer(TextRenderer* textRenderer);

void SetTextColor(TextRenderer* textRenderer, float r, float g, float b, float a);