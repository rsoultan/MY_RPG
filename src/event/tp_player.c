/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** tp_player
*/

#include "structure.h"
#include "macro.h"

static int check_tp(game_t *game)
{
    for (int i = 0; i < NB_TP; ++i)
        if ((int)game->player.pos.x == (int)game->tp[i].pos.x &&
            (int)game->player.pos.y == (int)game->tp[i].pos.y &&
            game->map_id == game->tp[i].current_id)
            return (i + 1);
    return (0);
}

void tp_player(game_t *game)
{
    int tp = check_tp(game);

    if (tp) {
        game->map_id = game->tp[tp - 1].tp_id;
        game->player.pos.x = game->tp[tp - 1].tp.x;
        game->player.pos.y = game->tp[tp - 1].tp.y;
        game->inputs.pos = game->player.pos;
    }
}