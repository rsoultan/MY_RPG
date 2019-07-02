/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** display_npc
*/

#include <SFML/Graphics/RenderTexture.h>
#include "structure.h"

static sfIntRect refresh_npc_rect(character_t player, unsigned short int i,
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

void display_npc(game_t *game, int j, sfVector2f pos)
{
    int coef[3] = {90, 90, 30};
    character_t skin = game->npcs[j].skin;

    skin.status[ORIENTATION] = DOWN;
    for (unsigned short int i = 0; i < 3; ++i) {
        sfSprite_setPosition(game->spr[i].spr, pos);
        if (game->scene == GAME_SCENE) {
            sfSprite_setScale(game->spr[i].spr, (sfVector2f){1, 1});
            sfSprite_setTextureRect(game->spr[i].spr,
                refresh_npc_rect(game->npcs[j].skin, i, coef[i]));
            sfRenderTexture_drawSprite(game->cam.rt, game->spr[i].spr, NULL);
        }
        else if (game->scene == FIGHT_SCENE) {
            sfSprite_setScale(game->spr[i].spr, (sfVector2f){20, 20});
            sfRenderWindow_drawSprite(game->window.render, game->spr[i].spr,
                NULL);
            sfSprite_setTextureRect(game->spr[i].spr,
                refresh_npc_rect(skin, i, coef[i]));
        }
    }
}

void display_map_npc(game_t *game, int y)
{
    for (int i = 0; i < NB_NPC; ++i) {
        if (game->npcs[i].map == game->map_id && y * 16 == game->npcs[i].pos.y)
            display_npc(game, i, (sfVector2f){game->npcs[i].pos.x - 6,
                game->npcs[i].pos.y - 6});
    }
}