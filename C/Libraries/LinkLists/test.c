/*
 * Author: Andrew Espinoza
 *
 * Description: program to test the functionality of my linked list library.
 */

#include <stdio.h>

#include "./lib/list.h"

enum ErrorCodes
{
    SUCCESS,
    FAILURE
};

int main(int argc, char* argv[])
{

    List* myList = NewList();
    if(!myList)
    {
        perror("error: could not initialize list ...\n");
        return FAILURE;
    }

    for(int i = 1; i <= 10; i++)
        push(myList, i);
    PrintList(myList);

    return SUCCESS;
}

