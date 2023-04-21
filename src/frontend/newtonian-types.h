#ifndef NEWTONIAN_TYPES_H
#define NEWTONIAN_TYPES_H

typedef enum {
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

typedef struct {
  char red;
  char green;
  char blue;
} color_t;

typedef char bool_t;

#endif