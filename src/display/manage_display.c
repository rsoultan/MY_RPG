/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** manage_display
*/

#include <SFML/Graphics/RenderWindow.h>
#include <stdio.h>
#include "structure.h"
#include "function.h"
#include "macro.h"

static const scene_t scene[NB_SCENE] = {
    {introduction_display, INTRODUCTION},
    {display_htp, HOW_TO_PLAY}, {main_menu_display, MAIN_MENU},
    {settings_display, SETTINGS_MENU},
    {display_player_creator, PLAYER_CREATOR_SCENE},
    {game_display, GAME_SCENE}, {fight_display, FIGHT_SCENE},
    {pause_display, PAUSE_SCENE}
};

void manage_display(game_t *game)
{
    for (unsigned short int i = 0; i < NB_SCENE; ++i) {
        if (scene[i].index == game->scene)
            scene[i].ptr(game);
    }
}