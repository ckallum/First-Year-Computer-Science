#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash.h"


struct Node{
  Node *next;
  char *data;
};

struct HashTable{
  Node **array;
  int arrayMax;
  int capacity;
  int max;
};

Node *newNode(char *data){
  Node *new = malloc(sizeof(Node));
  new->next = NULL;
  new->data = data;
  return new;
}

HashTable *newHash(int max){
  HashTable *h = malloc(sizeof(HashTable));
  h->array = malloc(max*sizeof(Node));
  for (int i = 0; i < max; i++){
    h->array[i] = NULL;
  }
  h->capacity = 0;
  h->arrayMax = 8;
  h->max = 8;
  return h;
}

int HashFunction (char *ch, HashTable *h){
  unsigned long hash = 0;
  int size = strlen(ch);
  for (int i = 0; i < size; i++){
    hash = 31*hash + ch[i];
  }
  return (hash % h->max);
}

bool isEmpty(HashTable *h, int index){
  if(h->array[index] == NULL) return true;
  return false;
}

bool HashFull(HashTable *h){
  if (h->capacity == 8) return true;
  return false;

}

bool ListFull(HashTable *h, int index){
  int count = 0;
  Node *temp = h->array[index];
  while (temp != NULL){
      count ++;
      temp = temp->next;
  }
  if (count == (h->max*(3/4))) return true;
  return false;
}

int findKinI(HashTable *h, int index, char *data){
  Node *temp = h->array[index];
  int listIndex = 0;
  while (temp != NULL){
    if(strcmp(temp->data,data)==0) return listIndex;
    temp = temp->next;
    listIndex++;
  }
  return -1;
}

void increaseHash(HashTable *h){
  h->max = h->max*2;
  h->array = realloc(h->array, h->max);
}

void reHash(HashTable *h){

}

void insertHash(HashTable *h, char *ch){
  int index = HashFunction(ch, h);
  Node *new = newNode(ch);
  if (HashFull(h) == true){
    increaseHash(h);
    insertHash(h,ch);
  }
  else if (isEmpty(h, index)==true){
    h->array[index]=new;
    ++h->capacity;
  }
  else{
    if (ListFull(h, index)) index++;
    Node *nextNode = h->array[index]->next;
    h->array[index]->next = new;
    new->next = nextNode;
    ++h->capacity;
  }
}



int main(){
  HashTable *h = newHash(8);
  char *c = malloc(6*sizeof(char));
  c = "Johns\0";
  insertHash(h, c);
  return 0;
}
