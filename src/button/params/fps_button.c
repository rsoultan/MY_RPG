/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** fps_button
*/

#include <SFML/Audio/Sound.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Event.h>
#include "structure.h"
#include "function.h"

static void fps_already_set(game_t *game, int i)
{
    if (i == LOW_FPS && game->window.fps == 30)
        sfRectangleShape_setFillColor(game->button[i].rect_shape, sfGreen);
    if (i == EPITECH_FPS && game->window.fps == 42)
        sfRectangleShape_setFillColor(game->button[i].rect_shape, sfGreen);
    if (i == HIGH_FPS && game->window.fps == 60)
        sfRectangleShape_setFillColor(game->button[i].rect_shape, sfGreen);
}

static void check_focus_fps_button(game_t *game, sfFloatRect rect, int i)
{
    sfColor color = sfRectangleShape_getFillColor(game->button[i].rect_shape);

    if (sfFloatRect_contains(&rect, game->window.pos_mouse.x,
        game->window.pos_mouse.y) == sfTrue) {
        sfRectangleShape_setFillColor(game->button[i].rect_shape, sfYellow);
        if (color.r != 0 && color.g != 0 && color.b != 0)
            play_sound(game, SELECTED_BUTTON_SOUND);
    } else
        sfRectangleShape_setFillColor(game->button[i].rect_shape, sfBlue);
}

static void pressed_button(game_t *game, int i)
{
    sfRectangleShape_setFillColor(game->button[i].rect_shape, sfRed);
    play_sound(game, CLICKED_BUTTON_SOUND);
}

void fps_button_event(game_t *game, sfEvent event, int i, unsigned int fps)
{
    game->button[i].rect =
        sfRectangleShape_getGlobalBounds(game->button[i].rect_shape);
    update_ratio_window(game);
    update_button_rect(game, i);
    check_focus_fps_button(game, game->button[i].rect, i);
    fps_already_set(game, i);
    if (event.mouseButton.type == sfEvtMouseButtonPressed &&
        sfFloatRect_contains(&game->button[i].rect, game->window.pos_mouse.x,
        game->window.pos_mouse.y) == sfTrue)
        pressed_button(game, i);
    if (event.mouseButton.type == sfEvtMouseButtonReleased &&
        sfFloatRect_contains(&game->button[i].rect, game->window.pos_mouse.x,
        game->window.pos_mouse.y) == sfTrue)
        game->window.fps = fps;
}