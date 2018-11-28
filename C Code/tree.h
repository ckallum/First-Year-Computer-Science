#include <stdbool.h>

struct huffData;
typedef struct huffData huffData;

struct huffNode;
typedef struct huffNode huffNode;

struct nodeLists;
typedef struct nodeLists nodeLists;

huffData *newHeapArr(int capacity, char chars[], int freqs[]);
huffNode *newNode(char data, char freq);

void add2List(nodeLists *l, huffNode *n);
huffNode *subFromList(nodeLists *l);

huffNode *findMin(nodeLists *l1, nodeLists *l2);


void HuffmanCodes(huffData *arr);






int *getHeapFreq(const int arrLen, int freqs[]);
char *getHeapData(const int arrLen, char chars[]);
int testGetData(char input);
int testGetFreq(int input, int freqs[], int index);
huffData *initialiseInput(int arrLen);
