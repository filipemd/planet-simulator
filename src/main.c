#include "main.h"
#include "main_loop.h"

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#include <emscripten/html5.h>
#endif

uint16_t    swidth = SCREEN_WIDTH;
uint16_t    sheight = SCREEN_HEIGHT;

bool close_window;

void loop(void) {
    main_loop(GetFrameTime());

    BeginDrawing();
        main_draw();
    EndDrawing();
}

int main(void) {
    InitWindow(swidth, sheight, "Planet Simulator");

    // Não existe som no espaço
    //InitAudioDevice();

    SetTargetFPS(60);
    SetExitKey(KEY_NULL);

    start();

    #ifdef __EMSCRIPTEN__
    emscripten_set_main_loop(loop, 0, 1);
    #else
    SetTargetFPS(60);
    close_window = false;
    while (!close_window) {
        close_window = WindowShouldClose();

        loop();
    }
    #endif
    end();

    CloseWindow();

    return 0;
}
