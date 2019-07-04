/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** particles.h
*/

#ifndef PARTICLES_H
    #define PARTICLES_H
    #include <SFML/System/Vector2.h>
    #include <SFML/Graphics/Image.h>
    #define BUF_PART_W 1600
    #define BUF_PART_H 900
    #define BUF_PART_SIZE (BUF_PART_W * BUF_PART_H)

typedef struct s_sprite sprite_t;

typedef struct s_particles {
    sfUint8 buf[BUF_PART_SIZE * 4];
    sprite_t *entity;
    sfImage *logo;
} particles_t;

#endif /* PARTICLES_H */