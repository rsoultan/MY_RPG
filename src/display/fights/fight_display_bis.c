/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** fight_display_bis.c
*/

#include "structure.h"
#include "function.h"

void display_life(game_t *game)
{
    int i = 0;

    while (i < game->fight[game->cur_fight].life) {
        sfSprite_setScale(game->spr[LIFE].spr, (sfVector2f){1, 1});
        sfSprite_setPosition(game->spr[LIFE].spr,
            (sfVector2f){40 + 104 * i + i * 20, 30});
        sfRenderWindow_drawSprite(game->window.render, game->spr[LIFE].spr,
            NULL);
        ++i;
    }
}