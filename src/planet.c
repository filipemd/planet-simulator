#include "main.h"

#include "planet.h"

void draw_planet(Planet* planet) {
    const double x = planet->pos.x * SCALE + SCREEN_WIDTH / 2;
	const double y = planet->pos.y * SCALE + SCREEN_HEIGHT / 2;

    DrawCircle(x, y, planet->radius, planet->color);
}
