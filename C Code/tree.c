#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"tree.h"

//STRUCT SECTION
struct heapArr{
  char *data;
  int *freq;
  int capacity;
};

struct minNode{
  char data;
  int freq;
  minNode *left;
  minNode *right;
};

struct minHeap{
  int size;
  int capacity;
  minNode *array;
};



//INITIALISE STRUCTURES;;
heapArr *newHeapArr(int capacity, char chars[], int freqs[]){
  heapArr *arr = malloc(sizeof(heapArr));
  arr->data = chars;
  arr->freq = freqs;
  arr->capacity = capacity;
  return arr;
}

minNode *newNode(char data, int freq){
  minNode *tempNode = malloc(sizeof(minNode));
  tempNode->left = tempNode->right = NULL;
  tempNode->freq = freq;
  tempNode->data = data;
  return tempNode;
}

minHeap *newHeap(int capacity){
  minHeap *h = malloc(sizeof(minHeap));
  h->size = 0;
  h->capacity = capacity;
  h->array = malloc(h->capacity * sizeof(minNode));
  return h;
}


//CREATE TREE
minHeap *CreateMinHeap(heapArr *arr){
  minHeap *h = newHeap(arr->capacity);
  for (int i = 0; i < h->capacity; i++){
    h->array[i] = *newNode(arr->data[i], arr->freq[i]);
  }
  return h;
}

minNode buildTree(heapArr *arr){
  minNode *left;
  minNode *right;
  minNode *top;

  minHeap *heap = CreateMinHeap(arr);
  while(heap->size != 1){
    *left = findMin(heap);
    *right = findMin(heap);
    top = newNode('s', left->freq + right->freq);
    top->left = left;
    top->right = right;
    insertNode(heap, top);
  }
  return findMin (heap);
}


void insertNode(minHeap *h, minNode *n){

}





//FREE SECTION
void freeHeap(minHeap *h){

}

void freeHeapArr(heapArr *arr){

}

void freeNode(minNode *n){

}




//IO
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
  if ((index > 0) && (input < freqs[index-1])) return -1;
  return 1;
}

heapArr *initialiseInput(int arrLen){
  int freqs[arrLen];
  char chars[arrLen+1];
  heapArr *arr = newHeapArr(arrLen,getHeapData(arrLen,chars), getHeapFreq(arrLen, freqs));
  printf("CharArray: %s, Number of Chars: %d\n", arr->data,arr->capacity);
  return arr;
}


//MAIN INITIALISER
void HuffmanCodes(heapArr *arr){

}

void printCodes(minNode *root, int arr[], int top){

}

//DRIVER
int main()
{
  int size;
  char line[100];
  printf( "How many characters do you want to encode?: \n");
  fgets(line,sizeof(line), stdin);
  sscanf(line, "%d", &size);
  heapArr *arr =initialiseInput(size);
  HuffmanCodes(arr);
  return 0;
}
