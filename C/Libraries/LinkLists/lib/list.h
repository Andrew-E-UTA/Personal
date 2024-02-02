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

void FreeList(List* list);

void PrintList(const List* list);

/*
 * Description: This will append a node with value 'val' to the end of the linked list. 
 * Returns: 0 if it was not able to push, 1 otherwise.
 */
int push(List* list, int val);

/*
 * Description: Looks in list to see if val is in that list.
 * Returns: Ptr to the node.
 */
Node* isInList(List* list, int val);

/*
 *  Description: Removes and frees the LAST node in the linked list.
 *  Returns: Value of the popped node.
 */
int pop(List* list);

/*
 *  Description: Removes and frees the node in the list with value 'val' if it exists
 *      in the list.
 */
void rem(List* list, int val);

/*
 *  Description: swaps the node with value 'val' and the next sequential node.
 */
void swap(List* list, int val);


/*
 *  Description: Uses the sorting algortithm quicksort to sort the linked list
 */
void quickSort(List* list);




