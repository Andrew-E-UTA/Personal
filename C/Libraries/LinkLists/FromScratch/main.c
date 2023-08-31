#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ll.h"
#include "flib.h"

#define INSERT 2
#define PRINT 1
#define DEL 3
#define SAVE 4
#define EXIT 5

int main(int argc, char *argv[]){

	nodePT Head = malloc(sizeof(node));
	Head->data = 0;
	Head->next = NULL;


	int input = PRINT, data = 0, destination = 0;
	char delInput[3];
	char fileName[FILENAMEMAX];
	FILE* saveFile = NULL;

	while (input != EXIT){

		switch(input){
			case INSERT:
				printf("Enter data of new node: ");
				scanf("%d", &data);
				printf("\n\nEnter value of node to insert behind, or 0 for the end of the list.\n");
				scanf("%d", &destination);

				if(destination == 0) insert(Head, data);
				else insertBehind(Head, destination, data);
				break;
			case PRINT:
				print(Head);
				printf("\n");
				break;
			case DEL:
				printf("Enter value of node to delete it, or type \"p\" to delete last entry.");
				scanf("%s", delInput);
				break;
			case SAVE:
				printf("Enter name for SaveFile: ");
				scanf("%s", fileName);
				saveFile = createSave(fileName);
				save(Head, saveFile);
				break;
		}

		printf("Enter Command:\n");
		printf("1)Print\n2)Insert\n3)Delete\n4)Save\n5)Exit\n");
		scanf("%d", &input);
	}
	if(input == EXIT)
		cleanup(Head);
	return 0;
}
