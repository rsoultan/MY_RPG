/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** game_structure
*/

#include <SFML/Window/Mouse.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include "macro.h"
#include "structure.h"
#include "function.h"

static void fill_values_by_default(game_t *game)
{
    game->window.pos_mouse =
        sfMouse_getPositionRenderWindow(game->window.render);
    game->scene = INTRODUCTION;
    game->old_scene = MAIN_MENU;
    game->htp_index = 0;
    game->window.fps = 30;
    game->inputs.move_mem = 0;
    game->audio.volume_music = 50;
    game->audio.volume_sound = 50;
    sfMusic_play(game->audio.music[MAIN_MENU_MUSIC]);
}

int create_game_structure(game_t *game)
{
    if (init_text(game) || init_window(game) || init_music(game) ||
        init_sound(game) || init_sprite(game) || init_maps(game) ||
        init_npc(game) || init_view(game) || init_game_time(game) ||
        init_button(game) || init_tp(game) || init_fight(game) ||
        init_quest(game) || init_ui(game) || init_particles(&game->part) ||
        init_inventory(game))
        return (ERROR);
    init_character(game);
    fill_values_by_default(game);
    return (SUCCESS);
}