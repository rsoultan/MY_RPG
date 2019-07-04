/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** introduction_display
*/

#include "structure.h"
#include "macro.h"
#include "function.h"

static int (*ptr[NB_ANIMATIONS_INTRO])(particles_t *part) = {
    print_bg_intro,
    print_inclined_square,
    print_tansition
};

void intro_update(game_t *game)
{
    static int index = 0;

    if (ptr[index](&game->part) != FALSE) {
        index++;
        if (index == NB_ANIMATIONS_INTRO) {
            clear_buffer(game->part.buf, (sfColor){80, 120, 255, 255});
            game->scene = MAIN_MENU;
        }
    }
}

int introduction_display(game_t *game)
{
    time_forward(game);
    display_particles(&game->part, &game->window);
    return (SUCCESS);
}