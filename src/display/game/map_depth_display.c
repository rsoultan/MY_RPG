/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** map_depth_display.c
*/

#include "function.h"

void choose_tile_obj(char tile, unsigned int pos[2], game_t *game)
{

    static char tile_code_obj[] = "VRFLH";
    static const unsigned int rects[NB_MAP_TILE_RECT_OBJ] = {
        TILE_2_PC_V, TILE_PC_RIGHT, TILE_PC_FRONT, TILE_PC_LEFT, TILe_2_PC_H
    };

    for (int i = 0; i != NB_MAP_TILE_RECT_OBJ; ++i) {
        if (tile == tile_code_obj[i]) {
            draw_tile(&game->spr[SPR_OBJ], pos, game,
                (sfIntRect){rects[i] * 16, 0, 16, 16});
            return;
        }
    }
}

void choose_tile_bg(char tile, unsigned int pos[2], game_t *game)
{
    static const unsigned int rects_bg[NB_MAP_TILE_RECT_BG][2] = {
        TILE_CARPET, TILE_FLOOR1, TILE_MARBLE, TILE_WORK_STREET, TILE_VOID_BG,
        TILE_MAP_BORDER, TILE_GRASS, TILE_WOODEN_FLOOR, TILE_W_STAIRS_UP,
        TILE_W_STAIRS_RIGHT, TILE_W_STAIRS_LEFT, TILE_W_STAIRS_DOWN,
        TILE_TP_CASE, TILE_DOME_MIDDLE, TILE_STAIRS_UP, TILE_STAIRS_RIGHT,
        TILE_STAIRS_LEFT, TILE_STAIRS_DOWN, TILE_COURTYARD, TILE_DOME_STREET,
        TILE_NEW_WOOD_1, TILE_NEW_WOOD_2
    };
    static const char tile_code_bg[NB_MAP_TILE_RECT_BG] =
        "cFM! #GW&)(|Pd{][}CDNn";

    for (int i = 0; tile_code_bg[i] != 0; ++i) {
        if (tile == tile_code_bg[i]) {
            draw_tile(&game->spr[SPR_BG], pos, game,
                (sfIntRect){rects_bg[i][X] * 16, rects_bg[i][Y] * 16, 16, 16});
            return;
        }
    }
}

void choose_tile_fg(char tile, unsigned int pos[2], game_t *game)
{
    static const char tile_code_fg[NB_MAP_TILE_RECT_FG] = "HIOZX TSiBbCEDPKF";
    static const sfIntRect rects_fg[NB_MAP_TILE_RECT_FG] = {
        TILE_FENCE_GRILL, TILE_FENCE_PILLAR, TILE_TABLE_V, TILE_TABLE_H,
        TILE_HEDGE, TILE_VOID_FG, TILE_TOILET, TILE_SINK, TILE_TOILETBAR,
        TILE_BAN1, TILE_BAN2, TILE_COUCH, TILE_BED, TILE_DISTRIB, TILE_DOOR,
        TILE_KFCBORNE, TILE_KFC
    };
    unsigned int new_pos[2] = {pos[X], pos[Y] - 2};

    for (int i = 0; tile_code_fg[i] != 0; ++i) {
        if (tile == tile_code_fg[i]) {
            draw_tile(&game->spr[SPR_FG], new_pos, game, rects_fg[i]);
            return;
        }
    }
}