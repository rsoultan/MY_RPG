/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_inventory
*/

#include <SFML/Graphics/RectangleShape.h>
#include "structure.h"
#include "function.h"

static int init_slot_rect_shape(game_t *game, int i)
{
    game->inv[i].rect_shape = sfRectangleShape_create();

    if (game->inv[i].rect_shape == NULL)
        return (ERROR);
    sfRectangleShape_setSize(game->inv[i].rect_shape, (sfVector2f){80, 80});
    sfRectangleShape_setPosition(game->inv[i].rect_shape,
        (sfVector2f){1530, 220 + (i * 100)});
    sfRectangleShape_setOutlineThickness(game->inv[i].rect_shape, 10);
    return (SUCCESS);
}

int init_inventory(game_t *game)
{
    for (int i = 0; i < NB_SLOT; ++i) {
        game->inv[i].item_name = NULL;
        game->inv[i].spr = NULL;
        if (init_slot_rect_shape(game, i) == 84)
            return (84);
    }
    game->ui.display_inv = true;
    add_item(game, "Carte Etudiante",
        create_inventory_sprite(game->spr[ITEM].spr, EPITECH_CARD));
    add_item(game, "PC",
        create_inventory_sprite(game->spr[ITEM].spr, PC));
    add_item(game, "Chargeur de QUA-LI-TE",
        create_inventory_sprite(game->spr[ITEM].spr, CHARGER));
    return (0);
}