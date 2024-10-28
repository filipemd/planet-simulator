#ifndef MAIN_H
#define MAIN_H

#ifdef __EMSCRIPTEN__
#include "raylib.h"
#else
#include <raylib.h>
#endif

#include <stdint.h>

#define SCREEN_WIDTH 720
#define SCREEN_HEIGHT 640

extern uint16_t swidth;
extern uint16_t sheight;

extern bool close_window;

#define STAR_AMOUNT 650

#define AU (149.6e6 * 1000)      // 1 AU em metros
#define SCALE (250 / AU)       // Escala em pixels por AU

#define TIMESTEP 3600*12

#endif
