#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "define.h"
#include "logic.h"
#include "draw.h"


Game *newGame() {
  Game *temp = malloc(sizeof(Game));
  for (int i = 0; i < 3; i++){
    for ( int j = 0; j<3; j++){
      temp -> grid[i][j] = N;
    }
  }
  temp -> currentPlayer = X;
  temp -> moves = 0;
  temp -> currentState = RUNNING;
  return temp;
}

static void fail() {
    fprintf(stderr, "Error: %s\n", SDL_GetError());
    SDL_Quit();
    exit(1);
}

// Check return values from SDL functions (Integer and Pointer versions).  These
// make error handling less intrusive.
static int I(int n) { if (n < 0) fail(); return n; }
static void *P(void *p) { if (p == NULL) fail(); return p; }

int main(int n, char *args[n]){

  I(SDL_Init(SDL_INIT_VIDEO));

  SDL_Window *window = P(SDL_CreateWindow("Procedural",100, 100,gridwidth, gridheight,SDL_WINDOW_SHOWN));

  SDL_Renderer *renderer = P(SDL_CreateRenderer(window, -1,0));

  Game *game = newGame();
  SDL_Event event_structure;
  SDL_Event *event = &event_structure;

  while (game->currentState != QUIT){
    while(SDL_PollEvent(event)){
      switch(event->type){
        case SDL_QUIT:
          game->currentState = QUIT;
          break;
        case SDL_MOUSEBUTTONDOWN:
          userKey(game,event->button.y/cellheight, event->button.x/cellwidth);
          break;
        default:{};
      }
    }
    I(SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255));
    I(SDL_RenderClear(renderer));
    drawGame(renderer, game, window);
    SDL_RenderPresent(renderer);

  }

  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
