#include "main.h"
#include "main_loop.h"

#include "stars.h"

#include "solar_system.h"
#include "newton_cannon.h"

#include "button.h"

typedef enum {
    SELECT_OPTION,
    SOLAR_SYSTEM,
    NEWTON_CANNON
} Page;

static Page page = SELECT_OPTION;

void start(void) {
    create_stars();

    //solar_system_init();
    //newton_cannon_init();
}

void main_loop(float delta) {
    switch (page) {
        case SOLAR_SYSTEM:
            solar_system_loop();
            break;
        case NEWTON_CANNON:
            newton_cannon_loop();
        default:
            ;
    }
}

void main_draw(void) {
    ClearBackground(BLACK);

    draw_stars();

    switch (page) {
        case SELECT_OPTION: { 
            DrawText("Escolha uma simulação: ", 16, 16, 48, WHITE);
            
            if (Button((Rectangle){10, 96, 480, 48}, "Sistema Solar incompleto.", false)) {
                page = SOLAR_SYSTEM;
                solar_system_init();
            } else if (Button((Rectangle){10, 164, 480, 48}, "Canhão de Newton.", false)) {
                page = NEWTON_CANNON;
                newton_cannon_init();
            }
            break;
        }
        case SOLAR_SYSTEM:
            solar_system_draw();
            break;
        case NEWTON_CANNON:
            newton_cannon_draw();
            break;
    }

    if (GetKeyPressed() == KEY_ESCAPE) {
        page = SELECT_OPTION;
    }
}

void end(void) {
    
}
