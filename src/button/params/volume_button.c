/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** settings_button
*/

#include <SFML/Audio/Sound.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Event.h>
#include "structure.h"
#include "function.h"

static void manage_button_statement(game_t *game, sfFloatRect rect, int i)
{
    if (sfFloatRect_contains(&rect, game->window.pos_mouse.x,
        game->window.pos_mouse.y) == sfTrue)
        sfRectangleShape_setFillColor(game->button[i].rect_shape, sfBlack);
    else
        sfRectangleShape_setFillColor(game->button[i].rect_shape, sfBlue);
}

void volume_button(game_t *game, int i, int music_offset, int sound_offset)
{
    game->button[i].rect =
        sfRectangleShape_getGlobalBounds(game->button[i].rect_shape);
    update_ratio_window(game);
    update_button_rect(game, i);
    manage_button_statement(game, game->button[i].rect, i);
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        sfFloatRect_contains(&game->button[i].rect, game->window.pos_mouse.x,
        game->window.pos_mouse.y) == sfTrue) {
        if ((game->audio.volume_sound == 0 && i == VOLUME_SOUND_LESS) ||
            (game->audio.volume_sound == 100 && i == VOLUME_SOUND_PLUS))
            return;
        game->audio.volume_sound += sound_offset;
        if ((game->audio.volume_music == 0 && i == VOLUME_MUSIC_LESS) ||
            (game->audio.volume_music == 100 && i == VOLUME_MUSIC_PLUS))
            return;
        game->audio.volume_music += music_offset;
        update_music_volume(game);
        update_sound_volume(game);
    }
}