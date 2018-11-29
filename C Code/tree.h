#include <stdbool.h>

struct huffData;
typedef struct huffData huffData;

struct huffNode;
typedef struct huffNode huffNode;

struct nodeLists;
typedef struct nodeLists nodeLists;

int *getHeapFreq(const int arrLen, int freqs[]);
char *getHeapData(const int arrLen, char chars[]);
int testGetData(char input);
int testGetFreq(int input, int freqs[], int index);
huffData *initialiseInput(int arrLen);
