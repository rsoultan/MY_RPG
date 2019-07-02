/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** init_button
*/

#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/RectangleShape.h>
#include "structure.h"

static const sfVector2f size[NB_BUTTON] = {
    {124.f, 43.f},
    {124.f, 43.f},
    {124.f, 43.f},
    {10.f, 10.f},
    {10.f, 10.f},
    {20.f, 20.f},
    {20.f, 20.f},
    {20.f, 20.f},
    {20.f, 20.f},
    {124.f, 43.f},
    {124.f, 43.f},
    {124.f, 43.f},
    {10.f, 10.f},
    {10.f, 10.f},
    {10.f, 10.f},
    {10.f, 10.f},
    {10.f, 10.f},
    {10.f, 10.f},
    {124.f, 43.f},
    {124.f, 43},
    {10.f, 10.f},
    {40.f, 40.f}
};
static const sfIntRect rect_button[NB_BUTTON] = {
    {0.f, 0.f, 124.f, 43.f},
    {0.f, 0.f, 124.f, 43.f},
    {0.f, 0.f, 124.f, 43.f},
    {18.f, 43.f, 9.f, 10.f},
    {9.f, 43.f, 9.f, 10.f},
    {36.f, 43.f, 10.f, 11.f},
    {46.f, 43.f, 11.f, 11.f},
    {36.f, 43.f, 10.f, 11.f},
    {46.f, 43.f, 11.f, 11.f},
    {0.f, 0.f, 124.f, 43.f},
    {0.f, 0.f, 124.f, 43.f},
    {0.f, 0.f, 124.f, 43.f},
    {0.f, 43.f, 9.f, 10.f},
    {0.f, 43.f, 9.f, 10.f},
    {0.f, 43.f, 9.f, 10.f},
    {0.f, 43.f, 9.f, 10.f},
    {0.f, 43.f, 9.f, 10.f},
    {0.f, 43.f, 9.f, 10.f},
    {0.f, 0.f, 124.f, 43.f},
    {0.f, 0.f, 124.f, 43.f},
    {0.f, 43.f, 9.f, 10.f},
    {56.f, 44.f, 9.f, 9.f}
};

int init_button(game_t *game)
{
    for (unsigned short int i = 0; i < NB_BUTTON; ++i) {
        game->button[i].rect_shape = sfRectangleShape_create();
        game->button[i].size = size[i];
        if (!game->button[i].rect_shape)
            return (ERROR);
        sfRectangleShape_setTexture(game->button[i].rect_shape,
            game->spr[SPR_BUTTON].tex, sfFalse);
        sfRectangleShape_setTextureRect(game->button[i].rect_shape,
            rect_button[i]);
        sfRectangleShape_setSize(game->button[i].rect_shape, size[i]);
        sfRectangleShape_setFillColor(game->button[i].rect_shape, sfBlue);
        game->button[i].rect =
            sfRectangleShape_getGlobalBounds(game->button[i].rect_shape);
    }
    return (SUCCESS);
}