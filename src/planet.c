#include "main.h"

#include "planet.h"

static double scale = SCALE;

void set_scale(double new_scale) {
    scale = new_scale;
}

void draw_planet(Planet* planet) {
    const double x = planet->pos.x * scale + SCREEN_WIDTH / 2;
	const double y = planet->pos.y * scale + SCREEN_HEIGHT / 2;

    DrawCircle(x, y, planet->radius, planet->color);
}
