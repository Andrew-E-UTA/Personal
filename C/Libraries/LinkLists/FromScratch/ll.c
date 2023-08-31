#include "ll.h"
#include <stdio.h>
#include <stdlib.h>
#include "flib.h"

nodePT getLast(nodePT Head){
	nodePT curr = NULL;
	if(Head != NULL)curr = Head;
	else return NULL;
	while(curr->next != NULL)
		curr = curr->next;
	return curr;

}

void insert(nodePT Head, int data){
	nodePT anew = malloc( sizeof(node) );
	anew->next = NULL;
	anew->data = data;

	nodePT last = getLast(Head);
	last->next = anew;
	return;
}

void print(nodePT Head){
	nodePT curr = NULL;
	if(Head != NULL)curr = Head;
	else {
		printf("List does not exist! Exiting...\n");
		return;
	}
	while(curr != NULL){
		printf("Node: %d @ %p | Next: %p\n", curr->data, curr, curr->next );
		curr = curr->next;
	}
	return;
}

void pop(nodePT Head){
	nodePT curr = NULL;
	nodePT prev = NULL;

	if(Head != NULL)curr = Head;
	else return;

	while(curr->next != NULL){
		prev = curr;
		curr = curr->next;
	}

	free(curr);
	prev->next = NULL;
	return;
}

void save(nodePT Head, FILE* saveFile){

	nodePT curr = NULL;
	if(Head != NULL)curr = Head;
	else {
		fprintf(saveFile, "List does not exist! Exiting...\n");
		return;
	}
	while(curr != NULL){
		fprintf(saveFile, "Node: %d @ %p | Next: %p\n", curr->data, curr, curr->next );
		curr = curr->next;
	}

	fclose(saveFile);
	return;
}
