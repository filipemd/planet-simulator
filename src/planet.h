#ifndef PHYSICS_H
#define PHYSICS_H

#include "main.h"

#include <stddef.h>

// Struct do Rust
typedef struct RVec2 {
    double x, y;
} RVec2;

typedef struct Planet {
    RVec2 pos;

    unsigned int radius;
    Color color;
    double mass;

    RVec2 vel;
} Planet;

extern Planet create_planet(double x, double y, unsigned int radius, Color color, double mass); // Função do Rust.
extern void update_planet(Planet *planet, const Planet *planets_raw, size_t planets_len, double timestep); // Outra função do Rust.

void draw_planet(Planet* planet);

#endif
