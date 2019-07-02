/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** init_game_time
*/

#include <SFML/System/Clock.h>
#include <SFML/Audio/Sound.h>
#include "structure.h"
#include "macro.h"
#include "function.h"

int init_game_time(game_t *game)
{
    game->game_time.game_clock = sfClock_create();
    if (!game->game_time.game_clock)
        return (ERROR);
    game->game_time.seconds = 0;
    return (SUCCESS);
}

void fight_time(game_t *game)
{
    int i = game->cur_fight;

    game->fight[i].time += 0.02 * game->game_time.fac;
    if (game->fight[i].time >= 0.65) {
        game->fight[i].life--;
        game->fight[i].time = 0;
        game->fight[i].i++;
        game->fight[i].key = '5';
        sfSound_play(game->audio.sound[OOF]);
    }
}

void time_loop(game_t *game)
{
    if (game->scene == GAME_SCENE) {
        player_movement(game);
        manage_ui(game);
    }
    if (game->scene == FIGHT_SCENE && game->fight[game->cur_fight].phase == 1)
        fight_time(game);
    if (game->scene == 0)
        intro_update(game);
    if (game->scene == MAIN_MENU || game->scene == SETTINGS_MENU ||
        game->scene == PAUSE_SCENE)
        menu_bg_part_update(game);
}

void time_forward(game_t *game)
{
    game->game_time.time = sfClock_getElapsedTime(game->game_time.game_clock);
    game->game_time.seconds = game->game_time.time.microseconds / 1000000.0;
    if (game->game_time.seconds >= (float)0.02) {
        game->game_time.fac = (float)(1 * (game->game_time.seconds / 0.02));
        time_loop(game);
        sfClock_restart(game->game_time.game_clock);
        game->game_time.seconds = 0;
    }
}