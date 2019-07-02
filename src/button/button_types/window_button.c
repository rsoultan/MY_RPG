/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** window_button
*/

#include "structure.h"

void small_window(game_t *game)
{
    game->window.mode.width = 800;
    game->window.mode.height = 600;
}

void high_window(game_t *game)
{
    game->window.mode.width = 1600;
    game->window.mode.height = 900;
}