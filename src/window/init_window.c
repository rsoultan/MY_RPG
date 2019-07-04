/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** window
*/

#include <SFML/Graphics/RenderWindow.h>
#include <stddef.h>
#include <stdio.h>
#include "macro.h"
#include "structure.h"

int init_window(game_t *game)
{
    sfVideoMode mode = {1600, 900, 32};

    game->window.mode = mode;
    game->window.ratio.x = 1;
    game->window.ratio.y = 1;
    game->window.render = sfRenderWindow_create(game->window.mode, "Epi'Taff",
        sfResize | sfClose, NULL);
    if (!game->window.render)
        return (ERROR);
    sfRenderWindow_setVerticalSyncEnabled(game->window.render, sfTrue);
    return (SUCCESS);
}