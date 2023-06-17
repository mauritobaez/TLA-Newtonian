#ifndef ABSTRACT_SYNTAX_TREE_HEADER
#define ABSTRACT_SYNTAX_TREE_HEADER

#include "../support/shared.h"
#include "../../frontend/newtonian-types.h"


/**
* Se realiza este tipo de definiciones cuando el tipo de dato debe
* auto-referenciarse, como es el caso de una "Expression", que está compuesta
* de otras 2 expresiones.
*/
typedef struct Placeable Placeable;
typedef struct PlaceableList PlaceableList;
typedef struct PropertyList PropertyList;

/**
* Para cada no-terminal se define una nueva estructura que representa su tipo
* de dato y, por lo tanto, su nodo en el AST (Árbol de Sintaxis Abstracta).
*/
typedef struct {
	int value;
} Constant;

/**
* En caso de que un no-terminal ("Factor" en este caso), posea más de una
* regla de producción asociada, se crea además de la estructura un enumerado
* que identitifque cada reducción posible (cada regla de producción). Luego,
* se agrega una instancia de este enumerado dentro del nodo del no-terminal.
*
* De este modo, al recorrer el AST, es posible determinar qué nodos hijos
* posee según el valor de este enumerado.
*/

typedef enum {
	ROW,
	COLUMN,
	ARROW,
	ROPE,
	SPRING,
	SPACER,
	HORIZONTAL_PLANE,
	VERTICAL_PLANE,
	BLOCK,
	CAR,
	BALL
} PlaceableType;

typedef enum {
	COLOR_PROP,		//color
	DIRECTION,		//direction
	FRICTION,		//boolean
	REVERSE_ARROW,	//boolean
	DOUBLE_ARROW,	//boolean
	VISIBLE,		//boolean
	LABEL,			//string
	ANGLE_LABEL, 	//string
	HEIGHT,			//number
	WIDTH,			//number
	LENGTH,			//number
	RADIUS,			//number
	ANGLE,			//number
} PropertyType;

#define AMOUNT_PROPERTIES 13

typedef union {
	float number;
	direction_t direction;
	color_t color;
	boolean boolean;
	char* string;
} PropertyValue;

//Nodos del AST

struct PlaceableList{
	Placeable* placeable;
	PlaceableList* next;
};

typedef struct {
	PropertyType key;
	PropertyValue value;
} Property;

struct PropertyList{
	Property* property;
	PropertyList* next;
};

struct Placeable{
	PlaceableType type;
	anchor_t position;
	PropertyList* properties;
	PlaceableList* composedPlaceables;
};

typedef struct {
	PlaceableType type;
	PropertyList* properties;
} PlaceableHeader;

typedef struct {
	Placeable * placeable;
} Program;

typedef enum {
    INVALID_ANGLE,
    INVALID_VALUE,
    REPEATED_PROPERTIES,
    NO_PLACEABLE,
    NESTED_ALIGNMENTS
} error_warning_type;

typedef struct {
    int linenumber;
    error_warning_type type;
} error_warning;

typedef enum {
	ERROR,
	WARNING
} problem;

#endif
