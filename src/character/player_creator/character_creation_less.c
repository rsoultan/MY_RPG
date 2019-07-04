/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** update_player
*/

#include <SFML/Window/Event.h>
#include "structure.h"

void skin_less(game_t *game)
{
    game->player.skin[SKIN]--;
    if (game->player.skin[SKIN] == -1)
        game->player.skin[SKIN] = SKIN_NB - 1;
}

void hair_less(game_t *game)
{
    game->player.skin[HAIR]--;
    if (game->player.skin[HAIR] == -1)
        game->player.skin[HAIR] = HAIR_NB - 1;
}

void clothes_less(game_t *game)
{
    game->player.skin[CLOTHES]--;
    if (game->player.skin[CLOTHES] == -1)
        game->player.skin[CLOTHES] = CLOTHES_NB - 1;
}