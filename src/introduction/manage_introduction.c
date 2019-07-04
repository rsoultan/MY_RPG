/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** manage_introduction.c
*/

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "structure.h"
#include "function.h"

int print_tansition(particles_t *part)
{
    static int left = 100;
    int pos = 0;

    for (int i = 0; i < BUF_PART_SIZE * 4; i += 4) {
        part->buf[i] -= 10;
        part->buf[i + 1] -= 10;
        part->buf[i + 2] -= 10;
        part->buf[i + 3] -= 10;
    }
    for (int j = 0; j < 100; ++j) {
        pos = (int)fabs(rand() % BUF_PART_SIZE);
        for (int i = 0; i < 10 &&
            (i * BUF_PART_W + pos) * 4 < BUF_PART_SIZE * 4; ++i)
            put_pixel(part->buf, (i * BUF_PART_H + pos) * 4, sfWhite);
    }
    --left;
    return (left ? FALSE : TRUE);
}

static void print_letter_e(particles_t *part, int i)
{
    i -= 30;
    for (int k = 0; k < 3; ++k) {
        for (int j = 700; j < 900; ++j) {
            part->buf[(i * BUF_PART_W + j) * 4] == sfWhite.r &&
                part->buf[(i * BUF_PART_W + j) * 4 + 1] == sfWhite.g &&
                part->buf[(i * BUF_PART_W + j) * 4 + 2] == sfWhite.b &&
                part->buf[(i * BUF_PART_W + j) * 4 + 3] == sfWhite.a ?
                put_pixel(part->buf, (i * BUF_PART_W + j) * 4,
                sfImage_getPixel(part->logo, j, i)) : 0;
        }
        ++i;
    }
}

int print_bg_intro(particles_t *part)
{
    static sfColor color = {0, 0, 0, 255};

    if (color.b == 255)
        return (TRUE);
    for (int i = 0; i < BUF_PART_SIZE * 4; i += 4)
        put_pixel(part->buf, i, color);
    color.r += 1.5;
    color.g += 2.35;
    color.b += 5;
    return (FALSE);
}

static int print_square_pixels(particles_t *part, int y, sfColor color)
{
    static int len = 0;
    static int off = 801;

    if (y > 250 && y < 450) {
        len += 2;
        --off;
    } else if (y > 450) {
        len -= 2;
        ++off;
    }
    for (int i = 0; i < len; ++i)
        put_pixel(part->buf, (y * BUF_PART_W + off + i) * 4, color);
    if (len <= 0 && y > 750)
        return (TRUE);
    return (FALSE);
}

int print_inclined_square(particles_t *part)
{
    static int ret = FALSE;
    static int i = 245;

    for (int j = 0; j < 5; ++j) {
        ret += print_square_pixels(part, i, sfWhite);
        print_letter_e(part, i);
        ++i;
    }
    return (ret);
}