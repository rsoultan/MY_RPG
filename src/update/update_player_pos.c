/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** update_player_pos
*/

#include "structure.h"
#include "function.h"

static float absolute(float value)
{
    if (value > 0)
        return (value);
    return (-value);
}

int test_pos(game_t *game, sfVector2f pos, int obj)
{
    if ((absolute(absolute(pos.x) - absolute(game->player.pos.x)) >= obj ||
        absolute(absolute(pos.y) - absolute(game->player.pos.y)) >= obj))
        return (1);
    return (0);
}

void player_movement(game_t *game)
{
    sfVector2f pos = game->inputs.pos;
    static unsigned short int step = 0;

    if (game->inputs.move_mem == 1) {
        game->player.pos.x += game->inputs.move.x * game->game_time.fac;
        game->player.pos.y += game->inputs.move.y * game->game_time.fac;
    }
    if (test_pos(game, pos, 8) && game->inputs.move_mem == 1 && step == 0) {
        manage_player_step(game);
        step = 1;
    }
    if (test_pos(game, pos, 16) && game->inputs.move_mem == 1) {
        game->player.pos = (sfVector2f){game->inputs.move.x * 8 + pos.x,
            game->inputs.move.y * 8 + pos.y};
        step = 0;
        game->inputs.pos = game->player.pos;
        game->inputs.move_mem = 0;
    }
}