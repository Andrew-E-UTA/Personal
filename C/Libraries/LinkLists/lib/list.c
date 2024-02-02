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
                , n, curr->val, (void*)curr->next);
        curr = curr->next;
    }
}  

int push(List* list, int val)
{
    Node* newNode = NULL;

    newNode = calloc(1, sizeof(Node));
    if(!newNode) return 0;

    newNode->val = val;
    newNode->next = NULL;
    
    list->last->next = newNode;
    list->last = newNode;
    list->len++;
    return 1;
}

int pop(List* list)
{
    if(!list) return -1;
    if(!list->root) return 1;
    Node* curr = list->root;
    Node* prev = NULL;
    int val = -1;
    while(curr->next)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    val = curr->val;
    free(curr);
    list->last = prev;
    list->len--;
    return val;
}

void rem(List* list, int val)
{
    
}
void FreeList(List* list)
{
    if(!list || !list->root)
        return;
    Node* curr = list->root;
    Node* temp  = curr->next;
    while(!curr)
    {
        curr->val = -1;
        free(curr);
        curr = temp;
        if(!temp->next)
            temp = temp->next;
        
    }
}

Node* isInList(List* list, int val)
{
    if(!list) return NULL;
    if(!list->root) return NULL;

    Node* curr = list->root;
    while(curr)
    {
        if(curr->val == val)
            return curr;        
        curr = curr->next;
    }
    return NULL;
}
