/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_inventory
*/

#include "structure.h"
#include "function.h"

static bool inventory_is_full(game_t *game)
{
    unsigned int nb_slot_full = 0;

    for (int i = 0; i < NB_SLOT; ++i) {
        if (game->inv[i].item_name != NULL)
            nb_slot_full++;
    }
    if (nb_slot_full == NB_SLOT)
        return (true);
    else
        return (false);
}

static void move_inv(game_t *game, unsigned int index)
{
    index++;
    while (index < NB_SLOT) {
        game->inv[index - 1].item_name = game->inv[index].item_name;
        game->inv[index - 1].nb_item = game->inv[index].nb_item;
        game->inv[index - 1].spr = game->inv[index].spr;
        index++;
    }
}

bool item_is_in_inv(game_t *game, char *name)
{
    for (int i = 0; i < NB_SLOT; ++i) {
        if (my_strcmp(game->inv[i].item_name, name) == 1)
            return (true);
    }
    return (false);
}

void add_item(game_t *game, char *name, sfSprite *spr)
{
    unsigned int index = 0;

    if (inventory_is_full(game) == true)
        return;
    if (item_is_in_inv(game, name) == true) {
        while (my_strcmp(game->inv[index].item_name, name) != 1)
            index++;
    } else {
        while (game->inv[index].item_name != NULL)
            index++;
    }
    game->inv[index].item_name = name;
    game->inv[index].spr = spr;
}

void remove_item(game_t *game, char *name)
{
    unsigned short int index = 0;

    if (item_is_in_inv(game, name) == false)
        return;
    while (my_strcmp(game->inv[index].item_name, name) != 1)
        index++;
    game->inv[index].item_name = NULL;
    game->inv[index].nb_item = 0;
    sfSprite_destroy(game->inv[index].spr);
    move_inv(game, index);
}