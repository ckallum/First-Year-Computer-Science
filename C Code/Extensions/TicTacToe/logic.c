#include "define.h"
#include "logic.h"
#include <stdbool.h>

player line(player p0, player p1, player p2) {
  if (p0 == p1 && p1==p2 && p0 == X) return X;
  if (p0 == p1 && p1 == p2 && p0 == O) return O;
  return N;
}

// Check whether a player has won, and return the winning player.
player win(Game *g) {
  for (int i = 0; i < 3; i++){

    char oxWin = line(g -> grid[i][0], g -> grid[i][1], g -> grid[i][2]);
    if (oxWin!= N) return oxWin;
  }
  for (int j = 0; j < 3; j++){
    char oxWin = line(g -> grid[0][j], g -> grid[1][j], g -> grid[2][j]);
    if (oxWin!= N) return oxWin;

  }
  if (g -> grid [0][0] == g-> grid [1][1] && g -> grid [1][1] == g -> grid [2][2] && g -> grid[0][0]==X) return X;
  if (g -> grid [0][0] == g-> grid [1][1] && g -> grid [1][1] == g -> grid [2][2] && g -> grid[0][0]==O) return O;
  if (g -> grid [0][2] == g-> grid [1][1] && g -> grid [1][1] == g -> grid [2][0] && g -> grid[0][2]==X) return X;
  if (g -> grid [0][2] == g-> grid [1][1] && g -> grid [1][1] == g -> grid [2][0] && g -> grid[0][2]==O) return O;
    return N;
}

bool draw(Game *g) {
  if (g -> moves == 9) return true;
    return false;
}

void changeState(Game*g){
  if (win(g) == X){
    g->currentState = XWIN;
  }
  else if (win(g) == O){
    g->currentState = OWIN;
  }
  else if (win(g) == N && draw(g) == true){
    g->currentState = DRAW;
  }
}

void switchplayer(Game *g){
  if(g->currentPlayer == X){
    g->currentPlayer = O;
  }
  else g->currentPlayer = X;
}

void reset(Game *g){
  for (int i = 0 ;i < 3 ;i++){
    for (int j = 0 ; j< 3; j++){
      g->grid[i][j] = N;
    }
  }
}

void addToGrid(Game *g, int row, int column){
  if(g->grid[row][column] == N){
    g->grid[row][column] = g->currentPlayer;
    switchplayer(g);
    changeState(g);
  }
}

void userkey(Game *g, int row, int column){
  if(g->currentState == RUNNING){
    addToGrid(g, row, column);
  }
  else reset(g);
}
