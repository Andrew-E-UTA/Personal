#include "linkedlist.h"

node *initList()
{
	node *ptr2Head = malloc(sizeof(node));
	ptr2Head->next = NULL;
	return ptr2Head;
}

void insert(node *ant, node *des)
{
	node *nuev = malloc(sizeof(node));
	ant->next = nuev;
	nuev->next = des;
}
