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

void opCode(int n, int op[]){
  op[0] = (n>>6);
  op[1] = n & 0x3F;
  if (op[1] > 31){
    op[1] = op[1] - 64;
  }
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


void drawY(state *s, display *d, int n){
  s->cy = s->cy+n;
  s->py = s->cy;
  s->px = s->cx;
  if (s->pen == true){
    line(d, s->px, s->py, s->cx, s->cy);
  }
}

void delay(display *d){
  pause(d, 10);
  
}



void update(){
  if (op[0] == DX) changeX(s, d, op[1]);
  if (op[0] == DY) drawY(s, d, op[1]);

}

void initialise(int n, display *d, state *s){

}


void readFile(display *d, char inputfile[], state *s){
  FILE *in = fopen(inputfile, "rb");
  unsigned int n = fgetc(in);
  while (! feof(in)) {
    initialise(n, d, s);
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

}
