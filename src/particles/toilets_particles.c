/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** toilets_particles.c
*/

#include <stdlib.h>
#include "function.h"
#include "structure.h"

void particles_toilets(particles_t *part, window_t *win)
{
    int pos[14][2] = {
        {56, 40}, {56, 41}, {57, 39}, {57, 40}, {57, 41}, {57, 43}, {57, 41},
        {55, 44}, {55, 39}, {56, 39}, {57, 42}, {58, 41}, {55, 41}, {53, 42}
    };
    sfUint8 alphas[14] = {
        200, 145, 182, 210, 200, 210, 190, 132, 208, 182, 210, 200, 210, 190
    };
    int final_pos = 0;

    for (int i = 0; i < 5; ++i) {
        final_pos = (pos[i][Y] * BUF_PART_W + pos[i][X]) * 4;
        put_pixel(part->buf, final_pos, (sfColor){232, 245, 42,
            alphas[i] + (rand() % 7)});
    }
    display_particles(part, win);
}