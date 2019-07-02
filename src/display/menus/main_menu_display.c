/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** main_menu_display
*/

#include "function.h"
#include "structure.h"
#include "macro.h"

int main_menu_display(game_t *game)
{
    sfRenderWindow_clear(game->window.render, (sfColor){80, 120, 255, 255});
    time_forward(game);
    display_particles(&game->part, &game->window);
    sfSprite_setScale(game->spr[EPITAFF_TITLE].spr, (sfVector2f){1, 1});
    sfSprite_setPosition(game->spr[EPITAFF_TITLE].spr,(sfVector2f){450, 50});
    sfRenderWindow_drawSprite(game->window.render,
        game->spr[EPITAFF_TITLE].spr, NULL);
    draw_button(game, (sfVector2f){600, 300},(sfVector2f){3, 3}, PLAY);
    draw_button(game, (sfVector2f){600, 500}, (sfVector2f){3, 3}, SETTINGS);
    draw_button(game, (sfVector2f){600, 700}, (sfVector2f){3, 3}, QUIT);
    draw_button(game, (sfVector2f){100, 100}, (sfVector2f){3, 3},
        HOW_TO_PLAY_BUTTON);
    display_text(game, "JOUER", (sfVector2f){700.f, 330.f});
    display_text(game, "OPTIONS", (sfVector2f){675.f, 525.f});
    display_text(game, "QUITTER", (sfVector2f){665.f, 725.f});
    return (SUCCESS);
}