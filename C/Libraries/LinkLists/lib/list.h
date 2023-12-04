#pragma once
/*
 * Author: Andrew Espinoza
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

typedef struct __node
{
    int val;
    struct __node* next;
}Node;

typedef struct __list
{
    Node* root;
    Node* last;
    int len;
}List;


//List Functions ===================================

/*
 * Description: This function creates the root node for this list instance and
 *  initializes it to default values of int and ptr to 0 and NULL respectively.
 */
List* NewList();

/*
 *Description: Self Explanitory
 */
void PrintList(const List* list);

/*
 *Description: This will append a node with value 'val' to the end of the linked list.
 */
int push(List* list, int val);
