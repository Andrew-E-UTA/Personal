#include "linkedlist.h"

int main(int argc, char *argv[])
{
	if(argc != 2)
		exit (1);
	int listSize = atoi(argv[1]);
	printf("You requested a linked list of size: %d\n", listSize);

	node *Root = NULL;
	Root = initList();

	for(int i = 0; i < listSize; i++)
	{
		
	}
	return (0);
}
