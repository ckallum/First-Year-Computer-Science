#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

// Use arrays of size 128 for ASCII characters.
enum { SIZE = 128 };

// Tree node representing one character, its frequency, and eventually its
// Huffman code (as text, not compressed bits, for demo purposes).
struct node {
  char ch;
  int n;
  struct node *left, *right;
  char code[20];
};
typedef struct node node;

// Create an array of SIZE pointers to nodes. This acts as a map from character
// codes to their nodes.
node **newMap() {
    node **map = malloc(SIZE * sizeof(node));
    for (int ch = 0; ch < SIZE; ch++) {
        map[ch] = malloc(sizeof(node));
        *map[ch] = (node) { ch, 0, NULL, NULL, "" };
    }
    return map;
}

void freeMap(node *map[SIZE]) {
    for (int ch = 0; ch < SIZE; ch++) free(map[ch]);
    free(map);
}

// Gather statistics for a string.
void count(node *map[SIZE], char const *s) {
    for (int i = 0; i < strlen(s); i++) {
        int ch = s[i];
        map[ch]->n++;
    }
}

// -----------------------------------------------------------------------------
// Functions implementing a priority queue as a binary heap (one of the most
// beautiful data structures in computer science). It is an implicit binary tree
// stored in an array. The children of node i are nodes 2*i+1 and 2*i+2 and the
// parent of node i is node (i-1)/2. (Why so many descriptions start at index 1
// instead of index 0 is a mystery.) The tree is semi-sorted by character count
// so that a node's count is smaller than either of its children. Initial
// semi-sorting is linear, and operations after that are O(log(n)). (Put these
// in a separate module to reuse.)

struct queue { int length; node *nodes[SIZE]; };
typedef struct queue queue;

// Create a queue from a map, including only nodes with non-zero counts.
// Use a forward reference to the buildHeap function below.
void sort(queue *q);
queue *newQueue(node *map[SIZE]) {
    queue *q = malloc(sizeof(queue));
    q->length = 0;
    for (int ch = 0; ch < SIZE; ch++) {
        if (map[ch]->n > 0) {
            q->nodes[q->length] = map[ch];
            q->length++;
        }
    }
    sort(q);
    return q;
}

// Free a queue, but not the nodes in it.
void freeQueue(queue *q) {
    free(q);
}

// Swap two nodes of an array. (Make static and inline for efficiency.)
void swap(node *nodes[], int i, int j) {
    node *temp = nodes[i];
    nodes[i] = nodes[j];
    nodes[j] = temp;
}

// Move node i up to the right place, iteratively. This function is often called
// heapifyUp or siftUp or bubbleUp...
void up(queue *q, int i) {
    bool done = false;
    while (i > 0 && ! done) {
        int parent = (i - 1)/2;
        if (q->nodes[parent]->n < q->nodes[i]->n) done = true;
        else swap(q->nodes, i, parent);
        i = parent;
    }
}

// Move node i down to the right place, iteratively. This function is often
// called heapifyDown, siftDown, bubbleDown, ...
void down(queue *q, int i) {
    bool done = false;
    while (! done) {
        int left = 2*i + 1, right = 2*i + 2;
        int smallest = i;
        if (left < q->length && q->nodes[left]->n < q->nodes[i]->n) {
            smallest = left;
        }
        if (right < q->length && q->nodes[right]->n < q->nodes[smallest]->n) {
            smallest = right;
        }
        if (smallest == i) done = true;
        else swap(q->nodes, i, smallest);
        i = smallest;
    }
}

// Extract the lowest priority item from a binary heap.
node *extract(queue *q) {
    node *smallest = q->nodes[0];
    q->length--;
    q->nodes[0] = q->nodes[q->length];
    down(q, 0);
    return smallest;
}

// Insert a node into a binary heap.
void insert(queue *q, node *p) {
    int n = q->length;
    q->nodes[n] = p;
    q->length++;
    up(q, n);
}

// Semi-sort all of the original nodes.
void sort(queue *q) {
    for (int i = q->length/2; i >= 0; i--) down(q, i);
}

// -----------------------------------------------------------------------------
// The Huffman algorithm. Repeatedly combine the two nodes with the lowest
// counts. Then use left and right navigation to define zeros and ones.

// Create a Huffman tree from a queue.
node *newTree(queue *q) {
    while (q->length > 1) {
        node *p1 = extract(q);
        node *p2 = extract(q);
        node *p = malloc(sizeof(node));
        *p = (node) { '?', p1->n + p2->n, p1, p2, "" };
        insert(q, p);
    }
    node *root = q->nodes[0];
    return root;
}

// Free the internal nodes inserted by newTree, but not the original nodes.
void freeTree(node *t) {
    if (t->left != NULL) {
        freeTree(t->left);
        freeTree(t->right);
        free(t);
    }
}

// Add encodings to a Huffman tree, given a prefix of 0s and 1s. Add a 0 to go
// left, a 1 to go right and restore the prefix to what it was before returning.
void encode(node *tree, char prefix[20]) {
    if (tree->left == NULL) {
        strcpy(tree->code, prefix);
        return;
    }
    int n = strlen(prefix);
    prefix[n] = '0';
    prefix[n+1] = '\0';
    encode(tree->left, prefix);
    prefix[n] = '1';
    encode(tree->right, prefix);
    prefix[n] = '\0';
}

// Tests are based on an example in the Wikipedia article on Huffman.
char const text[] = "A_DEAD_DAD_CEDED_A_BAD_BABE_A_BEADED_ABACA_BED";

// Test statistics.
void testCount(node *map[SIZE]) {
    assert(map['C']->n == 2);
    assert(map['B']->n == 6);
    assert(map['E']->n == 7);
    assert(map['_']->n == 10);
    assert(map['D']->n == 10);
    assert(map['A']->n == 11);
}

void testQueue(queue *q) {
    assert(q->length == 6);
    assert(q->nodes[0]->ch == 'C');
    assert(q->nodes[1]->ch == 'B');
    assert(q->nodes[2]->ch == '_');
    assert(q->nodes[3]->ch == 'D');
    assert(q->nodes[4]->ch == 'E');
    assert(q->nodes[5]->ch == 'A');
}

void testTree(node *tree) {
    assert(tree->n == 46);
    assert(tree->left->n == 20);
    assert(tree->left->left->ch == 'D');
    assert(tree->left->right->ch == '_');
    assert(tree->right->n == 26);
    assert(tree->right->left->ch == 'A');
    assert(tree->right->right->n == 15);
    assert(tree->right->right->left->ch == 'E');
    assert(tree->right->right->right->n == 8);
    assert(tree->right->right->right->left->ch == 'C');
    assert(tree->right->right->right->right->ch == 'B');
}

void testEncode(node *map[SIZE]) {
    assert(strcmp(map['D']->code, "00") == 0);
    assert(strcmp(map['_']->code, "01") == 0);
    assert(strcmp(map['A']->code, "10") == 0);
    assert(strcmp(map['E']->code, "110") == 0);
    assert(strcmp(map['C']->code, "1110") == 0);
    assert(strcmp(map['B']->code, "1111") == 0);
}

int main() {
    node **map = newMap();
    count(map, text);
    testCount(map);
    queue *q = newQueue(map);
    testQueue(q);
    node *tree = newTree(q);
    freeQueue(q);
    testTree(tree);
    char prefix[20] = "";
    encode(tree, prefix);
    freeTree(tree);
    testEncode(map);
    for (int ch = 0; ch < SIZE; ch++) {
        node *p = map[ch];
        if (p->n != 0) printf("%c %s\n", p->ch, p->code);
    }
    freeMap(map);
    return 0;
}
