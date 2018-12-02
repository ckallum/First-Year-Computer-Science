#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

long factorial(int s){
    long facTotal = 1;
    for (int i = 1; i <= s; i++){
      facTotal = facTotal * i;
    }
    return facTotal;
}

int main(int n, char *args[n]){
  int s = atol(args[1]);
  printf("%ld\n", factorial(s));

}
