#include <stdbool.h>

struct Node;
typedef struct Node Node;

struct HashTable;
typedef struct HashTable HashTable;

void reHash(HashTable *h);
void insertHash(HashTable *h, char *ch);
