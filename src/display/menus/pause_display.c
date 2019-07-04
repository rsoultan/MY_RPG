/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** pause_display
*/

#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/View.h>
#include <stdio.h>
#include "structure.h"
#include "macro.h"
#include "function.h"

static void set_pause_text_parameter(game_t *game)
{
    sfText_setCharacterSize(game->text.text, 30);
    sfText_setOutlineThickness(game->text.text, 0);
    sfText_setStyle(game->text.text, sfTextRegular);
    change_text_font(game, MENU_FONT);
}

int pause_display(game_t *game)
{
    sfRenderWindow_clear(game->window.render, (sfColor){80, 120, 255, 255});
    sfRenderWindow_setView(game->window.render,
        sfRenderWindow_getDefaultView(game->window.render));
    time_forward(game);
    display_particles(&game->part, &game->window);
    set_pause_text_parameter(game);
    draw_button(game, (sfVector2f){600, 150},(sfVector2f){3, 3}, RESUME);
    draw_button(game, (sfVector2f){600, 300}, (sfVector2f){3, 3}, SETTINGS);
    draw_button(game, (sfVector2f){600, 450}, (sfVector2f){3, 3},
        MENU_BUTTON);
    draw_button(game, (sfVector2f){600, 600}, (sfVector2f){3, 3}, QUIT);
    display_text(game, "CONTINUER", (sfVector2f){630.f, 177.f});
    display_text(game, "OPTIONS", (sfVector2f){660.f, 327.f});
    display_text(game, "MENU", (sfVector2f){700.f, 477.f});
    display_text(game, "QUITTER", (sfVector2f){665.f, 625.f});
    return (SUCCESS);
}