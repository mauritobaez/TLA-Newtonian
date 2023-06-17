#ifndef BISON_ACTIONS_HEADER
#define BISON_ACTIONS_HEADER

#include "../../backend/support/logger.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "../../backend/semantic-analysis/abstract-syntax-tree.h"
#include "../../backend/support/shared.h"


/**
 * Se definen las acciones a ejecutar sobre cada regla de producción de la
 * gramática. El objetivo de cada acción debe ser el de construir el nodo
 * adecuado que almacene la información requerida en el árbol de sintaxis
 * abstracta (i.e., el AST).
 */


Program* ProgramAction(Placeable* placeable);

// Función para alignments y objects
Placeable* PlaceableAction(PlaceableHeader* header, anchor_t position, PlaceableList* mainBody);

// Función auxiliar para guardar el tipo y las propiedades de un objeto, el header es deshecho cuando se junta con el body
PlaceableHeader* PlaceableHeaderAction(PlaceableType type, PropertyList* propertiesBody);

// Función utilizada al concatenar todas las properties de una acción
PropertyList* PlaceablePropertyAction(Property* property, PropertyList* propertyList);

// Función la cual le atribuye el valor establecido por el usuario a una property de un objeto
Property* PropertyAction(PropertyType key, void* value);

// Función en la cual se junta el header con lo que está dentro del objeto
PlaceableList* PlaceableBodyAction(Placeable* placeable, PlaceableList* placeableList);

//Tipica funcion free para que no haya memory leaks
void FreeProgram(Program* program);

#endif
