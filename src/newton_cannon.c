#include "main.h"
#include "main_loop.h"

#include "newton_cannon.h"

#include "planet.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define PLANET_AMOUNT 2

#define EARTH_RADIUS 6341000.0

Planet earth, cannonball;

void newton_cannon_init(void) {
    earth = create_planet(0, 0, 200, BLUE, 5.9742 * 1e24);

    cannonball = create_planet(0, -EARTH_RADIUS*1.3, 20, DARKGRAY, 300);

    // Escala relativa ao tamanho da Terra de fato.
    set_scale(200.0/EARTH_RADIUS);
}

void newton_cannon_loop(void) {
    const char key = GetCharPressed();
    if (key) {
        cannonball.pos.x = 0;
        cannonball.pos.y = -EARTH_RADIUS*1.3;

        cannonball.vel.y = 0;

        cannonball.vel.x = atoi(&key)*1000;
    }

    const double distance_x = cannonball.pos.x - earth.pos.x;
    const double distance_y = cannonball.pos.y - earth.pos.y;

    // Verifica colisão
    if (sqrt(distance_x*distance_x + distance_y*distance_y) > EARTH_RADIUS*1.1)
        update_planet(&cannonball, &earth, 1, TIMESTEP/1000);
}

void newton_cannon_draw(void) {
    draw_planet(&earth);
    draw_planet(&cannonball);

    DrawText("Aperte números de 1 a 9 de acordo com a força do canhão.", 0, 0, 24, WHITE);
}
