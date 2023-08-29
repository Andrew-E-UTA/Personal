/*
Author: Andrew Espinoza
Description: Amateur library for defining vectors and operation on them.
*/

#ifndef _VECTLIB_H
#define _VECTLIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define MAX_NAME_SIZE 20
#define MAX_LINE_SIZE 50

struct vector
{
	float i, j, k;
	float unit_i, unit_j, unit_k, magnitude;
	struct vector *next_vector;
	char name[];
};
typedef struct vector vector;

vector *initVector(char [], float, float, float);
void printVector(vector*);
float dot(vector*, vector*);
vector *cross(vector*, vector*);
void uscaleVect(vector*, int);
void clean(vector *);
#endif
