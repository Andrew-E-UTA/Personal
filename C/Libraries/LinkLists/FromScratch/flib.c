#include <stdio.h>
#include "flib.h"

FILE* createSave(char fileName[]){

	FILE* fp = NULL;
	fp = fopen(fileName, "w+");
	if(fp == NULL) return NULL;
	else return fp;
}
