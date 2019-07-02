/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** draw_sprite
*/

#include "structure.h"
#include "enum.h"

void draw_sprite(game_t *game, int index, sfVector2f pos, sfVector2f scale)
{
    sfSprite_setPosition(game->spr[index].spr, pos);
    sfSprite_setScale(game->spr[index].spr, scale);
    sfRenderWindow_drawSprite(game->window.render, game->spr[index].spr,
        NULL);
}