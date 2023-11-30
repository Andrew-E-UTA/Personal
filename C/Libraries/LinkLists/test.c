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
    PrintList(myList);

    return SUCCESS;
}

