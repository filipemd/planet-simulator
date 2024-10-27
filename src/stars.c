#include <raylib.h>

#include "main.h"
#include "stars.h"

static int x[STAR_AMOUNT];
static int y[STAR_AMOUNT];

void create_stars(void) {
    for(unsigned i=0; i < STAR_AMOUNT; i++) {
        x[i] = GetRandomValue(0, swidth);
        y[i] = GetRandomValue(0, sheight);
    }
}

void draw_stars(void) {
    for(unsigned i=0; i < STAR_AMOUNT; i++)
        DrawPixel(x[i], y[i], WHITE);
}
