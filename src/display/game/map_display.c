/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** map_display.c
*/

#include <SFML/Graphics/RenderTexture.h>
#include "function.h"

void draw_tile(sprite_t *tile, unsigned int pos[2], game_t *game,
    sfIntRect rect)
{
    sfSprite_setTextureRect(tile->spr, rect);
    if (tile != &game->spr[SPR_OBJ]) {
        sfSprite_setPosition(tile->spr,
            (sfVector2f){pos[X] * 16, pos[Y] * 16});
    } else
        sfSprite_setPosition(tile->spr, (sfVector2f){pos[X] * 16,
            pos[Y] * 16 - 3});
    sfRenderTexture_drawSprite(game->cam.rt, tile->spr, NULL);
}

void do_map_particles(game_t *game)
{
    switch (game->map_id) {
        case TOILET:
            particles_toilets(&game->part, &game->window);
            return;
        default:
            return;
    };
}

static void choose_depth(unsigned int len_str, int i, game_t *game,
    int depth)
{
    for (unsigned int j = 0; j < len_str + 1; ++j) {
        switch (depth) {
            case BG:
                choose_tile_bg(game->maps[depth][game->map_id][i][j],
                    (unsigned int [2]){j, i}, game);
                break;
            case FG:
                choose_tile_fg(game->maps[depth][game->map_id][i][j],
                    (unsigned int [2]){j, i}, game);
                    display_line(game, i);
                break;
            case OBJ:
                choose_tile_obj(game->maps[depth][game->map_id][i][j],
                    (unsigned int [2]){j, i}, game);
                break;
            default:
                return;
        }
    }
}

void display_map(game_t *game)
{
    unsigned int map_len = 0;
    unsigned int len_str = 0;

    sfRenderWindow_clear(game->window.render, sfWhite);
    if (!game->maps[BG] || !game->maps[FG] || !game->maps[OBJ])
        return;
    for (int a = 0; a < NB_MAPS_TYPE; ++a) {
        map_len = my_arrlen(game->maps[a][game->map_id]);
        for (unsigned int i = 0; i < map_len; ++i) {
            len_str = my_strlen(game->maps[a][game->map_id][i]);
            choose_depth(len_str, i, game, a);
        }
    }
    do_map_particles(game);
    display_particles_on_map(&game->part, &game->cam);
}