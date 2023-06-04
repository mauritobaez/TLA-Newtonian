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
    canvas_t canvas_object = malloc(sizeof(struct canvas_cdt));
    canvas_object->canvas = svg_create();
    canvas_object->max_x = 1;
    canvas_object->max_y = 1;
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
        .rotation = go.rotation
    };
    double hyp = hypot(o.width/2, o.height/2);
    double alpha = atan2(o.width/2, o.height/2);
    point_t topLeft = {
        .x = center.x - hyp * cos((M_PI/2) - alpha - angle),
        .y = center.y - hyp * sin((M_PI/2) - alpha - angle)
    };

    char* color = color_to_svg_color(o.color);

    svg_rectangle(canvas->canvas, o.width, o.height, topLeft.x, topLeft.y, color, "black", 1, 0, 0, go.rotation);
    //TODO: Label
    free(color);
    update_canvas_edges(canvas, (point_t) {.x = center.x + hyp, .y = center.y + hyp});
    update_canvas_edges(canvas, (point_t) {.x = center.x - hyp, .y = center.y - hyp});

    printf("Draw Rectangle: {top: (%d,%d), bottom: (%d,%d), left: (%d,%d), right: (%d,%d), center: (%d,%d), topLeft: (%d,%d)}\n", ans.top.x, ans.top.y, ans.bottom.x, ans.bottom.y, ans.left.x, ans.left.y, ans.right.x, ans.right.y, ans.center.x, ans.center.y, topLeft.x, topLeft.y);
    return ans;
}

object_t draw_car(canvas_t canvas, general_opt go, block_opt o) {
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
        .rotation = go.rotation
    };
    double hyp = hypot(o.width/2, o.height/2);
    double alpha = atan2(o.width/2, o.height/2);
    point_t topLeft = {
        .x = center.x - hyp * cos((M_PI/2) - alpha - angle),
        .y = center.y - hyp * sin((M_PI/2) - alpha - angle)
    };

    char* color = color_to_svg_color(o.color);

    svg_car(canvas->canvas, topLeft.x, topLeft.y, o.width, o.height, color, "gray", go.rotation);
    
    free(color);
    update_canvas_edges(canvas, (point_t) {.x = center.x + hyp, .y = center.y + hyp});
    update_canvas_edges(canvas, (point_t) {.x = center.x - hyp, .y = center.y - hyp});

    printf("Draw Car: {top: (%d,%d), bottom: (%d,%d), left: (%d,%d), right: (%d,%d), center: (%d,%d), topLeft: (%d,%d)}\n", ans.top.x, ans.top.y, ans.bottom.x, ans.bottom.y, ans.left.x, ans.left.y, ans.right.x, ans.right.y, ans.center.x, ans.center.y, topLeft.x, topLeft.y);
    return ans;
}

object_t draw_ball(canvas_t canvas, general_opt go, ball_opt o){
    point_t center;
    double angle = go.rotation * M_PI / 180.0;

    switch(go.draw_from) {
        case f_TOP:
            center.x = go.starting_point.x + (o.radius) * sin(angle);
            center.y = go.starting_point.y + (o.radius) * cos(angle);
            break;
        case f_BOTTOM:
            center.x = go.starting_point.x - (o.radius) * sin(angle);
            center.y = go.starting_point.y - (o.radius) * cos(angle);
            break;
        case f_LEFT:
            center.x = go.starting_point.x + (o.radius) * cos(angle);
            center.y = go.starting_point.y - (o.radius) * sin(angle);
            break;
        case f_RIGHT:
            center.x = go.starting_point.x - (o.radius) * cos(angle);
            center.y = go.starting_point.y + (o.radius) * sin(angle);
            break;
        case f_CENTER:
            center.x = go.starting_point.x;
            center.y = go.starting_point.y;
            break;
        default:
            //TODO:ERROR
        break;
    }

    object_t ans = {
        .top =    { .x = center.x - (o.radius) *  sin(angle), .y = center.y - (o.radius) * cos(angle)},
        .bottom = { .x = center.x + (o.radius) *  sin(angle), .y = center.y + (o.radius) * cos(angle)},
        .right =  { .x = center.x + (o.radius) *  cos(angle), .y = center.y - (o.radius) * sin(angle)},
        .left =   { .x = center.x - (o.radius) *  cos(angle), .y = center.y + (o.radius) * sin(angle)},
        .center = center,
        .rotation = go.rotation
    };

    char* color = color_to_svg_color(o.color);

    svg_circle(canvas->canvas, "black", 1, color, o.radius, center.x, center.y);
    
    //TODO:LABEL

    free(color);
    update_canvas_edges(canvas, (point_t) {.x = center.x + o.radius, .y = center.y + o.radius});
    update_canvas_edges(canvas, (point_t) {.x = center.x - o.radius, .y = center.y - o.radius});
    
    printf("Draw Circle: {top: (%d,%d), bottom: (%d,%d), left: (%d,%d), right: (%d,%d), center: (%d,%d)}\n", ans.top.x, ans.top.y, ans.bottom.x, ans.bottom.y, ans.left.x, ans.left.y, ans.right.x, ans.right.y, ans.center.x, ans.center.y);

    return ans;
}

