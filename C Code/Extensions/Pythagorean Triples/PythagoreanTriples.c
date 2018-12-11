/* Print all pythagorean triples upto a specified integer number */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <assert.h>


// Convert a mark string into an integer.  Return -1 if it is not valid.
// The argument n is the length of the string).
int convert(int inputLen, const char pInput[]) {
  bool Inval = false;
  for (int i = 0; i < inputLen; i++){
    if (!isdigit(pInput[i])){
      Inval = true;
    }
  }
  if (Inval == false){
    long converted = atol(pInput);
    if (converted > 2147483647 || converted <= 0) return -1;
    if (pInput[0] == '0' || converted < 2) return -1;
    return converted;
  }
  return -1;
}

// Print's all the pythagorean triple values upto a specified integer.
int pTriple(int pInput) {
  int a = 0;
  int b = 0;
  int j = 2;
  for (int c = 0; c < pInput;){
    for (int i = 1; i < j; ++i){
      a = j * j - i * i;
      b = 2 * j *i;
      c = j * j + i * i;
      if (c > pInput) break;
      printf("%d, %d, %d\n", a, b, c);
    }
    j++;
  }
  return -1;
}


//Tests if the conversion of the input character to integer was successful.
void testConvert() {
  assert(convert(1,"2")==2);
  assert(convert(2,"10")==10);
  assert(convert(3,"100")==100);
  assert(convert(4,"1000")==1000);
  assert(convert(1,"23423452")==23423452);
}

//Tests for invalid inputs
void testValue(){
  assert(convert(1,"0")==-1);
  assert(convert(1,"1")==-1);
  assert(convert(1,"x")==-1);
  assert(convert(2,"-1")==-1);
  assert(convert(3,"4xc")==-1);
  assert(convert(3,"040")==-1);
  assert(convert(2147483648,"2147483648")==-1);
}

//Initiates tests.
void test(){
  testConvert();
  testValue();
  printf("Success\n");
}

//Driver function.
int main(int n, char *args[n]) {
    setbuf(stdout, NULL);
    if (n == 1) test();
    else if (n > 1){
      pTriple(convert(strlen(args[1]), args[1]));
    }
    else {
      return 1;
    }
    return 0;
}
