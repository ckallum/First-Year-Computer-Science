#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"tree.h"
#define treeHeight = 100;

//STRUCT SECTION

struct huffData{
  int size;
  char *data;
  int *frequencies;
};

struct huffNode{
  huffNode *left;
  huffNode *right;
  char data;
  int freq;
};

struct nodeLists{
  int front;
  int back;
  int capacity;
  huffNode **array;
};

huffData *newHeapArr(int capacity, char chars[], int freqs[]){
  huffData *arr = malloc(sizeof(huffData));
  arr->data = chars;
  arr->frequencies = freqs;
  arr->size = capacity;
  return arr;
}

huffNode *newNode(char data, char freq){
  huffNode *temp = malloc(sizeof(huffNode));
  temp->left = temp->right = NULL;
  temp->data = data;
  temp->freq = freq;
  return temp;
}

nodeLists *newList(int capacity){
  nodeLists *list = malloc(sizeof(nodeLists));
  list->front = -1;
  list->back = -1;
  list->capacity = capacity;
  list->array = malloc(list->capacity * sizeof(huffNode));
  return list;
}

void add2List(nodeLists *l, huffNode *n){
  if(l->back == l->capacity-1)return;
  l->array[(l->back)+1] = n;
  if (l->front == -1) l->front = l->front+1;
}

huffNode *subFromList(nodeLists *l){
  if(l->front==-1)return NULL;
  huffNode *temp = l->array[l->front];
  if(l->front == l->back){
    l->front = l->back = -1;
  }
  else
  l->front = l->front +1;
  return temp;
}

huffNode *findMin(nodeLists *l1, nodeLists *l2){
  if(l1->front ==-1){
    return(subFromList(l2));
  }
  if(l2->front == -1){
    return(subFromList(l1));
  }
  if(((l1->front != -1)&& (l2->front != -1)) && (l1->array[l1->front]->freq < l2->array[l2->front]->freq)){
    return subFromList(l1);
  }
  return subFromList(l2);
}


int nodeLeaf(huffNode *n){
  return !(n->left) && !(n->right);
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

huffData *initialiseInput(int arrLen){
  int freqs[arrLen];
  char chars[arrLen+1];
  huffData *arr = newHeapArr(arrLen,getHeapData(arrLen,chars), getHeapFreq(arrLen, freqs));
  printf("CharArray: %s, Number of Chars: %d\n", arr->data,arr->size);
  return arr;
}



//DRIVER
int main()
{
  int size;
  char line[100];
  printf( "How many characters do you want to encode?: \n");
  fgets(line,sizeof(line), stdin);
  sscanf(line, "%d", &size);
  huffData *arr =initialiseInput(size);
  free(arr);
  // HuffmanCodes(arr);
  return 0;
}
