#ifndef _LL_H
#define _LL_H
#include <stdio.h>

struct node {
	int data;
	struct node * next;
};

typedef struct node node;
typedef struct node * nodePT;

nodePT getLast(nodePT);
void insert(nodePT, int);
void print(nodePT);
void pop(nodePT);
void save(nodePT, FILE*);

#endif
