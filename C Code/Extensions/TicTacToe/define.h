#ifndef DEF_H_
#define DEF_H_

//Some constants for the grid
#define gridwidth 640
#define gridheight 480
#define cellwidth (gridwidth/3)
#define cellheight (gridheight/3)

//enumerated player class
enum player { X, O, N };
typedef enum player player;

//enumerated state class
enum state{RUNNING, XWIN, OWIN, DRAW, QUIT};
typedef enum state state;

//game structure
struct game{
  int moves;
  player grid[3][3];
  player currentPlayer;
  state currentState;
};
typedef struct game Game;

#endif
