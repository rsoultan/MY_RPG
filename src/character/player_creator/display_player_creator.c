/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** credits_display
*/

#include <SFML/Graphics/RenderWindow.h>
#include "function.h"
#include "structure.h"
#include "macro.h"

static void player_creator_text(game_t *game)
{
    change_text_color(game, sfBlack);
    display_text(game, "Coiffure Precedente", (sfVector2f){20.f, 415.f});
    display_text(game, "Coiffure Suivante", (sfVector2f){1120.f, 415.f});
    display_text(game, "Peau Precedente", (sfVector2f){93.f, 510.f});
    display_text(game, "Peau Suivante", (sfVector2f){1120.f, 510.f});
    display_text(game, "Tenue Precedente", (sfVector2f){70.f, 615.f});
    display_text(game, "Tenue Suivante", (sfVector2f){1120.f, 615.f});
}

static void player_creator_draw_button(game_t *game)
{
    draw_button(game, (sfVector2f){100, 700}, (sfVector2f){10, 10}, CANCEL);
    draw_button(game, (sfVector2f){1400, 700}, (sfVector2f){10, 10}, CONFIRM);
    draw_button(game, (sfVector2f){490, 400}, (sfVector2f){10, 10},
        HAIR_LESS);
    draw_button(game, (sfVector2f){1110, 400}, (sfVector2f){-10, 10},
        HAIR_PLUS);
    draw_button(game, (sfVector2f){490, 500}, (sfVector2f){10, 10},
        SKIN_LESS);
    draw_button(game, (sfVector2f){1110, 500}, (sfVector2f){-10, 10},
        SKIN_PLUS);
    draw_button(game, (sfVector2f){490, 600}, (sfVector2f){10, 10},
        CLOTHES_LESS);
    draw_button(game, (sfVector2f){1110, 600}, (sfVector2f){-10, 10},
        CLOTHES_PLUS);
}

int display_player_creator(game_t *game)
{
    draw_sprite(game, BG_PLAYER_CREATOR, (sfVector2f){0, 0},
        (sfVector2f){1, 1});
    display_creator_character(game);
    player_creator_text(game);
    player_creator_draw_button(game);
    return (SUCCESS);
}