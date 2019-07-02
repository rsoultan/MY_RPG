/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** menu_bg_part.c
*/

#include <stdlib.h>
#include <math.h>
#include "structure.h"
#include "function.h"

void print_circle(sfUint8 *buf, int pos[2], int r, sfColor color)
{
    int ymax = pos[Y] + r <= BUF_PART_H ? pos[Y] + r : BUF_PART_H;
    int ymin = pos[Y] - r >= 0 ? pos[Y] - r : 0;
    int xmax = pos[X] + r <= BUF_PART_W ? pos[X] + r : BUF_PART_W;
    int xmin = pos[Y] - r >= 0 ? pos[X] - r : 0;

    for (int i = ymin; i < ymax; ++i) {
        for (int j = xmin; j < xmax; ++j) {
            (int)sqrt(pow(j - pos[X], 2) + pow(i - pos[Y], 2)) < r ?
                put_pixel(buf, (i * BUF_PART_W + j) * 4, color) : 0;
        }
    }
}

void menu_bg_part_update(game_t *game)
{
    static int nb_circles = 0;
    static int cooldown = 0;
    sfColor color_circles = {255, 255, 190, 255};

    if (nb_circles < 20 && cooldown == 0) {
        print_circle(game->part.buf, (int [2]){rand() % BUF_PART_W,
            rand() % BUF_PART_H}, rand() % 30 + 10, color_circles);
        cooldown = 5;
    }
    for (int i = 0; i < BUF_PART_SIZE * 4; i += 4) {
        if (game->part.buf[i] == color_circles.r && game->part.buf[i + 1] ==
            color_circles.g && game->part.buf[i + 2] == color_circles.b &&
            game->part.buf[i + 3] > 0)
            game->part.buf[i + 3] -= 5;
    }
    cooldown -= 1;
    if (cooldown == 0)
        nb_circles -= rand() % 3 + 1;
}