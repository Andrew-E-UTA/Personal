#include <stdio.h>

int AddTwoInts(int x, int y)
{
	return (x + y);
}

int main(int argc, char* argv[]) // argc is num of args argv at an index is the actuall arg
{
	int z = AddTwoInts(3, 2);
	
	printf("Arguments: %i\n", argc);
	//printf("Arguments: %d\n", argc);
	
	if(argc > 1)
	{
		printf("First Argument: %s\n", argv[1]); // index 0 is "a.out"
	}
	
	printf("\nAnswer is: %d\n", z);
	
	return 0;
}
