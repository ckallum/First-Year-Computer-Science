#include "define.h"
#include "draw.h"
#include <SDL2/SDL.h>

const SDL_Color GridColour = {.r = 255, .g =255, .b =255};
const SDL_Color XColour = {.r = 50, .g =255, .b =255};
const SDL_Color OColour = {.r = 50, .g =100, .b =255};
const SDL_Color DrawColour = {.r = 100, .g =100, .b =100};

void drawGrid(SDL_Renderer *renderer, const SDL_Color *colour){
  SDL_SetRenderDrawColor(renderer, colour->r, colour->g, colour->b,255);
  for (int i = 1; i < 3; i++){
      SDL_RenderDrawLine(renderer, i*cellwidth, 0, i*cellwidth, gridheight);
      SDL_RenderDrawLine(renderer, 0, i*cellheight, gridwidth, i*cellheight);
  }
}

void drawX(SDL_Renderer *renderer, int row, int column, const SDL_Color *colour){
  SDL_SetRenderDrawColor(renderer, colour->r, colour->g,colour->b, 255);
  SDL_RenderDrawLine(renderer, row*cellwidth, column*cellwidth, row*cellwidth*0.75, column*cellwidth *0.75);

}

void drawO(SDL_Renderer *renderer, int row, int column, const SDL_Color *colour){

}

void drawBoard(int n, player board[n][n], SDL_Renderer *renderer, const SDL_Color *xcolour, const SDL_Color *ocolour){
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      switch(board[i][j]){
        case(X):
          drawX(renderer, i, j, xcolour);
          break;
        case(O):
          drawO(renderer, i, j, ocolour);
          break;
    }
    }
  }
}


void drawRunning(int n, SDL_Renderer *renderer, const Game *game){
  drawGrid(renderer, &GridColour);
  player temp[3][3];
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      temp[i][j] = game->grid[i][j];
    }
  }
  drawBoard(n, temp, renderer, &XColour, &OColour);
}

void drawGameOver(int n, SDL_Renderer *renderer, const Game *game, const SDL_Color *colour){
  drawGrid(renderer, colour);
  player temp[3][3];
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      temp[i][j] = game->grid[i][j];
    }
  }
  drawBoard(n, temp, renderer, colour, colour);
}

void drawGame(SDL_Renderer *renderer, const Game *game){
  int n = 3;
  switch(game->currentState){
    case RUNNING:
      drawRunning(n, renderer, game);
      break;
    case XWIN:
      drawGameOver(n, renderer, game, &XColour);
      break;
    case OWIN:
      drawGameOver(n, renderer, game, &OColour);
      break;
    case DRAW:
      drawGameOver(n, renderer, game, &DrawColour);
      break;
  }
}
