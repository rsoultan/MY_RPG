/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** scene_button
*/

#include <SFML/Graphics/RenderWindow.h>
#include "function.h"
#include "structure.h"

void play_button_function(game_t *game)
{
    game->old_scene = game->scene;
    game->scene = PLAYER_CREATOR_SCENE;
    switch_music(MAIN_MENU_MUSIC, PLAYER_CREATOR_MUSIC, game);
}

void settings_button_function(game_t *game)
{
    game->old_scene = game->scene;
    game->scene = SETTINGS_MENU;
}

void resume_button_function(game_t *game)
{
    game->old_scene = game->scene;
    game->scene = GAME_SCENE;
}

void main_menu_button_function(game_t *game)
{
    game->old_scene = game->scene;
    game->scene = MAIN_MENU;
}

void close_game(game_t *game)
{
    sfRenderWindow_close(game->window.render);
}