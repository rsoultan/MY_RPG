/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** sprite_inventory
*/

#include "structure.h"

sfSprite *create_inventory_sprite(sfSprite *spr, unsigned short int index)
{
    sfSprite *result = sfSprite_copy(spr);
    sfIntRect rect = {0, index * 80, 80, 80};

    sfSprite_setScale(result, (sfVector2f){1, 1});
    sfSprite_setTextureRect(result, rect);
    if (!result)
        return (NULL);
    return (result);
}