/* Trying to find the longest substring of charachters in alphabetical order
in a string*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <assert.h>

// stringCheck a string into an integer.  Return False if it is not valid.
int stringCheck(int n, const char inputStr[]) {
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
  return subString;
}

void testStringCheck() {

}

// // Run tests on the stringCheck function.
void test() {
    testStringCheck();
    printf("All tests passed\n");
}

// Run the program or, if there are no arguments, test it.
int main(int n, char *strArray[n]) {
    setbuf(stdout, NULL);
    char b[2147483647];

    if (n == 1) {
        test();
    }
    else if (n >1) {
        printf("%s\n",stringEval(strlen(strArray[1]),strArray[1],b));
        printf("%d\n",stringCheck(strlen(strArray[1]), strArray[1]));
    }
    else {
        fprintf(stderr, "Use e.g.: ./StringEvaluation abcdefg\n");
        exit(1);
    }
    return 0;
}
