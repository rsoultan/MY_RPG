/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** init_particles.h
*/

#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/RenderTexture.h>
#include <stdlib.h>
#include <stdio.h>
#include "structure.h"
#include "particles.h"

void display_particles(particles_t *part, window_t *win)
{
    sfTexture_updateFromPixels(part->entity->tex, part->buf, 1600, 900, 0, 0);
    sfRenderWindow_drawSprite(win->render, part->entity->spr, NULL);
}

void display_particles_on_map(particles_t *part, cam_t *cam)
{
    sfTexture_updateFromPixels(part->entity->tex, part->buf, 1600, 900, 0, 0);
    sfRenderTexture_drawSprite(cam->rt, part->entity->spr, NULL);
}

void clear_buffer(sfUint8 *buf, sfColor color)
{
    for (unsigned int i = 0; i < BUF_PART_SIZE * 4; i += 4) {
        buf[i] = color.r;
        buf[i + 1] = color.g;
        buf[i + 2] = color.b;
        buf[i + 3] = color.a;
    }
}

int init_particles(particles_t *part)
{
    part->logo = sfImage_createFromFile("assets/sprites/epimalou_logo.png");
    part->entity = malloc(sizeof(sprite_t));
    if (!part->entity || !part->logo)
        return (ERROR);
    part->entity->tex = sfTexture_create(BUF_PART_W, BUF_PART_H);
    part->entity->spr = sfSprite_create();
    if (!part->entity->tex || !part->entity->spr)
        return (ERROR);
    clear_buffer(part->buf, sfBlack);
    sfTexture_updateFromPixels(part->entity->tex, part->buf,
        BUF_PART_W, BUF_PART_H, 0, 0);
    sfSprite_setTexture(part->entity->spr, part->entity->tex, sfTrue);
    return (SUCCESS);
}

void put_pixel(sfUint8 tab[BUF_PART_SIZE * 4], unsigned i, sfColor color)
{
    tab[i] = color.r;
    tab[i + 1] = color.g;
    tab[i + 2] = color.b;
    tab[i + 3] = color.a;
}