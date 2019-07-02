/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** main_menu_event
*/

#include <SFML/Window/Event.h>
#include <SFML/Graphics/RenderWindow.h>
#include "function.h"
#include "structure.h"
#include "macro.h"

int main_menu_event(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window.render, &event)) {
        button_event(game, event, PLAY, &play_button_function);
        button_event(game, event, SETTINGS, &settings_button_function);
        button_event(game, event, QUIT, &close_game);
        button_event(game, event, HOW_TO_PLAY_BUTTON, &htp_button);
        global_event(game, event);
    }
    return (SUCCESS);
}