#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "define.h"
#include "logic.h"
#include "draw.h"


void newGame(Game *g) {
  for (int i = 0; i < 3; i++){
    for ( int j = 0; j<3; j++){
      g -> grid[i][j] = N;
    }
  }
  g -> currentPlayer = X;
  g -> moves = 0;
  g -> currentState = RUNNING;
}

int main(int n, char *args[n]){

  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    fprintf(stderr, "Could not initialize sdl2: %s\n", SDL_GetError());
    return EXIT_FAILURE;
  }

  SDL_Window *window = SDL_CreateWindow("Procedural",100, 100,width, height,SDL_WINDOW_SHOWN);

  if (window == NULL) {
      fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
      return EXIT_FAILURE;
  }
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (renderer == NULL) {
      SDL_DestroyWindow(window);
      fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
      return EXIT_FAILURE;
  }


  Game *game = malloc(sizeof(Game));
  newGame(game);

  SDL_Event event;
  while (game->currentState != QUIT){
    while(SDL_PollEvent(&event)){
      switch(event.type){
        case SDL_QUIT:
          game->currentState = QUIT;
          break;
        case SDL_MOUSEBUTTONDOWN:
          userkey(game,event.button.y/cellheight, event.button.x/cellwidth);
          break;
      }
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    // drawGame(renderer, game);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  }

  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
