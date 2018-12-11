#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

int main(int n, char *args[n]){
  int s = atol(args[1]);
  int first = 0;
  int second = 1;
  int next =0;

  for (int c = 0 ; c <= s; c++){
    if (c<=1) next = c;
    else{
      next = first + second;
      first = second;
      second = next;
    }
    printf ("%d \n", next);
  }
}
