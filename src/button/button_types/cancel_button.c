/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** cancel_button
*/

#include "structure.h"
#include "function.h"

static void cancel_settings_button(game_t *game)
{
    game->old_scene = game->scene;
    game->scene = MAIN_MENU;
}

static void cancel_player_creator_button(game_t *game)
{
    game->old_scene = game->scene;
    game->scene = MAIN_MENU;
    switch_music(PLAYER_CREATOR_MUSIC, MAIN_MENU_MUSIC, game);
}

void cancel_button(game_t *game)
{
    switch (game->scene) {
        case PLAYER_CREATOR_SCENE:
            return (cancel_player_creator_button(game));
        case SETTINGS_MENU:
            return (cancel_settings_button(game));
        default:
            break;
    }
}