#include "ll.h"
#include <stdio.h>
#include <stdbool.h>
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
	nodePT anew = malloc(sizeof(node));
	anew->next = NULL;
	anew->data = data;

	nodePT last = getLast(Head);
	last->next = anew;
	return;
}

bool insertBehind(nodePT Head, int frontNode, int data){
	nodePT prev = NULL, curr = NULL;

	nodePT anew = malloc(sizeof(node));
	anew->next = NULL;
	anew->data = data;

	if(Head == NULL){
		printf("error, no list to add to..\n");
		return false;
	}
	else curr = Head;

	while(curr != NULL){
		if(curr->data == frontNode){
			anew->next = curr;
			prev->next = anew;
			return true;
		}
		prev = curr;
		curr = curr->next;
	}
	printf("No node with value of %d to insert behind of...\n", frontNode);
	return true;
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

void deleteNode(nodePT Head, int target){
	nodePT curr = NULL, prev = NULL;

	if(Head != NULL) curr = Head;
	else return;

	while(curr != NULL){
		if(curr->data != target){
			prev = curr;
			curr = curr->next;
		}
		else{
			prev->next = curr->next;
			free(curr);
			return;
		}
	}
	printf("There is no node with value %d to delete!\n", target);
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

void cleanup(nodePT Head){

	if(Head == NULL){
		printf("Nothing to cleanup... Exiting.");
		return;
	}
	else{
		while(Head->next != NULL)
			pop(Head);
		free(Head);
		Head = NULL;
		print(Head);
	}
	return;
}

