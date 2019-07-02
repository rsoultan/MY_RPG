/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** init_sprite
*/

#include <SFML/Graphics/Texture.h>
#include <stdlib.h>
#include "structure.h"
#include "macro.h"
#include "function.h"

static const char *name[NB_SPRITE] = {
    "assets/entities/skin.png",
    "assets/entities/clothes.png",
    "assets/entities/hair.png",
    "assets/sprites/textures/tiles.png",
    "assets/sprites/textures/foreground.png",
    "assets/sprites/textures/objects.png",
    "assets/sprites/bg_player_creator.png",
    "assets/sprites/fight_backg.png",
    "assets/button/menu_buttons.png",
    "assets/sprites/talk_bar.png",
    "assets/sprites/merlin_sp.png",
    "assets/sprites/kevin_sp.png",
    "assets/sprites/pollo_sp.png",
    "assets/sprites/chloe_sp.png",
    "assets/sprites/life.png",
    "assets/sprites/item.png",
    "assets/sprites/epitaff_title.png",
    "assets/sprites/htp.png"
};

void setup_talk_bar(game_t *game)
{
    sfVector2f pos = {40, 680};
    sfVector2f size = {5, 5};

    sfSprite_setPosition(game->spr[TALK_BAR].spr, pos);
    sfSprite_setScale(game->spr[TALK_BAR].spr, size);
}

int init_sprite(game_t *game)
{
    for (unsigned short int i = 0; i < NB_SPRITE; ++i) {
        game->spr[i].spr = sfSprite_create();
        game->spr[i].tex = sfTexture_createFromFile(name[i], NULL);
        if (!game->spr[i].spr || !game->spr[i].tex)
            return (ERROR);
        sfSprite_setTexture(game->spr[i].spr, game->spr[i].tex, sfTrue);
    }
    setup_talk_bar(game);
    return (EXIT_SUCCESS);
}