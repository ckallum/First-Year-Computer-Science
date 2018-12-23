#ifndef DRAW_H_
#define DRAW_H_
#include <SDL2/SDL.h>

//Header file so the drawGame function in draw.c can be called from main
void drawGame(SDL_Renderer *renderer, const Game *game);

#endif
