#ifndef NEWTONIAN_TYPES_H
#define NEWTONIAN_TYPES_H

typedef enum {
  NO_ANCHOR,
  TOP,
  BOTTOM,
  LEFT_SIDE,
  RIGHT_SIDE,
  CENTER
} anchor_t;

typedef enum {
  UP,
  DOWN,
  LEFT,
  RIGHT,
  NORTH,
  SOUTH,
  EAST,
  WEST
} direction_t;

typedef unsigned char byte_t;

typedef struct {
  byte_t red;
  byte_t green;
  byte_t blue;
} color_t;

typedef enum {
	false = 0,
	true = 1
} boolean;

#endif