/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** pause_event
*/

#include <SFML/Window/Event.h>
#include "structure.h"
#include "macro.h"
#include "function.h"

int pause_event(game_t *game)
{
    sfEvent evt;

    while (sfRenderWindow_pollEvent(game->window.render, &evt)) {
        if (evt.type == sfEvtKeyPressed && evt.key.code == sfKeyEscape) {
            game->old_scene = game->scene;
            game->scene = GAME_SCENE;
        }
        button_event(game, evt, SETTINGS, &settings_button_function);
        button_event(game, evt, RESUME, &resume_button_function);
        button_event(game, evt, MENU_BUTTON, &main_menu_button_function);
        button_event(game, evt, QUIT, &close_game);
        global_event(game, evt);
    }
    return (SUCCESS);
}