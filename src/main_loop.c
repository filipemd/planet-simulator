#include "main.h"
#include "main_loop.h"

#include "stars.h"

#include "solar_system.h"

void start(void) {
    create_stars();

    solar_system_init();
}

void main_loop(float delta) {
    solar_system_loop();
}

void main_draw(void) {
    ClearBackground(BLACK);

    draw_stars();

    solar_system_draw();
}

void end(void) {
    
}
