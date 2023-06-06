#ifndef SVG_HEADER
#define SVG_HEADER
#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include<math.h>

// --------------------------------------------------------
// STRUCT svg
// --------------------------------------------------------
typedef struct svg
{
    char* svg;
    bool finalized;
} svg;

// --------------------------------------------------------
// FUNCTION PROTOTYPES
// --------------------------------------------------------
svg* svg_create();
void svg_finalize(svg* psvg, int width, int height);
void svg_print(svg* psvg);
void svg_save(svg* psvg, char* filepath);
void svg_free(svg* psvg);


void svg_circle(svg* psvg, char* stroke, int strokewidth, char* fill, int r, int cx, int cy);
void svg_line(svg* psvg, char* stroke, int strokewidth, int x1, int y1, int x2, int y2);
void svg_rectangle(svg* psvg, int width, int height, int x, int y, char* fill, char* stroke, int strokewidth, int radiusx, int radiusy, double rotation);
void svg_text(svg* psvg, int x, int y, char* fontfamily, int fontsize, char* fill, char* stroke, char* text, char* text_anchor);
void svg_ellipse(svg* psvg, int cx, int cy, int rx, int ry, char* fill, char* stroke, int strokewidth, double rotation);
void svg_triangle(svg* psvg, char* fill, char* stroke, int strokewidth, int x1, int y1, int x2, int y2, int x3, int y3);
void svg_arrow(svg* psvg, char* fill, char* stroke, int strokewidth, int start_x, int start_y, int end_x, int end_y);
void svg_spring(svg* psvg, char* stroke, int strokewidth, int start_x, int start_y, int end_x, int end_y, int num_segments, int amplitude, int straight_segment);
void svg_car(svg* psvg, int x, int y, int width, int height, char* bodyColor, char* wheelColor, double rotation);
void svg_line_dashed(svg* psvg, char* stroke, int strokewidth, int x1, int y1, int x2, int y2, char* dasharray);
void svg_arc(svg* psvg, char* stroke, int stroke_width, int cx, int cy, int r, double angle_start, double angle_end);
#endif