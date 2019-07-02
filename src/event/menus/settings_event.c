/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** settings_event
*/

#include "function.h"
#include "structure.h"

int settings_event(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window.render, &event)) {
        button_event(game, event, CANCEL, &cancel_button);
        button_event(game, event, CONFIRM, &confirm_button);
        fps_button_event(game, event, LOW_FPS, 30);
        fps_button_event(game, event, EPITECH_FPS, 42);
        fps_button_event(game, event, HIGH_FPS, 60);
        global_event(game, event);
    }
    return (SUCCESS);
}