
#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

#include"svg.h"

// --------------------------------------------------------
// STATIC FUNCTION appendstringtosvg
// --------------------------------------------------------
static void appendstringtosvg(svg* psvg, char* text)
{
    int l = strlen(psvg->svg) + strlen(text) + 1;
    char* p = realloc(psvg->svg, l);
    if(p)
    {
        psvg->svg = p;
    }
    strcat(psvg->svg, text);
}

// --------------------------------------------------------
// STATIC FUNCTION appendnumbertosvg
// --------------------------------------------------------
static void appendnumbertosvg(svg* psvg, int n)
{
    char sn[16];

    sprintf(sn, "%d", n);

    appendstringtosvg(psvg, sn);
}

// Append rotation to SVG element
static void appendrotationtosvg(svg* psvg, double rotation, int x, int y)
{
    char srotation[64];
    sprintf(srotation, "rotate(%.2f, %d, %d)", -rotation, x, y);
    appendstringtosvg(psvg, " transform='");
    appendstringtosvg(psvg, srotation);
    appendstringtosvg(psvg, "'");
}

static void preppendstringtosvg(svg* psvg, char *text) {
    int l = strlen(psvg->svg) + strlen(text) + 1;
    text = realloc(text, l);    

    if(text)
    {
        strcat(text, psvg->svg);
        free(psvg->svg);
        psvg->svg = text;
    }
}

// --------------------------------------------------------
// FUNCTION svg_create
// --------------------------------------------------------
svg* svg_create()
{
    svg* psvg = malloc(sizeof(svg));

    if(psvg != NULL)
    {
        *psvg = (svg){.svg = NULL, .finalized = false};
        psvg->svg = malloc(2);
        sprintf(psvg->svg, "%s", "\0");
        return psvg;
    }
    else
    {
        return NULL;
    }
}

// --------------------------------------------------------
// FUNCTION svg_finalize
// --------------------------------------------------------
void svg_finalize(svg* psvg, int width, int height)
{
    char* header = malloc(500);
    sprintf(header, "<svg viewBox=\"%d %d %d %d\" xmlns='http://www.w3.org/2000/svg' version='1.1' xmlns:xlink='http://www.w3.org/1999/xlink'>\n", -width/2, -height/2, width, height);
    preppendstringtosvg(psvg, header);
    appendstringtosvg(psvg, "</svg>");

    psvg->finalized = true;
}

// --------------------------------------------------------
// FUNCTION svg_print
// --------------------------------------------------------
void svg_print(svg* psvg)
{
    printf("%s\n", psvg->svg);
}

// --------------------------------------------------------
// FUNCTION svg_save
// --------------------------------------------------------
void svg_save(svg* psvg, char* filepath)
{
    if(!psvg->finalized)
    {
        return;
    }

    FILE* fp;

	fp = fopen(filepath, "w");

	if(fp != NULL)
	{
		fwrite(psvg->svg, 1, strlen(psvg->svg), fp);

		fclose(fp);
	}
}

//----------------------------------------------------------------
// FUNCTION svg_free
//----------------------------------------------------------------
void svg_free(svg* psvg)
{
    free(psvg->svg);

    free(psvg);
}

//----------------------------------------------------------------
// FUNCTION svg_circle
//----------------------------------------------------------------
void svg_circle(svg* psvg, char* stroke, int strokewidth, char* fill, int r, int cx, int cy)
{
    appendstringtosvg(psvg, "    <circle stroke='");
    appendstringtosvg(psvg, stroke);
    appendstringtosvg(psvg, "' stroke-width='");
    appendnumbertosvg(psvg, strokewidth);
    appendstringtosvg(psvg, "px' fill='");
    appendstringtosvg(psvg, fill);
    appendstringtosvg(psvg, "' r='");
    appendnumbertosvg(psvg, r);
    appendstringtosvg(psvg, "' cy='");
    appendnumbertosvg(psvg, cy);
    appendstringtosvg(psvg, "' cx='");
    appendnumbertosvg(psvg, cx);
    appendstringtosvg(psvg, "' />\n");
}

