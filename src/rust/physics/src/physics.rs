/*
    Este código é responsável pela simulação dos planetas.

    Ele pode estar uma porcaria, já que sou meio iniciante tanto em Rust
    quanto em física.

    Grande parte da matemática foi emprestada no vídeo do YouTube abaixo,
    que também tem um código no GitHub:

    https://www.youtube.com/watch?v=WTLPmUHTPqo
    https://github.com/techwithtim/Python-Planet-Simulation

    O qual foi escrito em Python, mas eu quis escrever em Rust e C.

    O código dele não tem licensa, mas como não estou copiando-o e sim me 
    baseando nele, acho que não tem problema.
*/

use std::os::raw::*;
use std::ptr;

const G: f64 = 6.67428e-11; // Constante gravitacional

// Mesmo struct de cor do Raylib
#[repr(C)]
pub struct Color {
    pub r: u8,
    pub g: u8,
    pub b: u8,
    pub a: u8,
}

// Exclusivo do Rust. NÃO COMPATÍVEL COM O RAYLIB!!
#[repr(C)]
pub struct RVec2 {
    pub x: f64,
    pub y: f64,
}

#[repr(C)]
pub struct Planet {
    pub pos: RVec2,

    pub radius: c_uint,
    pub color: Color,
    pub mass: f64,

    pub vel: RVec2,
}

fn attraction(planet: &Planet, other: &Planet) -> RVec2 {
    let distance_x = other.pos.x - planet.pos.x;
    let distance_y = other.pos.y - planet.pos.y;
    
    let distance_squared = distance_x * distance_x + distance_y * distance_y;
    let distance = distance_squared.sqrt();
    
    let force = G * ((planet.mass * other.mass) / distance_squared); // A equação da Lei da Gravitação Universal.

    /*
        Normaliza os valores. Eu originalmente utilizei seno, cosseno e
        tangente para isto, mas é desnecessário. É só normalizar o vetor
        da distância dos dois corpos.

        Uma rápida olhada no vídeo do Sebastian Lague me fez ver isso.
        https://www.youtube.com/watch?v=7axImc1sxa0
    */

    // Normalização do vetor e multiplicação com a força.
    let force_x = (distance_x / distance) * force; 
    let force_y = (distance_y / distance) * force;

    RVec2 {
        x: force_x,
        y: force_y,
    }
}

pub fn update_position(this: &mut Planet, planets: &[Planet], timestep: f64) {
    let mut total_force: RVec2 = RVec2{
        x: 0.0,
        y: 0.0,
    };

    for planet in planets {
        if ptr::eq(this, planet) { // Vê se o planeta é o mesmo em que a posição está sendo atualizada
            continue;
        }

        let force = attraction(this, planet);

        total_force.x += force.x;
        total_force.y += force.y;
    }

    /*
        F = m.a
    */
    this.vel.x += total_force.x / this.mass * timestep;
    this.vel.y += total_force.y / this.mass * timestep;

    this.pos.x += this.vel.x * timestep;
    this.pos.y += this.vel.y * timestep;
}