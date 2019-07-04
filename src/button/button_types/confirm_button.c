/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** confirm_button
*/

#include "structure.h"
#include "function.h"

static void confirm_settings_button(game_t *game)
{
    if (game->old_scene == PAUSE_SCENE)
        game->scene = PAUSE_SCENE;
    else
        game->scene = MAIN_MENU;
    game->old_scene = SETTINGS_MENU;
}

static void confirm_player_creator_button(game_t *game)
{
    set_character_scale(game, (sfVector2f){1, 1});
    game->old_scene = game->scene;
    game->scene = GAME_SCENE;
    switch_music(PLAYER_CREATOR_MUSIC, EPITECH_MUSIC, game);
    game->audio.game_music = EPITECH_MUSIC;
    game->inputs.pos = game->player.pos;
    game->player.status[STEP] = STAND;
}

void confirm_button(game_t *game)
{
    void(*ptr[])(game_t *game) = {
        confirm_settings_button,
        confirm_player_creator_button
    };

    switch (game->scene) {
        case SETTINGS_MENU:
            return (ptr[0](game));
        case PLAYER_CREATOR_SCENE:
            return (ptr[1](game));
        default:
            break;
    }
}