/* Example program: say Hi. */
#include <stdio.h>
int square (int n){
  return n*n;
}
int main (){
    int n = square(50000);
    printf("42 squared is %d\n", n);
    return 0;
}
