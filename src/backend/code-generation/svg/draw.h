#ifndef DRAW_HEADER
#define DRAW_HEADER

#include "../../../frontend/newtonian-types.h"

typedef enum {
    f_TOP,
    f_BOTTOM,
    f_LEFT,
    f_RIGHT,
    f_CENTER,
    f_START,
    f_END
} from_t;

typedef struct {
    int x;
    int y;
} point_t;

typedef struct {
    point_t starting_point;
    from_t draw_from;
    float rotation;
} general_opt;

typedef struct {
    color_t color;
    char* label;
    int width;
    int height;
} block_opt;

typedef struct {
    int radius;
    color_t color;
    char *label;
} ball_opt;

typedef struct {
    char *angle_label;
    char *label;
    int length;
    boolean friction;
    color_t color;
    boolean visible;
    float angle;
} plane_opt;

typedef struct {
    color_t color;
    char *label;
    direction_t direction;
    float angle;
    char * angle_label;
    int length;
    boolean reverse_arrow;
    boolean double_arrow;
} arrow_opt;

typedef struct {
    color_t color;
    char *label;
    int length;
} rope_opt;

typedef struct {
    int length;
} spacer_opt;

typedef struct {
    point_t top, bottom, left, right, center, start, end;
    float rotation;
} object_t;

typedef struct canvas_cdt* canvas_t;
canvas_t create_canvas();
void free_canvas(canvas_t canvas);
void save_canvas(canvas_t canvas);

object_t draw_block(canvas_t canvas, general_opt general_options, block_opt options);
object_t draw_car(canvas_t canvas, general_opt general_options, block_opt options);
object_t draw_ball(canvas_t canvas, general_opt general_options, ball_opt options);
object_t draw_horizontal_plane(canvas_t canvas, general_opt general_options, plane_opt options);
object_t draw_vertical_plane(canvas_t canvas, general_opt general_options, plane_opt options);
object_t draw_arrow(canvas_t canvas, general_opt general_options, arrow_opt options);
object_t draw_spring(canvas_t canvas, general_opt general_options, rope_opt options);
object_t draw_rope(canvas_t canvas, general_opt general_options, rope_opt options);
object_t draw_spacer(canvas_t canvas, general_opt general_options, spacer_opt options);

#endif