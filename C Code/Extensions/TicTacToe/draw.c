#include "define.h"
#include "draw.h"
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL.h>

//Preset colours for each element in the window.
const SDL_Color GridColour = {.r = 255, .g =255, .b =255};
const SDL_Color XColour = {.r = 255, .g =0, .b =0};
const SDL_Color OColour = {.r = 50, .g =100, .b =255};
const SDL_Color DrawColour = {.r = 100, .g =100, .b =100};

//Draw the grid, colour depends on current state of the game. eg. White is default, Red if X has won.
void drawGrid(SDL_Renderer *renderer, const SDL_Color *colour){
  SDL_SetRenderDrawColor(renderer, colour->r, colour->g, colour->b,255);
  for (int i = 1; i < 3; i++){
      SDL_RenderDrawLine(renderer, i * cellwidth, 0, i * cellwidth, gridheight);
      SDL_RenderDrawLine(renderer, 0, i*cellheight, gridwidth, i*cellheight);
  }
}

//Draws an X where the user specified in the grid
void drawX(SDL_Renderer *renderer, int row, int column, const SDL_Color *colour){
  float boxsize = cellwidth*0.25;
  float centrex = (cellwidth * 0.5) + (column * cellwidth);
  float centrey = (cellheight *0.5) + (row * cellheight);
  SDL_SetRenderDrawColor(renderer, colour->r, colour->g, colour->b, 255);
  SDL_RenderDrawLine(renderer, centrex - boxsize, centrey-boxsize, centrex + boxsize, centrey + boxsize);
  SDL_RenderDrawLine(renderer, centrex + boxsize, centrey - boxsize, centrex - boxsize, centrey + boxsize);
}

//Draws an O where the user specified in the grid. Uses 2 circles to create the ring.
void drawO(SDL_Renderer *renderer, int row, int column, const SDL_Color *colour){
  float boxsize = cellwidth*0.25;
  float centrex = (cellwidth * 0.5) + (column * cellwidth);
  float centrey = (cellheight *0.5) + (row * cellheight);
  filledCircleRGBA(renderer, centrex, centrey, boxsize+5, colour->r, colour->g, colour->b,255);
  filledCircleRGBA(renderer, centrex, centrey, boxsize-5, 0, 0, 0,255);
}

//Passes through each element in the grid and draws the element in each cell.
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

//This is called when the game is in the running state, i.e. the grid colour and the X and O's remains default colours
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

//This is called when the game is in a game over state, i.e. the colour of all the elements in the window change to the colour of the result. e.g red if X won, grey if draw
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

//Determines what state the game is in and calls functions accordingly with the colours corresponding to each state.
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
