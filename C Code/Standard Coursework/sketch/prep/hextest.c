#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
  unsigned char b[10];
  FILE *in = fopen("lines.sketch", "rb");
  fread(b,sizeof(b),1,in); // read 10 bytes to our buffer
  for(int i = 0; i<10; i++){
    printf("%u\n", b[i]);
  }
  return 0;
}