object_t draw_horizontal_plane(canvas_t canvas, general_opt go, plane_opt opt) {
    point_t center;
    double angle_degrees = go.rotation + opt.angle;
    double angle = (angle_degrees) * M_PI / 180.0;
    switch(go.draw_from) {
        case f_LEFT:
            center.x = go.starting_point.x + (opt.length / 2) * cos(angle);
            center.y = go.starting_point.y - (opt.length / 2) * sin(angle);
            break;
        case f_RIGHT:
            center.x = go.starting_point.x - (opt.length / 2) * cos(angle);
            center.y = go.starting_point.y + (opt.length / 2) * sin(angle);
            break;
        case f_BOTTOM:
            angle += M_PI;
        case f_CENTER:
        case f_TOP:
        default:
            center.x = go.starting_point.x;
            center.y = go.starting_point.y;
            break;
    }

    char* color = color_to_svg_color(opt.color);

    object_t ans = {
        .top =    { .x = center.x, .y = center.y},
        .bottom = { .x = center.x, .y = center.y},
        .right =  { .x = center.x + (opt.length/2) *  cos(angle), .y = center.y - (opt.length/2) * sin(angle)},
        .left =   { .x = center.x - (opt.length/2) *  cos(angle), .y = center.y + (opt.length/2) * sin(angle)},
        .center = center,
        .rotation = angle_degrees
    };
    
    if (opt.visible) {
        if (opt.friction) {
            svg_line(canvas->canvas, color, 1, ans.left.x, ans.left.y, ans.right.x, ans.right.y);
            svg_line_dashed(canvas->canvas, color, 1, ans.left.x, ans.left.y + (go.draw_from==f_BOTTOM ? (-2) : (2)), ans.right.x, ans.right.y + (go.draw_from==f_BOTTOM ? (-2) : (2)), "2,2");
        } else {
            svg_line(canvas->canvas, color, 1, ans.left.x, ans.left.y, ans.right.x, ans.right.y);
        }
    }

    free(color);
    update_canvas_edges(canvas, (point_t) {.x = ans.left.x, .y = ans.left.y });
    update_canvas_edges(canvas, (point_t) {.x = ans.right.x, .y = ans.right.y });

    printf("Draw horizontal plane: { start: (%d, %d), end: (%d, %d) }\n", ans.left.x, ans.left.y, ans.right.x, ans.right.y);
    return ans;
}

