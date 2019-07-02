/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** update_size_window.c
*/

#include "structure.h"
#include "function.h"

void update_button_rect(game_t *game, int index)
{
    game->button[index].rect.top *= game->window.ratio.y;
    game->button[index].rect.left *= game->window.ratio.x;
    game->button[index].rect.height *= game->window.ratio.y;
    game->button[index].rect.width *= game->window.ratio.x;
}

void update_inv_shape_rect(game_t *game, sfFloatRect *rect)
{
    rect->top *= game->window.ratio.y;
    rect->left *= game->window.ratio.x;
    rect->height *= game->window.ratio.y;
    rect->width *= game->window.ratio.x;
}

void update_ratio_window(game_t *game)
{
    sfVector2u win_size = sfRenderWindow_getSize(game->window.render);
    sfVector2u original = {1600, 900};

    game->window.ratio.x = (float)win_size.x / (float)original.x;
    game->window.ratio.y = (float)win_size.y / (float)original.y;
}