#include "define.h"
#include "draw.h"
#include <SDL2/SDL.h>

const SDL_Color GridColour = {.r = 255, .g =255, .b =255};
const SDL_Color XColour = {.r = 255, .g =255, .b =255};
const SDL_Color OColour = {.r = 50, .g =100, .b =255};
const SDL_Color DrawColour = {.r = 100, .g =100, .b =100};

void drawGrid(SDL_Renderer *renderer, const SDL_Color *colour, SDL_Window *window){
  SDL_SetRenderDrawColor(renderer, colour->r, colour->g, colour->b,255);
  for (int i = 1; i < 3; i++){
      SDL_RenderDrawLine(renderer, i*cellwidth, 0, i*cellwidth, gridheight);
      // SDL_UpdateWindowSurface(window);
      SDL_RenderDrawLine(renderer, 0, i*cellheight, gridwidth, i*cellheight);
      // SDL_UpdateWindowSurface(window);
  }
}

void drawX(){

}

void drawO(){

}

void drawBoard(SDL_Renderer *render, const int *board, const SDL_Color *xcolor, const SDL_Color *ocolor){

}

void drawRunning(SDL_Renderer *renderer, const Game *game, SDL_Window *window){
  drawGrid(renderer, &GridColour, window);
}

void drawGameOver(SDL_Renderer *renderer, const Game *game, const SDL_Color *colour){

}

void drawGame(SDL_Renderer *renderer, const Game *game, SDL_Window *window){
  switch(game->currentState){
    case RUNNING:
      drawRunning(renderer, game, window);
      break;
    case XWIN:
      drawGameOver(renderer, game, &XColour);
      break;
    case OWIN:
      drawGameOver(renderer, game, &OColour);
      break;
    case DRAW:
      drawGameOver(renderer, game, &DrawColour);
      break;
  }
}
