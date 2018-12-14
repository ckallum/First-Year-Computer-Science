#include <stdio.h>
#include <stdlib.h>
#include "display.h"
#include <ctype.h>
#include <stdbool.h>

struct state {
  int x;
  int y;
  int dx;
  int dy;
  int dt;
  int operand;
  bool pen;
  display *display;
};
typedef struct state state;
typedef unsigned char byte;

state *newState(display *disp){
  state *s = malloc(sizeof(state));
  s->x = 0;
  s->y = 0;
  s->dx = 0;
  s->dy = 0;
  s->dt = 0;
  s->operand = 0;
  s->pen = false;
  s->display = disp;
  return s;
}

int getOP(byte b){
  return (b>>6);
}

int getOPER(byte b){
  int temp;
  temp = b & 0x3F;
  return temp;
}

void draw(state *s){
    s->dy = s->operand;
    if (s->pen == true){
      line(s->display, s->x, s->y, s->x + s->dx, s->y + s->dy);
    }
    s->x = s->x + s->dx;
    s->y = s->y + s->dy;
    s->dx = 0;
    s->dy = 0;
    s->operand = 0;
}

void doSwitch(int operand, state*s){
  switch (operand){
    case 0:
      if (s->pen == false) s->pen = true;
      else s->pen = false;
      break;
    case 1:
      s->dt = s->operand;
      pause(s->display, s->dt);
    case 2:
      clear(s->display);
      break;
    case 3:
      key(s->display);
      break;
    case 4:
      colour(s->display, operand);
      break;
  }
}

void extendOPER(int operand, state *s){
  s->operand = (s->operand<<6) | operand;
}

void opSwitch(int opcode, int operand, state *s){
  switch(opcode){
    case 0:
      extendOPER(operand, s);
      s->dx = s->operand;
      s->operand = 0;
      break;
    case 1:
      extendOPER(operand, s);
      draw(s);
      break;
    case 2:
      extendOPER(operand, s);
      break;
  }
  if (opcode > 2){
    doSwitch(operand, s);
  }
}

void initiate(byte b, state *s){
  int opcode = getOP(b);
  int operand = getOPER(b);
  if (operand > 31 && opcode < 2) operand = operand - 64;
  printf("opcode = %d ,operand = %d  \n",opcode, operand);
  opSwitch(opcode, operand, s);
}

void run(char filename[], display *d){
  state *s = newState(d);
  FILE *in = fopen(filename, "rb");
  byte b = fgetc(in);
  while (!feof(in)){
    printf("%02x  ", b);
    initiate(b,s);
    b = fgetc(in);
  }
  printf("\n");
  fclose(in);
}


int main(int n, char *args[n]){
  if(n != 2){
    fprintf(stdout, "Use ./sketch filename\n");
    exit(1);
  }
  display *d = newDisplay(args[1], 200, 200);
  run(args[1], d);
  end(d);
  return 0;
}
