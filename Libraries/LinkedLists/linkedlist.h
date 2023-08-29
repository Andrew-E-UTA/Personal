#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXNAME 21

struct node
{
	char name[MAXNAME];
	struct node *next;
};
typedef struct node node;

node *initList(void);
void insert(node*, node*);
#endif
