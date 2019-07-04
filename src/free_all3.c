/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** free_all3
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

void free_part(game_t *game)
{
    if (game->part.logo)
        sfImage_destroy(game->part.logo);
    if (!game->part.entity)
        return;
    if (game->part.entity->spr)
        sfSprite_destroy(game->part.entity->spr);
    if (game->part.entity->tex)
        sfTexture_destroy(game->part.entity->tex);
    free(game->part.entity);
}

void free_window(window_t window)
{
    if (window.render)
        sfRenderWindow_destroy(window.render);
}

void free_cam(cam_t cam)
{
    if (cam.view)
        sfView_destroy(cam.view);
    if (cam.sp)
        sfSprite_destroy(cam.sp);
    if (cam.rt)
        sfRenderTexture_destroy(cam.rt);
}

void free_text(text_t text)
{
    if (text.text)
        sfText_destroy(text.text);
    for (unsigned int i = 0; i < NB_FONT; ++i) {
        if (text.font[i])
            sfFont_destroy(text.font[i]);
    }
}

void free_time(game_time_t time)
{
    if (time.game_clock)
        sfClock_destroy(time.game_clock);
}