#ifndef LOGIC_H_
#define LOGIC_H_
#include <SDL2/SDL.h>
//Header file to allow call of userKey function in logic.c from main 
void userKey(Game *game, int row, int column, SDL_Window *window);

#endif  // LOGIC_H_