//----------------------------------------------------------------
// FUNCTION svg_line
//----------------------------------------------------------------
void svg_line(svg* psvg, char* stroke, int strokewidth, int x1, int y1, int x2, int y2)
{
    appendstringtosvg(psvg, "    <line stroke='");
    appendstringtosvg(psvg, stroke);
    appendstringtosvg(psvg, "' stroke-width='");
    appendnumbertosvg(psvg, strokewidth);
    appendstringtosvg(psvg, "px' y2='");
    appendnumbertosvg(psvg, y2);
    appendstringtosvg(psvg, "' x2='");
    appendnumbertosvg(psvg, x2);
    appendstringtosvg(psvg, "' y1='");
    appendnumbertosvg(psvg, y1);
    appendstringtosvg(psvg, "' x1='");
    appendnumbertosvg(psvg, x1);
    appendstringtosvg(psvg, "' />\n");
}

void svg_line_dashed(svg* psvg, char* stroke, int strokewidth, int x1, int y1, int x2, int y2, char* dasharray) {
    appendstringtosvg(psvg, "    <line stroke='");
    appendstringtosvg(psvg, stroke);
    appendstringtosvg(psvg, "' stroke-width='");
    appendnumbertosvg(psvg, strokewidth);
    appendstringtosvg(psvg, "px' y2='");
    appendnumbertosvg(psvg, y2);
    appendstringtosvg(psvg, "' x2='");
    appendnumbertosvg(psvg, x2);
    appendstringtosvg(psvg, "' y1='");
    appendnumbertosvg(psvg, y1);
    appendstringtosvg(psvg, "' x1='");
    appendnumbertosvg(psvg, x1);
    appendstringtosvg(psvg, "' stroke-dasharray='");
    appendstringtosvg(psvg, dasharray);
    appendstringtosvg(psvg, "' />\n");
}

//----------------------------------------------------------------
// FUNCTION svg_rectangle
//----------------------------------------------------------------
void svg_rectangle(svg* psvg, int width, int height, int x, int y, char* fill, char* stroke, int strokewidth, int radiusx, int radiusy, double rotation)
{
    appendstringtosvg(psvg, "    <rect fill='");
    appendstringtosvg(psvg, fill);
    appendstringtosvg(psvg, "' stroke='");
    appendstringtosvg(psvg, stroke);
    appendstringtosvg(psvg, "' stroke-width='");
    appendnumbertosvg(psvg, strokewidth);
    appendstringtosvg(psvg, "px' width='");
    appendnumbertosvg(psvg, width);
    appendstringtosvg(psvg, "' height='");
    appendnumbertosvg(psvg, height);
    appendstringtosvg(psvg, "' y='");
    appendnumbertosvg(psvg, y);
    appendstringtosvg(psvg, "' x='");
    appendnumbertosvg(psvg, x);
    appendstringtosvg(psvg, "' ry='");
    appendnumbertosvg(psvg, radiusy);
    appendstringtosvg(psvg, "' rx='");
    appendnumbertosvg(psvg, radiusx);
    appendstringtosvg(psvg, "' \n");
    appendrotationtosvg(psvg, rotation, x, y);
    appendstringtosvg(psvg, " />\n");
}

//----------------------------------------------------------------
// FUNCTION svg_text
//----------------------------------------------------------------
void svg_text(svg* psvg, int x, int y, char* fontfamily, int fontsize, char* fill, char* stroke, char* text, char* text_anchor)
{
    appendstringtosvg(psvg, "    <text x='");
    appendnumbertosvg(psvg, x);
    appendstringtosvg(psvg, "' y = '");
    appendnumbertosvg(psvg, y);
    appendstringtosvg(psvg, "' font-family='");
    appendstringtosvg(psvg, fontfamily);
    appendstringtosvg(psvg, "' stroke='");
    appendstringtosvg(psvg, stroke);
    appendstringtosvg(psvg, "' fill='");
    appendstringtosvg(psvg, fill);
    appendstringtosvg(psvg, "' font-size='");
    appendnumbertosvg(psvg, fontsize);
    appendstringtosvg(psvg, "px' ");
    appendstringtosvg(psvg, " text-anchor='");
    appendstringtosvg(psvg, text_anchor);
    appendstringtosvg(psvg, "' >");
    appendstringtosvg(psvg, text);
    appendstringtosvg(psvg, "</text>\n");
}

