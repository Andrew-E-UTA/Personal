#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ll.h"
#include "flib.h"

#define INSERT 1
#define PRINT 2
#define POP 3
#define SAVE 4
#define EXIT 5

int main(int argc, char *argv[]){

	nodePT Head = malloc(sizeof(node));
	Head->data = 0;
	Head->next = NULL;


	int input = PRINT;
	int data = 0;
	char fileName[FILENAMEMAX];
	FILE* saveFile = NULL;

	while (input != EXIT){

		switch(input){
			case INSERT:
				printf("Enter value: ");
				scanf("%d", &data);
				insert(Head, data);
				break;
			case PRINT:
				print(Head);
				printf("\n");
				break;
			case POP:
				pop(Head);
				break;
			case SAVE:
				printf("Enter name for SaveFile: ");
				scanf("%s", fileName);
				saveFile = createSave(fileName);
				save(Head, saveFile);
				break;
		}

		printf("Enter Command:\n");
		printf("1) Insert\n2)Print\n3)Pop\n4)Save\n5)Exit\n");
		scanf("%d", &input);
	}


return 0;
}
