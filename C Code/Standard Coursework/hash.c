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
  int capacity;
  int max;
};

Node *newNode(char *data){
  Node *new = malloc(sizeof(Node));
  new->next = NULL;
  new->data = data;
  return new;
}

HashTable *newHash(){
  HashTable *h = malloc(sizeof(HashTable));
  h->max = 8;
  h->array = malloc(h->max*sizeof(Node));
  for (int i = 0; i < h->max; i++){
    h->array[i] = NULL;
  }
  h->capacity = 0;
  return h;
}

void freeHash(HashTable *h){
  for (int i = 0; i < h->max; i++){
    if(h->array[i]==NULL) free(h->array[i]);
    else {
      Node *temp = h->array[i];
      Node *next = temp->next;
      while(temp != NULL){
        free(temp);
        temp = next;
        next = temp->next;
      }
    }
  }
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

Node *getNode(HashTable *h, int listIndex,int index){
  Node *temp =h->array[index];
  for (int i = 0 ; i<= listIndex; i++){
    temp = temp->next;
  }
  return temp;
}

bool HashFull(HashTable *h){
  if ((h->capacity/h->max) >= 0.75){
    return true;
  }
  return false;
}


void reHash(HashTable *h){
  HashTable *temp = h;
  int newMax = (h->max) *2;
  h->max = newMax;
  h->array = realloc(h->array, h->max * sizeof(Node));
  for (int i = 0; i < h->max; i++){
    h->array[i] = NULL;
  }
  for (int i = 0; i < temp->max; i++){
    Node *tempNode = temp->array[i];
    if (tempNode == NULL) i++;
    while(tempNode != NULL){
      insertHash(h, tempNode->data);
      tempNode = tempNode->next;
    }
  }
}

void insertHash(HashTable *h, char *ch){
  int index = HashFunction(ch, h);
  Node *new = newNode(ch);
  int listIndex = findKinI(h, index, ch);
  if (isEmpty(h, index)==true){
    h->array[index]=new;
    ++h->capacity;
  }
  else if(listIndex != -1){
      Node *node = getNode(h, listIndex, index);
      node->data = ch;
    }
  else{
    Node *nextNode = h->array[index]->next;
    h->array[index]->next = new;
    new->next = nextNode;
    ++h->capacity;
  }
  if (HashFull(h)){
    reHash(h);
  }
}

void printHash(HashTable *h){
  int i = 0;
  for (i = 0; i < h->max; i++){
    Node *temp = h->array[i];
    if (temp == NULL){
      printf("array[%d] has no elements\n", i);
    }
    else{
      printf("array[%d] has elements-: ", i);
      while (temp != NULL){
        printf("value= %s\t", temp->data);
        temp = temp->next;
      }
      printf("\n");
    }
  }
}


int main(){
  HashTable *h = newHash();
  printf("How many characters would you like to insert\n");
  char line[100];
  int size;
  fgets(line,sizeof(line), stdin);
  sscanf(line, "%d", &size);
  for (int i = 0; i<size; i++){
    printf("What character would you like to hash?\n");
    fgets(line, 100, stdin);
    insertHash(h, line);
  }
  printHash(h);
  freeHash(h);
  return 0;
}
