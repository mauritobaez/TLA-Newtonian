#ifndef NEWTONIAN_TYPES_H
#define NEWTONIAN_TYPES_H

//Valores correspondientes a las posiciones que pueden tomar los objetos si se les asigna una position tag
typedef enum {
  NO_ANCHOR,
  TOP,
  BOTTOM,
  LEFT_SIDE,
  RIGHT_SIDE,
  CENTER
} anchor_t;

//Valores correspondientes a las direcciones que puede tener una flecha
typedef enum {
  UP,
  DOWN,
  LEFT,
  RIGHT,
  NORTH,//Todas estas ultimas son las mismas que las anteriores pero funcionan de forma absoluta sobre la imagen
  SOUTH,
  EAST,
  WEST
} direction_t;

typedef unsigned char byte_t;

//Un struct para guardar los valores RGB que se usaran en el SVG
typedef struct {
  byte_t red;
  byte_t green;
  byte_t blue;
} color_t;

//Simple definicion de boolean
typedef enum {
	false = 0,
	true = 1
} boolean;

#endif