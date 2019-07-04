/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** game_event
*/

#include <SFML/Window/Event.h>
#include <SFML/Graphics/RenderWindow.h>
#include "structure.h"
#include "function.h"
#include "macro.h"

static void switch_display_quest(game_t *game)
{
    game->ui.display_quest = game->ui.display_quest == true ? false : true;
}

static void switch_display_inventory(game_t *game)
{
    game->ui.display_inv = game->ui.display_inv  == true ? false : true;
}

static void manage_switch_display(game_t *game, sfEvent event)
{
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeyH)
        switch_display_quest(game);
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeyI)
        switch_display_inventory(game);
}

int game_event(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window.render, &event)) {
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
            game->old_scene = game->scene;
            game->scene = PAUSE_SCENE;
            change_text_size(game, 30);
            change_text_color(game, sfBlack);
            change_text_font(game, MENU_FONT);
        }
        global_event(game, event);
        manage_switch_display(game, event);
        player_inputs(game, event);
    }
    tp_player(game);
    manage_quest(game);
    for (int i = 0; i < 4; ++i)
        choose_direction(game, i);
    return (SUCCESS);
}