//----------------------------------------------------------------
// FUNCTION svg_ellipse
//----------------------------------------------------------------
void svg_ellipse(svg* psvg, int cx, int cy, int rx, int ry, char* fill, char* stroke, int strokewidth, double rotation)
{
    appendstringtosvg(psvg, "    <ellipse cx='");
    appendnumbertosvg(psvg, cx);
    appendstringtosvg(psvg, "' cy='");
    appendnumbertosvg(psvg, cy);
    appendstringtosvg(psvg, "' rx='");
    appendnumbertosvg(psvg, rx);
    appendstringtosvg(psvg, "' ry='");
    appendnumbertosvg(psvg, ry);
    appendstringtosvg(psvg, "' fill='");
    appendstringtosvg(psvg, fill);
    appendstringtosvg(psvg, "' stroke='");
    appendstringtosvg(psvg, stroke);
    appendstringtosvg(psvg, "' stroke-width='");
    appendnumbertosvg(psvg, strokewidth);
    appendstringtosvg(psvg, "' \n");
    appendrotationtosvg(psvg, rotation, cx, cy);
    appendstringtosvg(psvg, " />\n");
}

// --------------------------------------------------------
// FUNCTION svg_triangle
// --------------------------------------------------------
void svg_triangle(svg* psvg, char* fill, char* stroke, int strokewidth, int x1, int y1, int x2, int y2, int x3, int y3)
{
    appendstringtosvg(psvg, "    <polygon fill='");
    appendstringtosvg(psvg, fill);
    appendstringtosvg(psvg, "' stroke='");
    appendstringtosvg(psvg, stroke);
    appendstringtosvg(psvg, "' stroke-width='");
    appendnumbertosvg(psvg, strokewidth);
    appendstringtosvg(psvg, "px' points='");
    appendnumbertosvg(psvg, x1);
    appendstringtosvg(psvg, ",");
    appendnumbertosvg(psvg, y1);
    appendstringtosvg(psvg, " ");
    appendnumbertosvg(psvg, x2);
    appendstringtosvg(psvg, ",");
    appendnumbertosvg(psvg, y2);
    appendstringtosvg(psvg, " ");
    appendnumbertosvg(psvg, x3);
    appendstringtosvg(psvg, ",");
    appendnumbertosvg(psvg, y3);
    appendstringtosvg(psvg, "' />\n");
}

// --------------------------------------------------------
// FUNCTION svg_arrow
// --------------------------------------------------------
void svg_arrow(svg* psvg, char* fill, char* stroke, int strokewidth, int start_x, int start_y, int end_x, int end_y)
{
    int arrow_length = 20; // Length of the arrow tip
    int arrow_width = 8; // Width of the arrow tip

    // Calculate the angle and coordinates for the arrow tip
    double angle = atan2(end_y - start_y, end_x - start_x);
    double tip_x = end_x - arrow_length * cos(angle);
    double tip_y = end_y - arrow_length * sin(angle);

    // Draw the arrow line
    svg_line(psvg, stroke, strokewidth, start_x, start_y, end_x, end_y);

    // Draw the filled triangle as the arrow tip
    svg_triangle(psvg, fill, fill, strokewidth, end_x, end_y,
        tip_x + arrow_width * sin(angle) / 2, tip_y - arrow_width * cos(angle) / 2,
        tip_x - arrow_width * sin(angle) / 2, tip_y + arrow_width * cos(angle) / 2);
}

