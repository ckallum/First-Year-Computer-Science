#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash.h"


struct Node{
  Node *next;
  int key;
  int value;
};

struct SLL{
  Node *currentNode;
  int capacity;
};

struct HashTable{
  SLL **array;
  int capacity;
};

Node *newNode(int key, int value){
  Node *new = malloc(sizeof(Node));
  *new = (Node) {NULL, key, value};
  return new;
}

SLL *newSLL(int capacity){
  SLL *l = malloc(sizeof(SLL));
  l->currentNode = NULL;
  l->capacity = capacity;
  return l;
}

HashTable *newHash(int k, int capacity){
  HashTable *h = malloc(sizeof(HashTable));
  h->array[k] = newSLL(k);
  h->capacity = capacity;
  return h;
}

int HashFunction (char ch[]){
  int key = 1;
  int size = strlen(ch);
  for (int i = 0; i < size; i++){
    key = 31*key + ch[i];
  }
  return key;
}

bool isEmpty(HashTable *h, int key){
  if(h->array[key] == NULL) return true;
  return false;
}

void insertHash(HashTable *h, char ch[]){
  int key = HashFunction(ch);
  if (isEmpty(h,key)==true){
    h->array[key]->currentNode = newNode(key,*ch);
  }
  else{
    h->array[key]->currentNode->next = newNode(key,*ch);
    h->array[key]->currentNode = h->array[key]->currentNode->next;
  }
}



int main(){
  return 0;
}
