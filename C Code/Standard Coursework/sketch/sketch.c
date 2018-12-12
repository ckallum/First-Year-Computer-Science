#include <stdio.h>
#include <stdlib.h>
#include "display.h"
#include <ctype.h>
#include <stdbool.h>
#define DX 0
#define DY 1
#define PEN 3

struct state {
  int px, py, cx, cy;
  bool pen;
};
typedef struct state state;

int opcode(int n, int op){
  op = (n>>6);
  return op;
}

int operand(int n, int op){
  op = n & 0x3F;
  if (op > 31){
    op = op - 64;
  }
  return op;
}

state *newState(){
  state *s = malloc(sizeof(state));
  s->px = 0;
  s->py = 0;
  s->cx = 0;
  s->cy = 0;
  s->pen = false;
  return s;
}


void dy(display *d, state *s, int n){
  s->py = s->cy;
  s->cy = s->cy+n;
  if (s->pen == true){
    line(d, s->px, s->py, s->cx, s->cy);
  }
}

void dx(display *d,state *s, int n){
  pause(d, 10);
  s->px = s->cx;
  s->cx = s->cx+n;
}




void update(display *d, int n, state *s){
  int op = 0;
  int opc = opcode(n, op);
  int oper = operand(n, op);
  // printf("%d\n",opcode);
  // printf("%d\n",oper);
  if (opc == DX) dx(d, s, oper);
  if (opc == DY) dy(d, s, oper);
  if (opc == PEN && s->pen ==false) s->pen = true;
  else s->pen = false;

}

void initialise(display *d, int n, state *s){
  update(d, n, s);
}


void readFile(display *d, char inputfile[], state *s){
  FILE *in = fopen(inputfile, "rb");
  unsigned int n = fgetc(in);
  while (! feof(in)) {
    initialise(d, n, s);
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
    readFile(d, args[1], s);
    end(d);
    free(s);
    return 0;
}
