/*
    Este código é apenas responsável por ser compatível com C, ou seja: a
    parte chata. Veja physics.rs.
*/
pub mod physics;

use std::os::raw::*;

use crate::physics::*;

#[no_mangle]
pub extern "C" fn create_planet(x: f64, y: f64, radius: c_uint, color: Color, mass: f64) -> Planet {
    Planet {
        pos: RVec2 {
            x,
            y,
        },
        radius,
        color,
        mass,
        vel: RVec2 {
            x: 0.0,
            y: 0.0
        },
    }
}

#[no_mangle]
pub extern "C" fn update_planet(planet: &mut Planet, planets_raw: *const Planet, planets_len: usize, timestep: f64) {
    // Converte o ponteiro C para um slice Rust
    let planets: &[Planet] = unsafe {
        assert!(!planets_raw.is_null(), "NULL POINTER!!"); // Verifica se o ponteiro não é nulo
        std::slice::from_raw_parts(planets_raw, planets_len) // Cria o slice seguro
    };

    update_position(planet, planets, timestep);
}