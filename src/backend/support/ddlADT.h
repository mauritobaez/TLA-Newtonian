#ifndef DDLADT_H_
#define DDLADT_H_

#include <stdlib.h>

//Dulce de Leche ADT (DDL) = Double Linked List ADT (DLL)

typedef struct ddlCDT *ddlADT;

typedef enum {
    INVALID_ANGLE,
    INVALID_VALUE,
    REPEATED_PROPERTIES,
    NO_PLACEABLE
} error_warning_type;

typedef struct {
    int linenumber;
    error_warning_type type;
} error_warning;

typedef void *elemType;

// Retorna una lista vacía.
ddlADT newList();

// Agrega un elemento.
int add(ddlADT list, elemType elem);

/* Resetea el iterador que recorre la lista en el orden de inserción */
void toBegin(ddlADT list);

/* Retorna 1 si hay un elemento siguiente en el iterador que
** recorre la lista en el orden de inserción. Sino retorna 0
*/
int hasNext(ddlADT list);

/* Retorna el elemento siguiente del iterador que recorre la lista
** en el orden de inserción.
** Si no hay un elemento siguiente o no se invocó a toBegin aborta la ejecución.
*/
elemType next(ddlADT list);

/*Es necesario llamarlo luego de un next, y borra lo que devuelve dicho next, NO ES POSIBLE
LLARMARLO DOS VECES SEGUIDAS, es necesario realizar un next antes */
void removeDDL(ddlADT list);

/* Libera la memoria reservada por la lista */
void freeList(ddlADT list);

/* Devuelve el elemento a buscar en la lista*/
elemType find(ddlADT list, int(cmpfunction(void *a, void *b)), void *toCmp);

/* Devuelve el tamaño de la lista*/
int getSize(ddlADT list);

/* Agrega un elemento al principio de la lista*/
int push(ddlADT list, elemType elem);

/* Devuelve el primer elemento de la lista y lo borra*/
elemType pop(ddlADT list);

/* Devuelve el primer elemento de la lista*/
elemType peek(ddlADT list);

#endif