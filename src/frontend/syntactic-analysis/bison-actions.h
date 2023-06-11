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

// Función para alginments y objects
Placeable* PlaceableAction(PlaceableHeader* header, anchor_t position, PlaceableList* mainBody);

//
PlaceableHeader* PlaceableHeaderAction(PlaceableType type, PropertyList* propertiesBody);

// Función para las properties
PropertyList* PlaceablePropertyAction(Property* property, PropertyList* propertyList);
Property* PropertyAction(PropertyType key, void* value);
PlaceableList* PlaceableBodyAction(Placeable* placeable, PlaceableList* placeableList);

void FreeProgram(Program* program);

#endif
