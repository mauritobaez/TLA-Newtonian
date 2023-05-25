#include "../../backend/domain-specific/calculator.h"
#include "../../backend/support/logger.h"
#include "bison-actions.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>

/**
 * Implementación de "bison-grammar.h".
 */

/**
* Esta función se ejecuta cada vez que se emite un error de sintaxis.
*/
void yyerror(const char * string) {
	LogError("Mensaje: '%s' debido a '%s' (linea %d).", string, yytext, yylineno);
	LogError("En ASCII es:");
	LogErrorRaw("\t");
	const int length = strlen(yytext);
	for (int i = 0; i < length; ++i) {
		LogErrorRaw("[%d]", yytext[i]);
	}
	LogErrorRaw("\n\n");
}

/**
* Esta acción se corresponde con el no-terminal que representa el símbolo
* inicial de la gramática, y por ende, es el último en ser ejecutado, lo que
* indica que efectivamente el programa de entrada se pudo generar con esta
* gramática, o lo que es lo mismo, que el programa pertenece al lenguaje.
*/
Program* ProgramAction(Placeable* placeable) {
	/*
	* "state" es una variable global que almacena el estado del compilador,
	* cuyo campo "succeed" indica si la compilación fue o no exitosa, la cual
	* es utilizada en la función "main".
	*/
	state.succeed = true;
	/*
	* Por otro lado, "result" contiene el resultado de aplicar el análisis
	* sintáctico mediante Bison, y almacenar el nood raíz del AST construido
	* en esta variable. Para el ejemplo de la calculadora, no hay AST porque
	* la expresión se computa on-the-fly, y es la razón por la cual esta
	* variable es un simple entero, en lugar de un nodo.
	*/
	Program* program = calloc(1, sizeof(Program));
	program->placeable = placeable;
	state.program = program;
	return program;
}

Placeable* PlaceableAction(PlaceableHeader* header, anchor_t position, PlaceableList* mainBody) {
	Placeable* placeable = calloc(1, sizeof(Placeable));
	placeable->position = position;
	placeable->composedPlaceables = mainBody;
	if(header!=NULL) {
		placeable->type = header->type;
		placeable->properties = header->properties;
		free(header);
	}
	return placeable;
}

PlaceableHeader* PlaceableHeaderAction(PlaceableType type, PropertyList* propertiesBody) {
	PlaceableHeader* header = calloc(1, sizeof(PlaceableHeader));
	header->type = type;
	header->properties = propertiesBody;
	return header;
}

PropertyList* PlaceablePropertyAction(Property* property, PropertyList* propertyList) {
	PropertyList* propertyListNode = calloc(1, sizeof(PropertyList));
	propertyListNode->next = propertyList;
	propertyListNode->property = property;
	return propertyListNode;
}

Property* PropertyAction(PropertyType key, void* value) {
	Property* property = calloc(1, sizeof(Property));
	switch (key) {
		case COLOR_PROP:
			property->value.color = *((color_t*) value);
			break;
		case DIRECTION: 
			property->value.direction = *((direction_t*) value);
			break;
		case FRICTION:
		case REVERSE_ARROW:
		case DOUBLE_ARROW:
		case VISIBLE:
			property->value.boolean = *((boolean*) value);
			break;
		case LABEL:
		case ANGLE_LABEL:
			// quizás deba ser un strncpy
			property->value.string = *((char**) value);
			break;
		case HEIGHT:
		case WIDTH:
		case LENGTH:
		case RADIUS:
		case ANGLE:
			property->value.number = *((float*) value);
			break;
		
	}
	property->key = key;
	return property;
}

PlaceableList* PlaceableBodyAction(Placeable* placeable, PlaceableList* placeableList) {
	PlaceableList* placeableListNode = calloc(1, sizeof(PlaceableList));
	placeableListNode->next = placeableList;
	placeableListNode->placeable = placeable;
	return placeableListNode;
}

void FreePlaceable(Placeable* placeable);
void FreePropertyList(PropertyList* propertyList);
void FreePlaceableList(PlaceableList* placeableList);
void FreeProperty(Property* property);

void FreeProgram(Program* program) {
	if(program->placeable != NULL)
		FreePlaceable(program->placeable);
	free(program);
}

void FreePlaceable(Placeable* placeable) {
	if(placeable->properties != NULL)
		FreePropertyList(placeable->properties);
	if(placeable->composedPlaceables != NULL)
		FreePlaceableList(placeable->composedPlaceables);
	free(placeable);
}

void FreePropertyList(PropertyList* propertyList) {
	if(propertyList->next != NULL)
		FreePropertyList(propertyList->next);
	if(propertyList->property != NULL)
		FreeProperty(propertyList->property);
	free(propertyList);
}

void FreePlaceableList(PlaceableList* placeableList) {
	if(placeableList->next != NULL)
		FreePlaceableList(placeableList->next);
	if(placeableList->placeable != NULL)
		FreePlaceable(placeableList->placeable);
	free(placeableList);
}

void FreeProperty(Property* property) {
	/* TODO: está bien hacer esto? (si es q el malloc esta en flex)
	if((property->key == LABEL || property->key == ANGLE_LABEL) && (property->value.string != NULL)) {
		free(property->value.string);
	}*/
	free(property);
}
