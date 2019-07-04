/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** map.h
*/

#ifndef MAP_H
    #define MAP_H

enum depths {
    FLOOR,
    OBJECT,
    ROOF
};

enum coordinates {
    X,
    Y
};

enum maps_type {
    BG,
    FG,
    OBJ,
    NB_MAPS_TYPE
};

enum maps_names {
    HALL,
    FLOOR1,
    STREET,
    AMPHI,
    CORRIDOR_HUB,
    TOILET,
    BANNETTE,
    ZIMMER,
    CROSSING_STREET,
    ANTRE,
    KFCMAP,
    NB_MAPS
};

typedef struct s_print_map {
    unsigned int pos[2];
    char tile;
} print_map_t;

/* BACKGROUND TILES */
    #define NB_MAP_TILE_RECT_BG 22

    #define TILE_CARPET {0, 0}
    #define TILE_FLOOR1 {1, 0}
    #define TILE_MARBLE {2, 0}
    #define TILE_WORK_STREET {3, 0}
    #define TILE_VOID_BG {4, 0}
    #define TILE_MAP_BORDER {4, 0}
    #define TILE_GRASS {5, 0}
    #define TILE_WOODEN_FLOOR {0, 1}
    #define TILE_W_STAIRS_UP {1, 1}
    #define TILE_W_STAIRS_RIGHT {2, 1}
    #define TILE_W_STAIRS_DOWN {3, 1}
    #define TILE_W_STAIRS_LEFT {4, 1}
    #define TILE_TP_CASE {5, 1}
    #define TILE_DOME_MIDDLE {0, 2}
    #define TILE_STAIRS_UP {1, 2}
    #define TILE_STAIRS_RIGHT {2, 2}
    #define TILE_STAIRS_LEFT {3, 2}
    #define TILE_STAIRS_DOWN {4, 2}
    #define TILE_COURTYARD {5, 2}
    #define TILE_DOME_STREET {0, 3}
    #define TILE_NEW_WOOD_1 {1, 3}
    #define TILE_NEW_WOOD_2 {2, 3}

/* FOREGROUND TILES */
    #define NB_MAP_TILE_RECT_FG 17
    #define TILE_FENCE_GRILL {0, 0, 16, 48}
    #define TILE_FENCE_PILLAR {16, 0, 16, 48}
    #define TILE_TABLE_V {32, 0, 16, 64}
    #define TILE_TABLE_H {48, 0, 32, 48}
    #define TILE_HEDGE {80, 0, 16, 48}
    #define TILE_VOID_FG {96, 0, 16, 16}
    #define TILE_SINK {96, 0, 16, 48}
    #define TILE_TOILET {112, 0, 16, 48}
    #define TILE_TOILETBAR {128, 0, 16, 48}
    #define TILE_BAN1 {144, 0, 16, 64}
    #define TILE_BAN2 {160, 0, 48, 48}
    #define TILE_COUCH {208, 0, 16, 64}
    #define TILE_BED {224, 0, 32, 64}
    #define TILE_DISTRIB {256, 0, 16, 48}
    #define TILE_DOOR {272, 0, 16, 48}
    #define TILE_KFCBORNE {288, 0, 16, 48}
    #define TILE_KFC {304, 0, 32, 48}

/* OBJECT TILES */
    #define NB_MAP_TILE_RECT_OBJ 5
    #define TILE_2_PC_V 0
    #define TILE_PC_RIGHT 1
    #define TILE_PC_FRONT 2
    #define TILE_PC_LEFT 3
    #define TILe_2_PC_H 4

#endif