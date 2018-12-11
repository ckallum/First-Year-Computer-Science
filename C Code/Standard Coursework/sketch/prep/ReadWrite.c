#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define max 100

void input();
char *upper_string();

void input(char filein[], char fileout[]){
  char line[max];
  FILE *in = fopen(filein, "r");
  FILE *out = fopen(fileout, "w");
  if (in == NULL || out == NULL) {
        fprintf(stderr, "cannot open this.txt\n");
        exit(0);
  }
  fgets(line, max, in);
  while (!feof(in)) {
    fprintf(out, upper_string(line));
    fgets(line, max, in);
  }
  fclose(in);
  fclose(out);
}


char *upper_string(char s[]) {
   int c = 0;

   while (s[c] != '\0') {
      if (s[c] >= 'a' && s[c] <= 'z') {
         s[c] = s[c] - 32;
      }
      c++;
   }
   return s;
}

int main(int n, char *args[n]){
  setbuf(stdout, NULL);
  if (n==1){
    printf("You dumb\n");
  }
  else{
    input(args[1], args[2]);
  }
  return 0;
}
