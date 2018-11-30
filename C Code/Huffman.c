#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include "Huffman.h"
#define treeHeight 100 //GLOBAL VARIABLE FOR MAXIMUM TREE HEIGHT

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
  unsigned freq;
};

struct nodeLists{
  int front;
  int back;
  int capacity;
  huffNode **array;
};

//CREATE NEW STRUCTURE FUNCTIONS
huffData *newHeapArr(int capacity, char chars[], int freqs[]){
  huffData *arr = malloc(sizeof(huffData));
  arr->data = chars;
  arr->frequencies = freqs;
  arr->size = capacity;
  return arr;
}

huffNode *newNode(char data, unsigned freq){
  huffNode *temp = malloc(sizeof(huffNode));
  temp->left = NULL;
  temp->right = NULL;
  temp->data = data;
  temp->freq = freq;
  return temp;
}

nodeLists *newList(int capacity){
  nodeLists *list = malloc(sizeof(nodeLists));
  list->front = list->back = -1;
  list->capacity = capacity;
  list->array = malloc(list->capacity * sizeof(huffNode));
  return list;
}

//FREE FUNCTIONS
void freeData(huffData *array){
  free(array);
}

void freeTree(nodeLists *l){
    while (l->back !=-1){
      free(l->array[l->back]);
      l->back = l->back-1;
    }
    free(l->array);
    free(l);
}

void freeNode(huffNode *n){
  if(n != NULL){
    freeNode(n->left);
    freeNode(n->right);
    free(n);
  }
}

//INSERTION AND DELETION FUNCTIONS
void add2List(nodeLists *l, huffNode *n){
  if(l->back == l->capacity-1)return;
  l->back = l->back +1;
  l->array[(l->back)] = n;
  if (l->front == -1){
    l->front = l->front+1;
  }
}

huffNode *subFromList(nodeLists *l){
  if(l->front==-1)return NULL;
  huffNode *t = l->array[l->front];
  if(l->front == l->back){
    l->front = l->back = -1;
  }
  else l->front = l->front +1;
  return t;
}

//FUNCTION TO FETCH THE FIRST NODE OF THE LIST
huffNode *firstNode(nodeLists* list){
  if (list->front == -1) return NULL;
  return list->array[list->front];
}

//FUNCTION TO FIND THE NODE WITH THE MINIMUM FREQUENCY FROM BOTH LISTS
huffNode *findMin(nodeLists *l1, nodeLists *l2){
  if(l1->front ==-1){
    return(subFromList(l2));
  }
  if(l2->front == -1){
    return(subFromList(l1));
  }
  if(firstNode(l1)->freq < firstNode(l2)->freq){
    return subFromList(l1);
  }
  return subFromList(l2);
}

//FUNCTION TO CREATE HUFF TREE AND FIND THE BASE/ROOT NODE
huffNode *huffTree(nodeLists *l1, nodeLists *l2,char data[], int freqs[], int size){
  huffNode *left;
  huffNode *right;
  huffNode *top;

  for (int i=0 ;i< size;i++){
    add2List(l1, newNode(data[i],freqs[i]));
  }
  while (!((l1->front == -1)&&(l2->front !=-1 && l2->front == l2->back))){
    left = findMin(l1,l2);
    right = findMin(l1,l2);
    top = newNode('$', (left->freq + right->freq));
    top->left = left;
    top->right = right;
    add2List(l2, top);
  }
  return subFromList(l2);
}

//FUNCTION TO PRINT THE BINARY VALUE OF THE CHARACTERS USING THE HUFF TREE
void printCodes(int codeArray[], int parent, huffNode *base){
  if (base->left){
    codeArray[parent] = 0;
    printCodes(codeArray, parent+1, base->left);
  }
  if (base->right){
    codeArray[parent] = 1;
    printCodes(codeArray, parent+1, base->right);
  }
  if (!(base->right) && !(base->left)){
    printf("%c:",base->data);
    for (int i = 0; i<parent;i++){
        printf("%d",codeArray[i]);
    }
    printf("\n");
  }
}


// FUNCTION TO INITIATE CALL HUFFTREE,PRINT AND FREE FUNCTIONS
void HuffmanCodes(huffData *array){
  int parent = 0;
  int cArray[treeHeight];
  nodeLists *l1 = newList(array->size);
  nodeLists *l2 = newList(array->size);
  huffNode *base = huffTree(l1, l2,array->data, array->frequencies, array->size);
  printCodes(cArray, parent,base);
  freeHuffman(l1,l2,array,base);
}

//FREE FUNCTION TO CALL OTHER FREE FUNCTIONS
void freeHuffman(nodeLists *l1, nodeLists *l2, huffData *array,huffNode *base){
  freeTree(l1);
  freeTree(l2);
  freeNode(base);
  freeData(array);
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

//INITIALISES USER INPUT, CREATES DATA STRUCTURE FOR FREQUENCIES AND CHARACTERS
huffData *initialiseInput(const int arrLen){
  int freqs[arrLen];
  char chars[arrLen+1];
  huffData *arr = newHeapArr(arrLen,getHeapData(arrLen,chars), getHeapFreq(arrLen, freqs));
  printf("Characters: %s, Number of Characters: %d\n", arr->data,arr->size);
  for (int i = 0; i < arrLen; i++){
    printf("Frequency of %c: %d\n", arr->data[i], arr->frequencies[i]);
  }
  return arr;
}

//GETS THE AMOUNT OF CHARACTERS TO BE ENCODED, CHECKS IF AMOUUN IS VALID
int getData(){
  int size;
  char line[100];
  bool valid = false;
  while (valid == false){
    printf( "How many characters do you want to encode?: \n");
    fgets(line,sizeof(line), stdin);
    sscanf(line, "%d", &size);
    if (size<=1){
      printf("Size needs to be bigger than 1\n");
    }
    else valid = true;
  }
  return size;
}

//DRIVER
int main(){
  int size = getData();
  huffData *arr = initialiseInput(size);
  HuffmanCodes(arr);
  return 0;
}
