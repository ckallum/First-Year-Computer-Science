#include <stdio.h>
#include <stdlib.h>
#include "display.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>

struct state {
  int x, y, dx, dy;
  long operand;
  int DT;
  display *display;
  bool pen;
  bool init;
};
typedef struct state state;

int opcode(int n){
  return n>>6;
}

int operand(int n){
  long op;
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
  s->x = 0;
  s->y = 0;
  s->dx = 0;
  s->dy = 0;
  s->operand = 0;
  s->DT = 0;
  s->pen = false;
  s->init = false;
  return s;
}


void dy(state *s, int n){
  s->operand = (s->operand<<6) | operand(n);
  s->dy = s->dy+s->operand;
  if (s->pen == true){
    line(s->display, s->x, s->y, (s->x + s->dx), s->dy);
  }
  s->x = s->x + s->dx;
  s->dx = 0;
  s->y = s->dy;
  s->operand = 0;

}

void dx(state *s, int n){
  s->operand = (s->operand<<6) | operand(n);
  s->dx = s->operand;
  s->operand = 0;
}

void updateOp(state *s, int n){
  s->operand = (s->operand << 6) | operand(n);
}

void findDO(state *s, int n){
  switch (operand(n)){
    case 0:
      if (s->pen == false) s->pen = true;
      else s->pen = false;
      break;
    case 1:
      if (s->operand != 0) s->DT = s->operand;
      else pause(s->display, s->DT);
      break;s->operand = 0;s->operand = 0;
    case 2:
      clear(s->display);
      break;
    case 3:
      key(s->display);
      break;
    case 4:
      colour(s->display, s->operand);
      break;
  }
}




void getOp(int n, state *s){
  int opc = opcode(n);
  switch (opc) {
    case 0:
      dx(s, n);
      break;
    case 1:
      dy(s, n);
      break;
    case 2:
      updateOp(s, n);
    }
  if (opc >2){
    findDO(s, n);
  }
  printf("operand = %ld, x = %d, y = %d, dx = %d, dy = %d,     %d, %d\n",s->operand, s->x, s->y, s->dx, s->dy, opc, operand(n));
}

void initialise(int n, state *s){
  getOp(n, s);
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
