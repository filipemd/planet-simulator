#include "main.h"
#include "main_loop.h"

#include "stars.h"

static unsigned x[STAR_AMOUNT];
static unsigned y[STAR_AMOUNT];

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
