/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** display_inventory
*/

#include <SFML/Graphics/RectangleShape.h>
#include "structure.h"
#include "function.h"

static void draw_rect_shape(game_t *game)
{
    for (unsigned short int i = 0; i < NB_SLOT; ++i) {
        sfRenderWindow_drawRectangleShape(game->window.render,
            game->inv[i].rect_shape, NULL);
        if (game->inv[i].spr != NULL) {
            sfSprite_setPosition(game->inv[i].spr,
                sfRectangleShape_getPosition(game->inv[i].rect_shape));
            sfRenderWindow_drawSprite(game->window.render,
                game->inv[i].spr, NULL);
        }
    }
}

static void draw_info_slot(game_t *game, int i)
{
    sfVector2f pos = sfRectangleShape_getPosition(game->inv[i].rect_shape);

    pos.x -= 50 + (12 * my_strlen(game->inv[i].item_name));
    pos.y += 18;
    display_text(game, game->inv[i].item_name, pos);
}

static void draw_slot(game_t *game)
{
    sfFloatRect rect;

    for (unsigned short int i = 0; i < NB_SLOT; ++i) {
        rect = sfRectangleShape_getGlobalBounds(game->inv[i].rect_shape);
        update_ratio_window(game);
        update_inv_shape_rect(game, &rect);
        if (sfFloatRect_contains(&rect, game->window.pos_mouse.x,
            game->window.pos_mouse.y) == sfTrue) {
            sfRectangleShape_setOutlineColor(game->inv[i].rect_shape, sfBlack);
            sfRectangleShape_setFillColor(game->inv[i].rect_shape,
                sfColor_fromRGBA(120, 255, 120, 220));
            draw_info_slot(game, i);
        } else {
            sfRectangleShape_setOutlineColor(game->inv[i].rect_shape, sfBlack);
            sfRectangleShape_setFillColor(game->inv[i].rect_shape, sfWhite);
        }
    }
}

void display_inventory(game_t *game)
{
    draw_rect_shape(game);
    draw_slot(game);
}