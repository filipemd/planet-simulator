#ifndef MAIN_H
#define MAIN_H

#include <raylib.h>
#include <stdint.h>

#define SCREEN_WIDTH 720
#define SCREEN_HEIGHT 640

uint16_t swidth;
uint16_t sheight;

bool close_window;

#define STAR_AMOUNT 650

#define AU (149.6e6 * 1000)      // 1 AU em metros
#define SCALE (250 / AU)       // Escala em pixels por AU

#define TIMESTEP 3600*12

#endif
