
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
        .height = 200,
        .width = 200,
    };

    draw_block(canvas, go, o);

    go = (general_opt) {
        .draw_from = f_CENTER,
        .starting_point = {0, 0},
        .rotation = 360,
    };

    o = (block_opt) {
        .color = {255, 255, 0},
        .height = 100,
        .width = 50,
    };

    object_t block = draw_block(canvas, go, o);

    go = (general_opt) {
        .draw_from = f_BOTTOM,
        .starting_point = {block.top.x, block.top.y},
        .rotation = 0,
    };

    o = (block_opt) {
        .color = {0, 255, 0},
        .height = 20,
        .width = 40,
    };

    draw_block(canvas, go, o);

    go = (general_opt) {
        .draw_from = f_CENTER,
        .starting_point = {0, 0},
        .rotation = 0,
    };

    o = (block_opt) {
        .color = {255, 0, 0},
        .height = 5,
        .width = 5,
    };

    draw_block(canvas, go, o);
    
    save_canvas(canvas);
    free_canvas(canvas);

    return EXIT_SUCCESS;
}