object_t draw_vertical_plane(canvas_t canvas, general_opt go, plane_opt opt) {
    point_t center;
    double angle_degrees = go.rotation + opt.angle;
    double angle = (angle_degrees) * M_PI / 180.0;
    // TODO: chequear angulos
    switch(go.draw_from) {
        case f_BOTTOM:
            center.x = go.starting_point.x - (opt.length / 2) * sin(angle);
            center.y = go.starting_point.y - (opt.length / 2) * cos(angle);
            break;
        case f_TOP:
            center.x = go.starting_point.x + (opt.length / 2) * sin(angle);
            center.y = go.starting_point.y + (opt.length / 2) * cos(angle);
            break;
        case f_RIGHT:
            angle += M_PI;
        case f_CENTER:
        case f_LEFT:
        default:
            center.x = go.starting_point.x;
            center.y = go.starting_point.y;
            break;
    }

    char* color = color_to_svg_color(opt.color);

    object_t ans = {
        .left =    { .x = center.x, .y = center.y},
        .right = { .x = center.x, .y = center.y},
        .bottom =  { .x = center.x + (opt.length / 2) * sin(angle), .y = center.y + (opt.length / 2) * cos(angle)},
        .top =   { .x = center.x - (opt.length / 2) * sin(angle), .y = center.y - (opt.length / 2) * cos(angle)},
        .center = center,
        .rotation = angle_degrees
    };
    
    if (opt.visible) {
        if (opt.friction) {
            svg_line(canvas->canvas, color, 1, ans.top.x, ans.top.y, ans.bottom.x, ans.bottom.y);
            svg_line_dashed(canvas->canvas, color, 2, ans.top.x + (go.draw_from==f_RIGHT ? (2) : (-2)), ans.top.y, ans.bottom.x + (go.draw_from==f_RIGHT ? (2) : (-2)), ans.bottom.y, "2,2");
        } else {
            svg_line(canvas->canvas, color, 1, ans.top.x, ans.top.y, ans.bottom.x, ans.bottom.y);
        }
    }

    free(color);
    update_canvas_edges(canvas, (point_t) {.x = ans.top.x, .y = ans.top.y });
    update_canvas_edges(canvas, (point_t) {.x = ans.bottom.x, .y = ans.bottom.y });

    printf("Draw Vertical plane: { start: (%d, %d), end: (%d, %d) }\n", ans.top.x, ans.top.y, ans.bottom.x, ans.bottom.y);
    return ans;
}

object_t draw_arrow(canvas_t canvas, general_opt go, arrow_opt o) {
    point_t start;
    double angle_degrees = go.rotation;

    switch(o.direction) {
        case UP:
            angle_degrees += 90;
            break;
        case LEFT:
            angle_degrees += 180;
            break;
        case DOWN:
            angle_degrees += 270;
            break;
        case NORTH:
            angle_degrees = 90;
            break;
        case EAST:
            angle_degrees = 180;
            break;
        case SOUTH:
            angle_degrees = 270;
            break;
        case WEST:
            angle_degrees = 0;
            break;
        default:
            break;        
    }

    angle_degrees += o.angle;
    
    double angle = angle_degrees * M_PI / 180.0;

    switch(go.draw_from) {
        case f_START:
            start.x = go.starting_point.x;
            start.y = go.starting_point.y;
            break;
        case f_END:
            start.x = go.starting_point.x - (o.length) * cos(angle);
            start.y = go.starting_point.y + (o.length) * sin(angle);
            break;
        default:
            //TODO: error
            break;
    }

    object_t ans = {
        .start = { .x = start.x, .y = start.y },
        .center = { .x = start.x + (o.length / 2) * cos(angle), .y = start.y - (o.length / 2) * sin(angle) },
        .end = { .x = start.x + (o.length) * cos(angle), .y = start.y - (o.length) * sin(angle) },
        .rotation = angle_degrees
    };

    char* color = color_to_svg_color(o.color);

    if(o.double_arrow || o.reverse_arrow)
        svg_arrow(canvas->canvas, color, color, 1, ans.end.x, ans.end.y, ans.start.x, ans.start.y);
    if(o.double_arrow || !o.reverse_arrow)
        svg_arrow(canvas->canvas, color, color, 1, ans.start.x, ans.start.y, ans.end.x, ans.end.y);
    
    free(color);
    update_canvas_edges(canvas, (point_t) {.x = ans.start.x, .y = ans.start.y });
    update_canvas_edges(canvas, (point_t) {.x = ans.end.x, .y = ans.end.y });

    printf("Draw arrow: { start: (%d, %d), end: (%d, %d) }\n", ans.start.x, ans.start.y, ans.end.x, ans.end.y); 
    return ans;
}

