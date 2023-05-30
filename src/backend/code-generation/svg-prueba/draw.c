#include "draw.h"
#include "svg.h"
#include <malloc.h>

struct canvas_cdt {
    svg* canvas;
    int max_x, max_y;
};

void update_canvas_edges(canvas_t canvas, point_t point) {
    canvas->max_x = abs(point.x) > canvas->max_x ? abs(point.x) : canvas->max_x;
    canvas->max_y = abs(point.y) > canvas->max_y ? abs(point.y) : canvas->max_y;
}

char* color_to_svg_color(color_t color) {
    char* svg_color = (char*)malloc(8 * sizeof(char));
    if (svg_color == NULL) {
        return NULL;
    }
    
    sprintf(svg_color, "#%02X%02X%02X", color.red, color.green, color.blue);
    return svg_color;
}

canvas_t create_canvas() {
    canvas_t canvas_object = calloc(1, sizeof(struct canvas_cdt));
    canvas_object->canvas = svg_create();
    return canvas_object;
}

void free_canvas(canvas_t canvas_object) {
    svg_free(canvas_object->canvas);
    free(canvas_object);
}

void save_canvas(canvas_t canvas_object) {
    int width = 2.5 * (canvas_object->max_x);
    int height = 2.5 * (canvas_object->max_y);
    printf("Canvas Height: %d, Canvas Width: %d\n", height, width);
    svg_finalize(canvas_object->canvas, width, height);
    svg_save(canvas_object->canvas, "image.svg");
}

object_t draw_block(canvas_t canvas, general_opt go, block_opt o) {
    point_t center;
    double angle = go.rotation * M_PI / 180.0;

    switch(go.draw_from) {
        case f_TOP:
            center.x = go.starting_point.x + (o.height / 2) * sin(angle);
            center.y = go.starting_point.y + (o.height / 2) * cos(angle);
            break;
        case f_BOTTOM:
            center.x = go.starting_point.x - (o.height / 2) * sin(angle);
            center.y = go.starting_point.y - (o.height / 2) * cos(angle);
            break;
        case f_LEFT:
            center.x = go.starting_point.x + (o.width / 2) * cos(angle);
            center.y = go.starting_point.y - (o.width / 2) * sin(angle);
            break;
        case f_RIGHT:
            center.x = go.starting_point.x - (o.width / 2) * cos(angle);
            center.y = go.starting_point.y + (o.width / 2) * sin(angle);
            break;
        case f_CENTER:
            center.x = go.starting_point.x;
            center.y = go.starting_point.y;
            break;
        default:
            //TODO: error
            break;
    }

    object_t ans = {
        .center = center,
        .top =    { .x = center.x - (o.height / 2) * sin(angle), .y = center.y - (o.height / 2) * cos(angle)},
        .bottom = { .x = center.x + (o.height / 2) * sin(angle), .y = center.y + (o.height / 2) * cos(angle)},
        .right =  { .x = center.x + (o.width / 2) *  cos(angle), .y = center.y - (o.width / 2)  * sin(angle)},
        .left =   { .x = center.x - (o.width / 2) *  cos(angle), .y = center.y + (o.width / 2)  * sin(angle)},
        .rotation = angle
    };
    double hyp = hypot(o.width/2, o.height/2);
    double alpha = atan2(o.width/2, o.height/2);
    point_t topLeft = {
        .x = center.x - hyp * cos((M_PI/2) - alpha - angle),
        .y = center.y - hyp * sin((M_PI/2) - alpha - angle)
    };

    char* color = color_to_svg_color(o.color);

    svg_rectangle(canvas->canvas, o.width, o.height, topLeft.x, topLeft.y, color, "black", 1, 0, 0, go.rotation);
    
    free(color);
    update_canvas_edges(canvas, (point_t) {.x = center.x + hyp, .y = center.y + hyp});
    update_canvas_edges(canvas, (point_t) {.x = center.x - hyp, .y = center.y - hyp});

    printf("Draw Rectangle: {top: (%d,%d), bottom: (%d,%d), left: (%d,%d), right: (%d,%d), center: (%d,%d), topLeft: (%d,%d)}\n", ans.top.x, ans.top.y, ans.bottom.x, ans.bottom.y, ans.left.x, ans.left.y, ans.right.x, ans.right.y, ans.center.x, ans.center.y, topLeft.x, topLeft.y);
    return ans;
}
