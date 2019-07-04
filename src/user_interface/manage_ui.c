/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** manage_quest_ui
*/

#include <SFML/Graphics/RectangleShape.h>
#include "structure.h"

static void manage_quest_ui(game_t *game)
{
    if (game->ui.display_quest == false &&
        sfRectangleShape_getPosition(game->ui.quest).x < 1620)
        sfRectangleShape_move(game->ui.quest,
            (sfVector2f){10 * game->game_time.fac, 0});
    else if (game->ui.display_quest == true &&
        sfRectangleShape_getPosition(game->ui.quest).x > 1100)
        sfRectangleShape_move(game->ui.quest,
            (sfVector2f){-10 * game->game_time.fac, 0});
    if (sfRectangleShape_getPosition(game->ui.quest).x > 1620)
        sfRectangleShape_setPosition(game->ui.quest,
            (sfVector2f){1620, 100});
    if (sfRectangleShape_getPosition(game->ui.quest).x < 1100)
        sfRectangleShape_setPosition(game->ui.quest,
            (sfVector2f){1100, 100});
}

static void check_inventory_pos(game_t *game, int i)
{
    if (game->ui.display_inv == false &&
        sfRectangleShape_getPosition(game->inv[i].rect_shape).x > 1620)
        sfRectangleShape_setPosition(game->inv[i].rect_shape,
            (sfVector2f){1620, 220 + i * 100});
    else if (game->ui.display_inv == true &&
        sfRectangleShape_getPosition(game->inv[i].rect_shape).x < 1520)
        sfRectangleShape_setPosition(game->inv[i].rect_shape,
            (sfVector2f){1520, 220 + i * 100});
}

static void manage_inventory_ui(game_t *game)
{
    for (int i = 0; i < NB_SLOT; ++i) {
        if (game->ui.display_inv == false &&
            sfRectangleShape_getPosition(game->inv[i].rect_shape).x <= 1620)
            sfRectangleShape_move(game->inv[i].rect_shape,
                (sfVector2f){10 * game->game_time.fac, 0});
        else if (game->ui.display_inv == true &&
            sfRectangleShape_getPosition(game->inv[i].rect_shape).x >= 1520)
            sfRectangleShape_move(game->inv[i].rect_shape,
                (sfVector2f){-10 * game->game_time.fac, 0});
        check_inventory_pos(game, i);
    }
}

void manage_ui(game_t *game)
{
    manage_inventory_ui(game);
    manage_quest_ui(game);
}