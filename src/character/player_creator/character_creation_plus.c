/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** character_creation_plus
*/

#include "structure.h"

void skin_plus(game_t *game)
{
    ++game->player.skin[SKIN];
    if (game->player.skin[SKIN] == SKIN_NB)
        game->player.skin[SKIN] = 0;
}

void hair_plus(game_t *game)
{
    ++game->player.skin[HAIR];
    if (game->player.skin[HAIR] == HAIR_NB)
        game->player.skin[HAIR] = 0;
}

void clothes_plus(game_t *game)
{
    ++game->player.skin[CLOTHES];
    if (game->player.skin[CLOTHES] == CLOTHES_NB)
        game->player.skin[CLOTHES] = 0;
}