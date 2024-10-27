#include "main.h"
#include "solar_system.h"

#include "planet.h"

#define PLANET_AMOUNT 3

static Planet planets[PLANET_AMOUNT];

void solar_system_init(void) {
    Planet sun = create_planet(0, 0, 40, YELLOW, 1.98892 * 1e30);

    Planet mercury = create_planet(0.387 * AU, 0, 8, BROWN, 3.3 * 1e23);
    mercury.vel.y = -47400;

    Planet earth = create_planet(-AU, 0, 20, BLUE, 5.9742 * 1e24);
    earth.vel.y = 29783;
    
    // Armazena os planetas no array
    planets[0] = sun;
    planets[1] = mercury;
    planets[2] = earth;
}

void solar_system_loop(void) {
    for (uint8_t i = 0; i < PLANET_AMOUNT; i++)
        update_planet(&planets[i], planets, PLANET_AMOUNT, TIMESTEP);
}

void solar_system_draw(void) {
    for (uint8_t i = 0; i < PLANET_AMOUNT; i++)
        draw_planet(&planets[i]);
}
