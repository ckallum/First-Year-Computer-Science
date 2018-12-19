#ifndef DEF_H_
#define DEF_H_

#define width 640
#define height 480
#define cellwidth (width/3)
#define cellheight (height/3)


enum player { X, O, N };
typedef enum player player;

enum state{RUNNING, XWIN, OWIN, DRAW, QUIT};
typedef enum state state;

struct game{
  int moves;
  player grid[3][3];
  player currentPlayer;
  state currentState;
};
typedef struct game Game;

#endif
