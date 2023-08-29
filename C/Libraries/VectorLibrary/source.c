#include <stdio.h>
#include <stdbool.h>
#include "vectLib.h"

int main(void)
{
	FILE *vect_input;
	char vector_name[MAX_NAME_SIZE] = {};
	float x,y,z;
	int buff_size = 2;
	bool end = false;

	vector *Head = NULL, *curr = NULL, *temp = NULL;

	int line_count = 0;
	vect_input = fopen("vectorfile.txt", "r");
	char line_buffer[MAX_LINE_SIZE], delims[] = "<,>";
	fgets(line_buffer, MAX_LINE_SIZE, vect_input);
	while(!feof(vect_input))
	{
		strcpy(vector_name, strtok(line_buffer, delims));
		vector_name[strlen(vector_name) - 1] = '\0';
		x = atof( strtok(NULL, delims) );
		y = atof( strtok(NULL, delims) );
		z = atof( strtok(NULL, delims) );
		if(Head == NULL)
		{
			Head = initVector(vector_name, x, y, z);
			if(Head != NULL)
			{
				curr = Head;
			}
		}	//problem with segfault... *curr is null and cant be accessed...*
		else
		{
			curr->next_vector = initVector(vector_name, x, y, z);
			if(curr->next_vector != NULL)
				curr = curr->next_vector;
		}
		line_count++;
		fgets(line_buffer, MAX_LINE_SIZE, vect_input);
	}

	printVector(Head);

	clean(Head);
	fclose(vect_input);
	return(0);
}

void clean(vector *Head)
{
	vector *temp;
	while(Head)
	{
		temp = Head;
		Head = Head->next_vector;
		free(temp);
	}
}
