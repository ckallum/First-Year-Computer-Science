#include <stdbool.h>

struct heapArr;
typedef struct heapArr heapArr;

struct minNode;
typedef struct minNode minNode;

struct minHeap;
typedef struct minHeap minHeap;


minNode *newNode(char data, int freq);

heapArr *newHeapArr(int capacity, char chars[], int freqs[]);

void initialiseInput();

void freeHeap(minHeap *h);

void freeHeapArr(heapArr *arr);

void sortHeap(minHeap *h, int index);

void swapNode(minNode**a, minNode**b);

minNode findMin(minHeap *h);

void insertNode(minHeap *h,minNode *n);

void expandHeap(minHeap *h);

int isLeaf(minNode *root);

minHeap* createHeap(heapArr *arr);

minNode *huffmanTree(heapArr *arr);

void printCodes(minNode *root, heapArr *arr, int top);

void HuffmanCodes(heapArr *arr);


int testGetFreq(int input, int freqs[], int index);
int testGetData(char input);
