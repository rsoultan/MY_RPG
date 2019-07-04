/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** how_to_play.c
*/

#include <SFML/Graphics/Texture.h>
#include "structure.h"
#include "function.h"

int event_htp(game_t *game)
{
    sfEvent evt;

    while (sfRenderWindow_pollEvent(game->window.render, &evt)) {
        if (evt.type == sfEvtKeyReleased) {
            ++game->htp_index;
        }
        global_event(game, evt);
    }
    return (0);
}

int display_htp(game_t *game)
{
    if (game->htp_index == NB_HTP_PAGES) {
        game->old_scene = game->scene;
        game->scene = MAIN_MENU;
        game->htp_index = 0;
        return (0);
    }
    sfSprite_setTextureRect(game->spr[HTP_SPR].spr,
        (sfIntRect){1600 * game->htp_index, 0, 1600, 900});
    sfRenderWindow_clear(game->window.render, sfBlack);
    sfRenderWindow_drawSprite(
        game->window.render, game->spr[HTP_SPR].spr, NULL);
    return (0);
}

void htp_button(game_t *game)
{
    game->old_scene = game->scene;
    game->scene = HOW_TO_PLAY;
}