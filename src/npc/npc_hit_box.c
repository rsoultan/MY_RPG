/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** npc_hit_box
*/

#include "structure.h"
#include "macro.h"

static int compare_position(game_t *game, int i)
{
    static sfVector2f dir[4] = {
        {0, 16}, {-16, 0}, {0, -16}, {16, 0}
    };

    if (game->npcs[i].pos.x == game->player.pos.x +
        dir[(int)game->player.status[ORIENTATION]].x && game->npcs[i].pos.y ==
        game->player.pos.y + dir[(int)game->player.status[ORIENTATION]].y)
        return (i + 1);
    return (0);
}

int npc_hitbox(game_t *game)
{
    for (int i = 0; i < NB_NPC; ++i) {
        if (game->npcs[i].map == game->map_id && compare_position(game, i))
            return (i + 1);
    }
    return (0);
}