object_t draw_spring(canvas_t canvas, general_opt go, rope_opt o) {
    point_t start;    
    double angle = go.rotation * M_PI / 180.0;

    switch(go.draw_from) {
        case f_START:
            start.x = go.starting_point.x;
            start.y = go.starting_point.y;
            break;
        case f_END:
            start.x = go.starting_point.x - (o.length) * cos(angle);
            start.y = go.starting_point.y + (o.length) * sin(angle);
            break;
        default:
            //TODO: error
            break;
    }

    object_t ans = {
        .start = { .x = start.x, .y = start.y },
        .center = { .x = start.x + (o.length / 2) * cos(angle), .y = start.y - (o.length / 2) * sin(angle) },
        .end = { .x = start.x + (o.length) * cos(angle), .y = start.y - (o.length) * sin(angle) },
        .rotation = go.rotation
    };

    char* color = color_to_svg_color(o.color);

    
    int dy = ans.end.y - ans.start.y;
    int dx = ans.end.x - ans.start.x;
    int length = hypot(dx, dy);
    svg_spring(canvas->canvas, color, 1, ans.start.x, ans.start.y, ans.end.x, ans.end.y, 8, length*0.1, length*0.15);
    
    free(color);
    update_canvas_edges(canvas, (point_t) {.x = ans.start.x, .y = ans.start.y });
    update_canvas_edges(canvas, (point_t) {.x = ans.end.x, .y = ans.end.y });

    printf("Draw spring: { start: (%d, %d), end: (%d, %d) }\n", ans.start.x, ans.start.y, ans.end.x, ans.end.y); 
    return ans;
}

object_t draw_rope(canvas_t canvas, general_opt go, rope_opt o) {
    point_t start;    
    double angle = go.rotation * M_PI / 180.0;

    switch(go.draw_from) {
        case f_START:
            start.x = go.starting_point.x;
            start.y = go.starting_point.y;
            break;
        case f_END:
            start.x = go.starting_point.x - (o.length) * cos(angle);
            start.y = go.starting_point.y + (o.length) * sin(angle);
            break;
        default:
            //TODO: error
            break;
    }

    object_t ans = {
        .start = { .x = start.x, .y = start.y },
        .center = { .x = start.x + (o.length / 2) * cos(angle), .y = start.y - (o.length / 2) * sin(angle) },
        .end = { .x = start.x + (o.length) * cos(angle), .y = start.y - (o.length) * sin(angle) },
        .rotation = go.rotation
    };

    char* color = color_to_svg_color(o.color);
    
    int dy = ans.end.y - ans.start.y;
    int dx = ans.end.x - ans.start.x;
    int length = hypot(dx, dy);
    svg_line(canvas->canvas, color, 1, ans.start.x, ans.start.y, ans.end.x, ans.end.y);
    
    free(color);
    update_canvas_edges(canvas, (point_t) {.x = ans.start.x, .y = ans.start.y });
    update_canvas_edges(canvas, (point_t) {.x = ans.end.x, .y = ans.end.y });

    printf("Draw rope: { start: (%d, %d), end: (%d, %d) }\n", ans.start.x, ans.start.y, ans.end.x, ans.end.y); 
    return ans;
}

object_t draw_spacer(canvas_t canvas, general_opt go, spacer_opt o) {
    double angle = go.rotation * M_PI / 180.0;
    point_t start;
    
    switch(go.draw_from) {
        case f_START:
            start.x = go.starting_point.x;
            start.y = go.starting_point.y;
            break;
        case f_END:
            start.x = go.starting_point.x - (o.length) * cos(angle);
            start.y = go.starting_point.y + (o.length) * sin(angle);
            break;
        default:
            //TODO: error
            break;
    }

    object_t ans = {
        .center =  { .x = go.starting_point.x + (o.length /2) * cos(angle), .y = go.starting_point.y - (o.length /2) * sin(angle) },
        .start = start,
        .end = { .x = go.starting_point.x + (o.length) * cos(angle), .y = go.starting_point.y - (o.length) * sin(angle) },
        .rotation = go.rotation
    };

    update_canvas_edges(canvas, ans.start);
    update_canvas_edges(canvas, ans.end);


    printf("Draw spacer: {start: (%d, %d), end: (%d, %d), center: (%d,%d)}\n", ans.start.x, ans.start.y, ans.end.x, ans.end.y, ans.center.x, ans.center.y);
    return ans;
}