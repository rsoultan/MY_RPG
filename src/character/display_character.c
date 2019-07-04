/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** display_character
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/RenderTexture.h>
#include <stdio.h>
#include "structure.h"
#include "enum.h"
#include "macro.h"
#include "function.h"

static sfIntRect refresh_player_rect(character_t player, unsigned short int i,
    int coef)
{
    sfIntRect rect;

    rect.height = 30;
    rect.left = player.status[ORIENTATION] * 30;
    rect.top = (player.status[STEP] * 30) + player.skin[i] * coef;
    rect.width = 30;
    if (i == 2) {
        rect.left -= 4;
        rect.top = player.skin[i] * coef;
    }
    return (rect);
}

void display_creator_character(game_t *game)
{
    int coef[3] = {90, 90, 30};
    sfVector2f pos = {595, 370};

    for (unsigned short int i = 0; i < 3; ++i) {
        set_character_scale(game, (sfVector2f){15, 15});
        sfSprite_setPosition(game->spr[i].spr, pos);
        sfSprite_setTextureRect(game->spr[i].spr,
        refresh_player_rect(game->player, i, coef[i]));
        sfRenderWindow_drawSprite(game->window.render, game->spr[i].spr,
            NULL);
    }
}

void display_game_character(game_t *game)
{
    int coef[3] = {90, 90, 30};
    sfVector2f pos = {game->player.pos.x - 6, game->player.pos.y - 6};

    for (unsigned short int i = 0; i < 3; ++i) {
        sfSprite_setPosition(game->spr[i].spr, pos);
        sfSprite_setTextureRect(game->spr[i].spr,
        refresh_player_rect(game->player, i, coef[i]));
        sfRenderTexture_drawSprite(game->cam.rt, game->spr[i].spr, NULL);
    }
}