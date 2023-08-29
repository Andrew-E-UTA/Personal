/*
Author: Andrew Espinoza
Description: Function definitions for vectLib header file. Contains the operations that can be formed on vectors.
	such vector types are defined in vectLib.h.
*/

#include "vectLib.h"

vector *initVector(char name[], float i, float j, float k)
{
	vector *v = calloc(2, sizeof(vector));
	v->next_vector = NULL;
	strcpy(v->name, name);
	v->i = i;
	v->j = j;
	v->k = k;
	v->magnitude = sqrt( (i*i) + (j*j) + (k*k));

	v->unit_i = i / v->magnitude;
	v->unit_j = j / v->magnitude;
	v->unit_k = k / v->magnitude;
	return v;
}

void printVector(vector *vect)
{
	printf("\n");
	printf("\tMatrix-Form:\n\t\t %s = <%.1f, %.1f, %.1f>\n", vect->name, vect->i, vect->j, vect->k);
	printf("\n");
	printf("\tUnit-Form:\n\t\t %s = %.1fi + %.1fj + %.1fk\n", vect->name, vect->i, vect->j, vect->k);
	printf("\n");
	printf("\tUnit Vector:\n\t\t U = <%.01f, %.01f, %.01f>\n", vect->unit_i, vect->unit_j, vect->unit_k);
	printf("\n");
}

float dot(vector *v1, vector *v2)
{
	float dotProduct = 0;

	dotProduct += (v1->i * v2->i);
	dotProduct += (v1->j * v2->j);
	dotProduct += (v1->k * v2->k);
	return dotProduct;
}

vector *cross(vector *v1, vector *v2)
{
	vector *resultant = NULL;
	float R_i, R_j, R_k;
	char default_name[MAX_NAME_SIZE] = {};
	strcpy(default_name, v1->name);
	strcat(default_name, " X ");
	strcat(default_name, v2->name);
	R_i = ((v1->j * v2->k) - (v1->k * v2->j));
	R_j = ((v1->i * v2->k) - (v1->k * v2->i));
	R_k = ((v1->i * v2->j) - (v1->j * v2->i));

	resultant = initVector(default_name, R_i, R_j, R_k);

	return resultant;
}
void uscaleVect(vector *v1, int num)
{
	v1->i *= num;
	v1->j *= num;
	v1->k *= num;
}
