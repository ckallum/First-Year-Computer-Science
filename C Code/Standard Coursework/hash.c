#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash.h"

//http://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29
//https://github.com/jamesroutley/write-a-hash-table#contents

Node *newNode(char *data, char *key){
  Node *new = malloc(sizeof(Node));
  new->next = NULL;
  new->data = data;
  new->key = key;
  return new;
}

HashTable *newHash(int size){
  HashTable *h = malloc(sizeof(HashTable));
  h->size = size;
  h->count = 0;
  h->array = calloc(h->size, sizeof(Node));
  return h;
}

void freeNode(Node *item){
  free(item->key);
  free(item->data);
  free(item);
}

void freeHash(HashTable *h){
  int i;
  Node *temp;
  Node *next;
  for(i=0;i < h->size;i++){
    for (temp = h->array[i]; temp!= NULL; temp = next){
      next = temp->next;
      freeNode(temp);
    }
  }
  free(h->array);
  free(h);
}

int HashFunction (const char *key, HashTable *h){
  unsigned long hash = 1;
  int size = strlen(key);
  for (int i = 0; i < size; i++){
    hash = 31*hash + key[i];
  }
  return (hash % h->size);
}


bool ListEmpty(HashTable *h, int index){
  if(h->array[index] == NULL) return true;
  return false;
}

int getIndex(HashTable *h, int index, char *key){
  Node *temp = h->array[index];
  int listIndex = 0;
  while (temp != NULL){
    if(strcmp(temp->key,key)==0) return listIndex;
    temp = temp->next;
    listIndex++;
  }
  return -1;
}

Node *getNode(HashTable *h, int listIndex,int index){
  Node *temp =h->array[index];
  for (int i = 0 ; i< listIndex; i++){
    temp = temp->next;
  }
  return temp;
}

void insert(HashTable *h, char *key, char *ch){
  int index = HashFunction(key, h);
  Node *new = newNode(ch, key);
  int listIndex = getIndex(h, index, key);
  if (ListEmpty(h, index)==true){
    h->array[index]=new;
    ++h->count;
  }
  else if(listIndex != -1){
      Node *node = getNode(h, listIndex, index);
      node->data = ch;
    }
  else{
    Node *nextNode = h->array[index]->next;
    h->array[index]->next = new;
    new->next = nextNode;
    ++h->count;
  }
  if(HashFull(h)){
    increaseSize(h);
  }
}

char *search(HashTable *h, char *key){
  int index = HashFunction(key, h);
  Node *temp = h->array[index];
  while (temp != NULL){
    if (strcmp(temp->key,key)==0) return temp->data;
    else temp = temp->next;
  }
  return NULL;
}

void delete(HashTable *h, char *key){
  int index = HashFunction(key, h);
  Node *node = h->array[index];
  Node *temp = node;
  if(node == NULL){
    printf("This key has no data\n");
    return;
  }
  while(node!=NULL){
    if (strcmp(node->key, key)==0){
      if (node == h->array[index]){
        h->array[index] = node->next;
      }
      else {
        temp->next = node->next;
      }
      h->count--;
      free(node);
      break;
    }
    temp = node;
    node = node->next;
  }
}

bool HashFull(HashTable *h){
  if((h->count*100 / h->size)>70) return true;
  return false;
}

bool HashEmpty(HashTable *h){
  if((h->count*100 / h->size)<10) return true;
  return false;
}

void increaseSize(HashTable *h){
  const int newSize = h->size *2;
  rehash(h, newSize);
}


void rehash(HashTable *h, int newSize){
  HashTable *temp = h;
  int newsize = (h->size) *2;
  h->size = newsize;
  h->array = realloc(h->array, h->size * sizeof(Node));
  for (int i = 0; i < h->size; i++){
    h->array[i] = NULL;
  }
  for (int i = 0; i < temp->size; i++){
    Node *tempNode = temp->array[i];
    if (tempNode == NULL) i++;
    while(tempNode != NULL){
      insert(h, tempNode->data, tempNode->key);
      tempNode = tempNode->next;
    }
  }
}

void printHash(HashTable *h){
  int i = 0;
  for (i = 0; i < h->size; i++){
    Node *temp = h->array[i];
    if (temp == NULL){
      printf("array[%d] has no elements\n", i);
    }
    else{
      printf("array[%d] has elements-: ", i);
      while (temp != NULL){
        printf("key= %s, value= %s\t",temp->key, temp->data);
        temp = temp->next;
      }
      printf("\n");
    }
  }
}


int main(){
  HashTable *h = newHash(10);
  insert(h, "31","john");
  insert(h, "32","john");
  insert(h, "33","john");
  insert(h, "34","john");
  printHash(h);
  delete(h, "31");
  printHash(h);
  delete(h, "32");
  printHash(h);
  // freeHash(h);
  return 0;
}
