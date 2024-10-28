#include "main.h"
#include "main_loop.h"

#include "stars.h"

#include "solar_system.h"
#include "newton_cannon.h"

void start(void) {
    create_stars();

    //solar_system_init();
    newton_cannon_init();
}

void main_loop(float delta) {
    //solar_system_loop();
    newton_cannon_loop();
}

void main_draw(void) {
    ClearBackground(BLACK);

    draw_stars();

    //solar_system_draw();
    newton_cannon_draw();
}

void end(void) {
    
}
