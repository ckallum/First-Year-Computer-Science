#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

main(){
  int r =16;
  int g = 12;
  int b = 9 ;
  int c = (r << 16) | (g << 8) | b;
  printf("%d", c);
}
