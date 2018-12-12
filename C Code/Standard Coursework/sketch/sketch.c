#include <stdio.h>
#include <stdlib.h>
#include "display.h"
#include <ctype.h>
#include <stdbool.h>

struct state {
  int px, py, cx, cy;
  int currentOp;
  int DT;
  display *display;
  bool pen;
  bool init;
};
typedef struct state state;

int opcode(int n){
  return (n>>6);
}

int operand(int n){
  int op;
  op = n & 0x3F;
  if (op > 31){
    op = op - 64;
  }
  return op;
}

int increaseOp(state *s, int n){
  return 0;
}

state *newState(){
  state *s = malloc(sizeof(state));
  s->px = 0;
  s->py = 0;
  s->cx = 0;
  s->cy = 0;
  s->currentOp = 0;
  s->DT = 0;
  s->pen = false;
  s->init = false;
  return s;
}


void dy(state *s, int n){
  s->cy = s->cy+n;
  if (s->pen == true){
    line(s->display, s->px, s->py, s->cx, s->cy);
  }
  s->px = s->cx;
  s->py = s->cy;

}

void dx(state *s, int n){
  s->cx = s->cx+n;
}




void update(int n, state *s){
  int opc = opcode(n);
  int oper = operand(n);
  printf("%d, %d\n", opc, oper);
  if (opc == 2){};
  if (opc == 0) dx(s, oper);
  else if (opc == 1) dy(s, oper);
  else if (opc == 3 && s->pen ==false) s->pen = true;
  else s->pen = false;

}

void initialise(int n, state *s){
  update(n, s);
}


void readFile (char inputfile[], state *s){
  FILE *in = fopen(inputfile, "rb");
  unsigned int n = fgetc(in);
  while (! feof(in)) {
    initialise(n, s);
    n = fgetc(in);
  }
  fclose(in);
}

int main(int n, char *args[n]){
  if (n != 2) {
    fprintf(stdout, "Use ./sketch filename\n");
    exit(1);
  }
    state *s = newState();
    display *d = newDisplay(args[1], 200, 200);
    s->display = d;
    readFile(args[1], s);
    end(d);
    free(s);
    return 0;
}
