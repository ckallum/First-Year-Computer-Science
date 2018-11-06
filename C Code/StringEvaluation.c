/* Trying to find the longest substring of charachters in alphabetical order
in a string*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <assert.h>

// stringCheck a string into an integer.  Return False if it is not valid.
int stringCheck(const char inputStr[]) {
  int n = strlen(inputStr);
  if (n>0 && n<100){
    for (int i=0; i<n; i++){
      if (!isalpha(inputStr[i])) return -1;
    }
    return 1;
  }
  return -1;
}

char *stringEval(int inputLen, char inputStr[], char subString[]) {
  int maxCount = 0;
  int startPos = 0;
  int tempCount = 1;
  // Calculates the temporary string in alphabetical order
  for (int i = 0; i < inputLen-1; i++){
    for(int j = i+1; j < inputLen; j++){
      if(inputStr[j] < inputStr[j-1]){
        break;
      }
      tempCount++;
    }

  //Checks if this new alphabetical string is longer than the longest
    if (tempCount > maxCount){
      printf("Start: %d, Length: %d\n", i, tempCount);
      maxCount = tempCount;
      startPos = i;
    }
    tempCount = 1;
  }

  //Puts longest string into new array and returns.
  for (int c = 0; c < maxCount; c++){
      subString[c] = inputStr[startPos+c];
  }
  // printf("%s\n", subString);
  return subString;
}

void testStringCheck() {
  assert(stringCheck("a")==1);
  assert(stringCheck("ab")==1);
  assert(stringCheck("zxy")==1);
  assert(stringCheck("")==-1);
  assert(stringCheck("2")==-1);
  assert(stringCheck("x0")==-1);
  assert(stringCheck("abc5d")==-1);
}

void testStringEval(){
  char subString[100];
  memset(subString,0, sizeof subString);
  assert(stringEval(3,"aba",subString)=="ab");
  assert(stringEval(5,"abcab",subString)=="abc");
  assert(stringEval(7,"wxysabc",subString)=="wxy");
  assert(stringEval(1,"a",subString)=="a");
}

// // Run tests on the stringCheck function.
void test() {
    testStringCheck();
    testStringEval();
    printf("All tests passed\n");
}

// Run the program or, if there are no arguments, test it.
int main(int n, char *strArray[n]) {
    setbuf(stdout, NULL);
    char subString[100];
    memset(subString,0, sizeof subString);

    if (n == 1) {
        test();
    }
    else if (n >1) {
      int printCheck = stringCheck(strArray[1]);
      if (printCheck == 1){
        printf("%s\n",stringEval(strlen(strArray[1]),strArray[1],subString));
      }
      else {
        printf("Input is invalid\n");
      }
    }
    else{
        fprintf(stderr, "Use e.g.: ./StringEvaluation abcdefg\n");
        exit(1);
    }
  return 0;
}
