/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_character
*/

#include "macro.h"
#include "structure.h"

void set_character_scale(game_t *game, sfVector2f vector)
{
    sfSprite_setScale(game->spr[0].spr, vector);
    sfSprite_setScale(game->spr[1].spr, vector);
    sfSprite_setScale(game->spr[2].spr, vector);
}

void set_character_pos(game_t *game, sfVector2f vector)
{
    game->player.pos.x = vector.x;
    game->player.pos.y = vector.y;
}

void init_character(game_t *game)
{
    game->player.pos = (sfVector2f){60 * 16, 17 * 16};
    game->player.skin[SKIN] = SKIN_WHITE;
    game->player.skin[CLOTHES] = CLOTHES_RED;
    game->player.skin[HAIR] = BALD;
    game->player.status[ORIENTATION] = DOWN;
    game->player.status[STEP] = STAND;
    game->player.status[MEMSTEP] = STAND;
    game->player.dialogue = -1;
}