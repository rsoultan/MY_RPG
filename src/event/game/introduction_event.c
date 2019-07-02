/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** introduction_event
*/

#include "structure.h"
#include "macro.h"
#include "function.h"

int introduction_event(game_t *game)
{
    sfEvent evt;

    while (sfRenderWindow_pollEvent(game->window.render, &evt)) {
        if (evt.type == sfEvtKeyPressed) {
            game->scene = MAIN_MENU;
            clear_buffer(game->part.buf, (sfColor){80, 120, 255, 255});
        }
        global_event(game, evt);
    }
    return (SUCCESS);
}