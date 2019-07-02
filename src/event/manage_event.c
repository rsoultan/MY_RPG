/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** manage_event
*/

#include <SFML/Graphics/RenderWindow.h>
#include "function.h"
#include "structure.h"
#include "macro.h"

static const scene_t scene[NB_SCENE] = {
    {introduction_event, INTRODUCTION}, {event_htp, HOW_TO_PLAY},
    {main_menu_event, MAIN_MENU},
    {settings_event, SETTINGS_MENU},
    {player_creator_event, PLAYER_CREATOR_SCENE},
    {game_event, GAME_SCENE}, {fight_event, FIGHT_SCENE},
    {pause_event, PAUSE_SCENE}
};

void global_event(game_t *game, sfEvent evt)
{
    if (evt.type == sfEvtClosed)
        sfRenderWindow_close(game->window.render);
}

void manage_event(game_t *game)
{
    for (unsigned short int i = 0; i < NB_SCENE; ++i) {
        if (scene[i].index == game->scene)
            scene[i].ptr(game);
    }
    time_forward(game);
}