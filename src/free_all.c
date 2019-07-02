/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** free_all
*/

#include <SFML/Graphics/View.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/RenderTexture.h>
#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#include "macro.h"
#include "structure.h"

void free_inventory(inv_t *inv)
{
    if (!inv)
        return;
    for (unsigned short int i = 0; i < NB_SLOT; ++i) {
        if (inv[i].rect_shape)
            sfRectangleShape_destroy(inv[i].rect_shape);
        if (inv[i].spr)
            sfSprite_destroy(inv[i].spr);
    }
}

void free_sprite(sprite_t *spr)
{
    if (!spr)
        return;
    for (unsigned short int i = 0; i < NB_SPRITE; ++i) {
        if (spr[i].spr)
            sfSprite_destroy(spr[i].spr);
        if (spr[i].tex)
            sfTexture_destroy(spr[i].tex);
    }
}

void free_button(button_t *buttons)
{
    if (!buttons)
        return;
    for (unsigned short int i = 0; i < NB_BUTTON; ++i) {
        if (buttons[i].rect_shape)
            sfRectangleShape_destroy(buttons[i].rect_shape);
    }
}

void free_maps(char ****maps)
{
    if (!maps)
        return;
    for (unsigned short int i = 0; i < NB_MAPS_TYPE; ++i) {
        if (!maps[i])
            return;
        for (unsigned short int j = 0; j < NB_MAPS; ++j)
            maps[i][j] ? free_array(maps[i][j]) : 0;
        if (maps[i])
            free(maps[i]);
    }
}

void free_all(game_t *game)
{
    if (!game)
        return;
    free_button(game->button);
    free_sprite(game->spr);
    free_inventory(game->inv);
    free_quest(game->quest);
    free_npc(game->npcs);
    free_fight(game->fight);
    free_audio(game->audio);
    free_ui(game->ui);
    free_time(game->game_time);
    free_text(game->text);
    free_cam(game->cam);
    free_window(game->window);
    free_part(game);
    free_maps(game->maps);
    free(game);
}