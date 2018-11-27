#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"tree.h"

struct heapArr{
  char *data;
  int *freq;
  int capacity;
};

heapArr *newHeapArr(int capacity, char chars[], int freqs[]){
  heapArr *arr = malloc(sizeof(heapArr));
  arr->data = chars;
  arr->freq = freqs;
  arr->capacity = capacity;
  return arr;
}


// struct minNode* newNode{
//
// }

//Get's the frequencies of corresponding data to be encoded
int *getHeapFreq(const int arrLen, int freqs[]){
  char line[100];
  int freq;
  for (int i=0; i< arrLen; i++){
    printf( "Enter the sorted frequencies(smallest to largest) of the chars: \n");
    fgets(line,sizeof(line), stdin);
    sscanf(line, "%d", &freq);
    if(testGetFreq(freq, freqs, i)== -1){
      printf("This input is invalid, Try again\n");
      i--;
    }
    else freqs[i] = freq;
  }
  return freqs;
}

//Get's the characters from stdin to be encoded
char *getHeapData(const int arrLen, char chars[]){
  char line[100];
  char ch;
  for (int i=0; i<arrLen; i++){
    printf( "What characters do you want to encode?: \n");
    fgets(line,sizeof(line), stdin);
    sscanf(line, "%c", &ch);
    if(testGetData(ch)==-1){
      printf("This input is invalid, Try again\n");
      i--;
    }
    else chars[i] = ch;
  }
  chars[arrLen] = '\0';
  return chars;
}

//Tests that the input's are valid
int testGetData(char input){
  if(!isalpha(input))return -1;
  return 1;
}

int testGetFreq(int input, int freqs[], int index){
  // bool digits = true;
  // if(!isdigit(input)) digits = false;
  // if(digits == false) return -1;
  if ((index > 0) && (input < freqs[index-1])) return -1;
  return 1;
}

void initialiseInput(){
  int arrLen;
  char line[100];
  printf( "How many characters do you want to encode?: \n");
  fgets(line,sizeof(line), stdin);
  sscanf(line, "%d", &arrLen);
  int freqs[arrLen];
  char chars[arrLen+1];
  heapArr *arr = newHeapArr(arrLen,getHeapData(arrLen,chars), getHeapFreq(arrLen, freqs));
  printf("%s and %d and %d\n", arr->data,arr->freq[1],arr->capacity);
  free(arr); //temp free
}

int main()
{
  initialiseInput();
  return 0;
}
