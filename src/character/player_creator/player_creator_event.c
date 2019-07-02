/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** credits_event
*/

#include <SFML/Graphics/RenderWindow.h>
#include "function.h"
#include "structure.h"
#include "macro.h"

int player_creator_event(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window.render, &event)) {
        button_event(game, event, CANCEL, &cancel_button);
        button_event(game, event, CONFIRM, &confirm_button);
        button_event(game, event, HAIR_PLUS, &hair_plus);
        button_event(game, event, HAIR_LESS, &hair_less);
        button_event(game, event, SKIN_PLUS, &skin_plus);
        button_event(game, event, SKIN_LESS, &skin_less);
        button_event(game, event, CLOTHES_LESS, &clothes_less);
        button_event(game, event, CLOTHES_PLUS, &clothes_plus);
        manage_player_orientation(game);
        if (event.type == sfEvtKeyReleased && event.key.code == sfKeyW)
            manage_player_step(game);
        global_event(game, event);
    }
    return (SUCCESS);
}