
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>

#include"svg.h"


//--------------------------------------------------------
// FUNCTION main
//--------------------------------------------------------
int main(void)
{
    svg* psvg;
    psvg = svg_create(1024, 1024);
    if(psvg == NULL)
    {
        puts("psvg is NULL");
        return EXIT_FAILURE;
    }

    svg_rectangle(psvg, 400, 400, 0, 0, "white", "black", 2, 0, 0, 0);
    svg_rectangle(psvg, 100, 70, 50, 50, "green", "green", 0, 0, 0, 0);
    svg_car(psvg, 50, 50, 100, 70, "blue", "gray", 0);
    

    svg_finalize(psvg);
    svg_save(psvg, "image.svg");
    svg_free(psvg);

    return EXIT_SUCCESS;
}