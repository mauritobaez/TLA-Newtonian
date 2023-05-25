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
	POSITION,
	FRICTION,
	COLOR_VALUE,
	LABEL,
	DIRECTION,
	ANGLE,
	ANGLE_LABEL,
	HEIGHT,
	WIDTH,
	LENGTH,
	REVERSE_ARROW,
	DOUBLE_ARROW,
	RADIUS,
	VISIBLE
} PropertyType;

typedef union {
	float number;
	anchor_t anchor;
	direction_t direction;
	color_t color;
	boolean boolean;
	char* string;
} PropertyValue;

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
	boolean isPositionless;
	PropertyList* properties;
	PlaceableList* composedPlaceables;
};

typedef struct {
	Placeable * placeable;
} Program;

#endif
