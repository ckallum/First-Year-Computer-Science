#ifndef DEF_H_
#define DEF_H_

#define gridwidth 640
#define gridheight 480
#define cellwidth (gridwidth/3)
#define cellheight (gridheight/3)


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
