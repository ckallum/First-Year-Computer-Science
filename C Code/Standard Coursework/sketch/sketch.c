#include <stdio.h>
#include <stdlib.h>
#include "display.h"
#include <ctype.h>
#include <stdbool.h>

struct state {
  int x, y, dx, dy;
  int operand;
  int PRCount;
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
  s->x = 0;
  s->y = 0;
  s->dx = 0;
  s->dy = 0;
  s->operand = 0;
  s->DT = 0;
  s->PRCount = 0;
  s->pen = false;
  s->init = false;
  return s;
}


void dy(state *s, int n){
  s->dy = s->dy+operand(n);
  if (s->pen == true){
    line(s->display, s->x, s->y, s->dx, s->dy);
  }
  s->x = s->dx;
  s->y = s->dy;
  s->PRCount = 0;

}

void dx(state *s, int n){
  s->dx = s->dx+operand(n);
  s->PRCount = 0;
}

void updateOp(state *s, int n){
  s->operand = (s->operand << 6) || operand(n);
  s->PRCount++;
}

void findDO(state *s){
  switch ((s->operand & 0x3F)+3);
}




void getOp(int n, state *s){
  int opc = opcode(n);
  printf("%d, %d\n", opc, operand(n));
  switch (opc) {
    case 0:
      dx(s, n);
      break;
    case 1:
      dy(s, n);
      break;
    case 2:
      updateOp(s, n);
    case 3:
      if (s->pen == false) s->pen = true;
      else s->pen = false;
      break;
  }
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
