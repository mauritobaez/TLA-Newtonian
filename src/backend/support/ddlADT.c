#include "ddlADT.h"

typedef struct node
{
    elemType elem;
    struct node *next;
    struct node *prev;
} TNode;

typedef TNode *TList;

struct ddlCDT
{
    TList first;   
    TList current; 
    TList toRemove;
    int size;
};

ddlADT newList()
{
    ddlADT ans = malloc(sizeof(struct ddlCDT));
    if (ans == NULL){
        //TODO out of memory
        return NULL;
    }
    ans->first = NULL;
    ans->current = NULL;
    ans->toRemove = NULL;
    return ans;
}

int add(ddlADT list, elemType elem) // agrega al principio
{
    TList second = list->first;
    list->first = malloc(sizeof(struct node));
    if (list->first == NULL){
        //TODO out of memory
        return 0;
    }
    list->first->elem = elem;
    list->first->next = second;
    list->first->prev = NULL;
    if (second != NULL)
        second->prev = list->first;
    list->size += 1;
    return 0;
}

void toBegin(ddlADT list)
{
    list->current = list->first;
}

int hasNext(ddlADT list)
{
    return list->current != NULL;
}

elemType next(ddlADT list)
{
    if (!hasNext(list))
    {
        return NULL;
    }
    elemType aux = list->current->elem;
    list->toRemove = list->current;
    list->current = list->current->next;
    return aux;
}

void remove(ddlADT list)
{
    if (list->toRemove != NULL)
    {
        if (list->toRemove->prev == NULL) // es el primero
        {
            list->first = list->toRemove->next;
        }
        else
        {
            list->toRemove->prev->next = list->toRemove->next;
        }

        if (list->toRemove->next != NULL)
        {
            list->toRemove->next->prev = list->toRemove->prev;
        }
        free(list->toRemove);
        list->toRemove = NULL;
        list->size -= 1;
    }
}

void freeList(ddlADT list)
{
    TList head = list->first;
    while (head != NULL)
    {
        TList aux = head->next;
        free(head);
        head = aux;
    }
    free(list);
}

elemType find(ddlADT list, int(cmpfunction(void *a, void *b)), void *toCmp)
{
    TList searcher = list->first;
    while (searcher != NULL)
    {
        if (cmpfunction(searcher->elem, toCmp))
            return searcher->elem;
        searcher = searcher->next;
    }
    return NULL;
}

int getSize(ddlADT list)
{
    return list->size;
}

int push(ddlADT list, elemType elem){
    TList second = list->first;
    list->first = malloc(sizeof(struct node));
    if (list->first == NULL){
        //TODO out of memory
        return 0;
    }
    list->first->elem = elem;
    list->first->next = second;
    list->first->prev = NULL;
    if (second != NULL)
        second->prev = list->first;
    list->size += 1;
    return 0;
}

elemType pop(ddlADT list){

    if (list->first == NULL){
        return NULL;
    }

    elemType aux = list->first->elem;
    TList auxNode = list->first;
    list->first = list->first->next;

    if (list->first != NULL)
        list->first->prev = NULL;

    free(auxNode);
    list->size -= 1;

    return aux;
}
elemType peek(ddlADT list){
    if (list->first == NULL){
        return NULL;
    }
    return list->first->elem;
}