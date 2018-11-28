#include <stdbool.h>

struct heapArr;
typedef struct heapArr heapArr;

struct minNode;
typedef struct minNode minNode;

struct minHeap;
typedef struct minHeap minHeap;


minNode *newNode(char data, int freq);
heapArr *newHeapArr(int capacity, char chars[], int freqs[]);
minHeap *newHeap(int capacity);
minNode *huffmanTree(minNode *n, heapArr *arr);

void freeHeap(minHeap *h);
void freeHeapArr(heapArr *arr);
void freeNode(minNode *n);

void sortHeap(minHeap *h, int index);
void swapNode(minNode**a, minNode**b);


minNode buildTree(heapArr *arr);
void insertNode(minHeap *h,minNode *n);
minNode findMin(minHeap *h);

void expandHeap(minHeap *h);

int isLeaf(minNode *root);


void HuffmanCodes(heapArr *arr);
void printCodes(minNode *root, int arr[], int top);

heapArr *initialiseInput(int arrLen);
int testGetFreq(int input, int freqs[], int index);
int testGetData(char input);
