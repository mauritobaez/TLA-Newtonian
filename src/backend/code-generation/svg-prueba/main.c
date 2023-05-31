
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>

#include"draw.h"


//--------------------------------------------------------
// FUNCTION main
//--------------------------------------------------------
int main(void)
{
    canvas_t canvas = create_canvas();
    if(canvas == NULL)
    {
        puts("canvas is NULL");
        return EXIT_FAILURE;
    }

    general_opt go = {
        .draw_from = f_CENTER,
        .starting_point = {0, 0},
        .rotation = 0,
    };

    block_opt o = {
        .color = {255, 255, 255},
        .height = 1000,
        .width = 1000,
    };

    ball_opt ob = {
        .color = {255, 150, 150},
        .radius = 100,
    };

    draw_block(canvas, go, o);

    object_t block = draw_block(
        canvas, 
        (general_opt) { .draw_from = f_CENTER, .rotation = 10, .starting_point = {0,0}}, 
        (block_opt) {.color={23,243,85}, .height=100, .width=50}
    );

    object_t arr = draw_arrow(
        canvas,
        (general_opt) { .draw_from = f_START, .rotation = 10, .starting_point = {0,0}},
        (arrow_opt) {.color={0,0,0}, .angle= 30, .direction= NORTH, .double_arrow = false, .reverse_arrow = true, .length = 50} 
    );


    draw_spring(
        canvas,
        (general_opt) { .draw_from = f_START, .rotation = arr.rotation, .starting_point = arr.end},
        (rope_opt) {.color={100,100,100}, .length = 100} 
    );

    draw_horizontal_plane(
        canvas,
        (general_opt) { .draw_from = f_RIGHT, .rotation = block.rotation, .starting_point = block.bottom},
        (plane_opt) {.angle = 0, .color = {17, 130, 200}, .friction = true, .length = 200, .visible = true}
    );

    draw_vertical_plane(
        canvas,
        (general_opt) { .draw_from = f_RIGHT, .rotation = block.rotation, .starting_point = block.right},
        (plane_opt) {.angle = 0, .color = {0, 0, 0}, .friction = true, .length = 200, .visible = true}
    );
    
    
    save_canvas(canvas);
    free_canvas(canvas);

    return EXIT_SUCCESS;
}