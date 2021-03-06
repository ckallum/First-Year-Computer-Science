#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void hex();

void convert(char input[]){
  // char str[3];
  FILE *in = fopen(input, "rb");
  unsigned char b = fgetc(in);
  while (! feof(in)) {
    // hex(b, str);
    printf("%02x ",b);
    b = fgetc(in);
  }
  printf("\n");
  fclose(in);
}

// Convert an int into a hex string of 8 hex digits.
void hex(int n, char s[8]) {
  char hexCheck[]= {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','\0'};
  s[7] = '\0';
  for (int i = 0; i < 7 ; i++){
    int j = (n >> (4*(6-i)) & 0xF);
    s[i] = hexCheck[j];
  }
}

int main(int n, char *args[n]){
  setbuf(stdout, NULL);
  if (n==1){
    printf("You dumb\n");
  }
  else{
    convert(args[1]);
  }
  return 0;
}
