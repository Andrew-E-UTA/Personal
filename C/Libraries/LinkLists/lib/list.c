#include "list.h"


List* NewList()
{
    List* list = NULL;
    Node* root = NULL;
    
    list = calloc(1, sizeof(List));
    if(!list) return NULL;

    root = calloc(1, sizeof(Node));
    if(!root) return NULL;

    list->root = root;
    list->last = root;
    list->len  = 1;

    root->val  = 0;
    root->next = NULL;
    return list;
}

void PrintList(const List* list)
{
    Node* curr = list->root;

    for(int n = 0; n < list->len; n++)
    {
        printf("Node[%d]:\n\tValue: %d\n\tNext: %p\n"
                , n, curr->val, curr->next);
    }
}   
