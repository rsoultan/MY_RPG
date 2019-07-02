/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_user_interface
*/

#include <SFML/Graphics/RectangleShape.h>
#include "structure.h"

int init_quest_display(game_t *game)
{
    sfRectangleShape *rect_shape = sfRectangleShape_create();
    sfVector2f position = {1100, 100};

    if (rect_shape == NULL)
        return (ERROR);
    sfRectangleShape_setSize(rect_shape, (sfVector2f){500, 100});
    sfRectangleShape_setFillColor(rect_shape,
        sfColor_fromRGBA(40, 40, 255, 220));
    sfRectangleShape_setPosition(rect_shape, position);
    sfRectangleShape_setOutlineColor(rect_shape, sfBlack);
    sfRectangleShape_setOutlineThickness(rect_shape, 10);
    game->ui.quest = rect_shape;
    game->ui.display_quest = true;
    return (SUCCESS);
}

int init_ui(game_t *game)
{
    if (init_quest_display(game) == ERROR)
        return (ERROR);
    return (SUCCESS);
}