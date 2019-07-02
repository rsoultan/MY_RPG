/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** scale_sprite
*/

#include "structure.h"

void scale_sprite(game_t *game)
{
    static sfVector2f big_scale = {20, 20};
    static sfVector2f small_scale = {10, 10};

    for (unsigned short int i = 0; i < NB_SPRITE; ++i) {
        if (game->window.mode.width == 1600)
            sfSprite_setScale(game->spr[i].spr, big_scale);
        else
            sfSprite_setScale(game->spr[i].spr, small_scale);
    }
}