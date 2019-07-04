/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** move_character
*/

#include <SFML/Window/Event.h>
#include <SFML/Graphics/RenderWindow.h>
#include "function.h"
#include "structure.h"

static void step_by_step(game_t *game)
{
    if (game->player.status[MEMSTEP] % 2 == 0)
        game->player.status[STEP] = STAND;
    else if (game->player.status[MEMSTEP] == 1)
        game->player.status[STEP] = STEP_LEFT;
    else
        game->player.status[STEP] = STEP_RIGHT;
}

void manage_player_step(game_t *game)
{
    game->player.status[MEMSTEP]++;
    step_by_step(game);
    if (game->player.status[MEMSTEP] == 4)
        game->player.status[MEMSTEP] = 0;
}

void manage_player_orientation(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight) ||
        sfKeyboard_isKeyPressed(sfKeyD))
        game->player.status[ORIENTATION] = RIGHT;
    if (sfKeyboard_isKeyPressed(sfKeyLeft) ||
        sfKeyboard_isKeyPressed(sfKeyQ))
        game->player.status[ORIENTATION] = LEFT;
    if (sfKeyboard_isKeyPressed(sfKeyUp) ||
        sfKeyboard_isKeyPressed(sfKeyZ))
        game->player.status[ORIENTATION] = UP;
    if (sfKeyboard_isKeyPressed(sfKeyDown) ||
        sfKeyboard_isKeyPressed(sfKeyS))
        game->player.status[ORIENTATION] = DOWN;
}