/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** manage_update
*/

#include <SFML/Graphics/RenderWindow.h>
#include "function.h"
#include "structure.h"

void manage_update(game_t *game)
{
    game->window.pos_mouse =
        sfMouse_getPositionRenderWindow(game->window.render);
    sfRenderWindow_display(game->window.render);
    sfRenderWindow_setFramerateLimit(game->window.render, game->window.fps);
}