#ifndef LIBRARY_H_
#define LIBRARY_H_

#include<iostream>
#include<SDL.h>
#include<string>
#include<SDL_image.h>
#include "SDL_events.h"

static const int SCREEN_WIDTH = 1200;
static const int SCREEN_HEIGHT = 600;
static const char* WINDOW_TITLE = "Tank_Ranarok";
const int NUM_Threat=3;

static SDL_Window* window;
static SDL_Renderer* renderer;

#endif // BACKGROUND_H_
