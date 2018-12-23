#include "define.h"
#include "logic.h"
#include <stdbool.h>

//Checks if a row or column is filled with the same element
player line(player p0, player p1, player p2) {
  if (p0 == p1 && p1==p2 && p0 == X) return X;
  if (p0 == p1 && p1 == p2 && p0 == O) return O;
  return N;
}

// Check whether a player has won, and return the winning player.
player win(Game *g) {
  for (int i = 0; i < 3; i++){//Iterating through each row and column

    char oxWin = line(g -> grid[i][0], g -> grid[i][1], g -> grid[i][2]);
    if (oxWin!= N) return oxWin;
  }
  for (int j = 0; j < 3; j++){
    char oxWin = line(g -> grid[0][j], g -> grid[1][j], g -> grid[2][j]);
    if (oxWin!= N) return oxWin;

  }
  //Diagonal cases
  if (g -> grid [0][0] == g-> grid [1][1] && g -> grid [1][1] == g -> grid [2][2] && g -> grid[0][0]==X) return X;
  if (g -> grid [0][0] == g-> grid [1][1] && g -> grid [1][1] == g -> grid [2][2] && g -> grid[0][0]==O) return O;
  if (g -> grid [0][2] == g-> grid [1][1] && g -> grid [1][1] == g -> grid [2][0] && g -> grid[0][2]==X) return X;
  if (g -> grid [0][2] == g-> grid [1][1] && g -> grid [1][1] == g -> grid [2][0] && g -> grid[0][2]==O) return O;
    return N;
}

//Determines if the game is a draw
bool draw(Game *g) {
  if (g -> moves == 9) return true;
    return false;
}

//Changes the state of the game depending on the result.
void changeState(Game*g){
  if (win(g) == X){
    g->currentState = XWIN;
  }
  else if (win(g) == O){
    g->currentState = OWIN;
  }
  else if (draw(g) == true){
    g->currentState = DRAW;
  }
}

//Switches player
void switchplayer(Game *g){
  if(g->currentPlayer == X){
    g->currentPlayer = O;
  }
  else g->currentPlayer = X;
}

//Resets the game and prints a message depending on the result.
void reset(Game *g, SDL_Window *window){
  char result[1024];
  char *winner;
  if (g->currentState == XWIN) winner = "Player X Wins!";
  else if (g->currentState == OWIN) winner = "Player O Wins!";
  else winner = "Draw!";
  SDL_snprintf(result, sizeof(result), "%s", winner);
  SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Tic Tac Toe result", result, window);
  for (int i = 0 ;i < 3 ;i++){//Setting all elements in grid to N
    for (int j = 0 ; j< 3; j++){
      g->grid[i][j] = N;
    }
  }
  g->moves = 0;
  g->currentState = RUNNING;//Sets currentState back to running, resets game
}

//Adds an element to the grid if the cell has nothing in it. Then switches player and checks if the state needs to be changed
void addToGrid(Game *g, int row, int column){
  if(g->grid[row][column] == N){
    g->grid[row][column] = g->currentPlayer;
    g->moves++;
    switchplayer(g);
    changeState(g);
  }
}

//Signifies a key has been pressed. Calls reset if the game is over.
void userKey(Game *g, int row, int column, SDL_Window *window){
  if(g->currentState == RUNNING){
    addToGrid(g, row, column);
  }
  else reset(g, window);
}
