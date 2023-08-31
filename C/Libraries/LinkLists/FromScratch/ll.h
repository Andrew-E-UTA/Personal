#ifndef _LL_H
#define _LL_H
#include <stdio.h>
#include <stdbool.h>

struct node {
	int data;
	struct node * next;
};

typedef struct node node;
typedef struct node * nodePT;

nodePT getLast(nodePT);
void insert(nodePT, int);
bool insertBehind(nodePT, int, int);
void print(nodePT);
void pop(nodePT);
void save(nodePT, FILE*);
void cleanup(nodePT);

#endif