// --------------------------------------------------------
// FUNCTION svg_spring
// --------------------------------------------------------
void svg_spring(svg* psvg, char* stroke, int strokewidth, int start_x, int start_y, int end_x, int end_y, int num_segments, int amplitude, int straight_segment)
{
    int dx = end_x - start_x;
    int dy = end_y - start_y;
    double segment_length = (hypot(dx, dy) - 2*straight_segment) / num_segments;
    double angle = atan2(dy, dx);
    double first_x, first_y, last_x, last_y, new_x, new_y;
    svg_line(psvg, stroke, strokewidth, start_x, start_y, (first_x = start_x + straight_segment * cos(angle)), (first_y = start_y + straight_segment * sin(angle)));

    last_x = first_x;
    last_y = first_y;

    for (int i = 1; i < num_segments; i++)
    {
        new_x = first_x + i*segment_length*cos(angle);
        new_y = first_y + i*segment_length*sin(angle);

        new_x -= pow(-1, i) * amplitude * sin(angle); 
        new_y += pow(-1, i) * amplitude * cos(angle);

        svg_line(psvg, stroke, strokewidth, last_x, last_y, new_x, new_y);
        last_x = new_x;
        last_y = new_y;
    }
    new_x = end_x - straight_segment * cos(angle);
    new_y = end_y - straight_segment * sin(angle);
    svg_line(psvg, stroke, strokewidth, last_x, last_y, new_x, new_y);

    svg_line(psvg, stroke, strokewidth, new_x, new_y, end_x, end_y);
}

// --------------------------------------------------------
// FUNCTION svg_car
// --------------------------------------------------------
void svg_car(svg* psvg, int x, int y, int width, int height, char* bodyColor, char* wheelColor, double rotation)
{
    int bodyHeight = height * 0.5;
    int roofHeight = height * 0.4;
    int wheelRadius = height * 0.2;
    int wheelX1 = x + width * 0.2;
    int wheelX2 = x + width * 0.8;
    int wheelY = y + roofHeight - height * 0.1 + bodyHeight;
    appendstringtosvg(psvg, "<g ");
    appendrotationtosvg(psvg, rotation, x, y);
    appendstringtosvg(psvg, ">\n");
    // Draw car body
    svg_rectangle(psvg, width, bodyHeight, x, y + roofHeight - (height * 0.1), bodyColor, "none", 0, 10, 10, 0);

    // Draw car roof
    svg_rectangle(psvg, width * 0.6, roofHeight, x + width * 0.2, y, bodyColor, "none", 0, 5, 5, 0);

    // Draw car wheels
    svg_circle(psvg, wheelColor, 0, wheelColor, wheelRadius, wheelX1, wheelY);
    svg_circle(psvg, wheelColor, 0, wheelColor, wheelRadius, wheelX2, wheelY);
    appendstringtosvg(psvg, "</g>\n");
}

// ----------------------------------------------------------
// FUNCTION svg_arc
// ----------------------------------------------------------
void svg_arc(svg* psvg, char* stroke, int stroke_width, int cx, int cy, int r, double angle_start, double angle_end) {
    double angle_start_rad = angle_start * M_PI / 180.0;
    double angle_end_rad = angle_end * M_PI / 180.0;

    int start_x = cx + r * cos(angle_start_rad);
    int start_y = cy - r * sin(angle_start_rad);

    int end_x = cx + r * cos(angle_end_rad);
    int end_y = cy - r * sin(angle_end_rad);

    appendstringtosvg(psvg, "    <path d=' M ");
    appendnumbertosvg(psvg, start_x);
    appendstringtosvg(psvg, " ");
    appendnumbertosvg(psvg, start_y);
    appendstringtosvg(psvg, " A ");
    appendnumbertosvg(psvg, r);
    appendstringtosvg(psvg, " ");
    appendnumbertosvg(psvg, r);
    appendstringtosvg(psvg, " 0");
    appendstringtosvg(psvg, angle_end - angle_start <= 180.0 ? " 0" : " 1");
    appendstringtosvg(psvg, angle_end >= 0.0 ? " 0" : " 1");
    appendnumbertosvg(psvg, end_x);
    appendstringtosvg(psvg, " ");
    appendnumbertosvg(psvg, end_y);
    appendstringtosvg(psvg, "' stroke='");
    appendstringtosvg(psvg, stroke);
    appendstringtosvg(psvg, "' stroke-width='");
    appendnumbertosvg(psvg, stroke_width);
    appendstringtosvg(psvg, "px' fill='transparent' />\n");

}