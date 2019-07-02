/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** init_npc_bis.c
*/

#include <stdlib.h>
#include "structure.h"
#include "function.h"

int get_skin(npc_t *npc, char *line)
{
    if (my_strlen(line) != 6)
        return (1);
    for (int i = 3; i < 6; ++i)
        if (line[i] < '0')
            return (1);
    npc->skin.skin[0] = line[3] - '0';
    npc->skin.skin[1] = line[4] - '0';
    npc->skin.skin[2] = line[5] - '0';
    return (0);
}

int get_stat(npc_t *npc, char *line)
{
    if (my_strlen(line) != 6)
        return (1);
    for (int i = 3; i < 6; ++i)
        if (line[i] < '0' || line[i] >'9')
            return (1);
    npc->skin.status[0] = line[3] - '0';
    npc->skin.status[1] = line[4] - '0';
    npc->skin.status[2] = line[5] - '0';
    return (0);
}

int get_map_id(npc_t *npc, char *line)
{
    if (my_strlen(line) <= 4 || my_str_isnum(&line[4]))
        return (1);
    npc->map = my_atoi(&line[4]);
    return (0);
}

int get_coo(npc_t *npc, char *line)
{
    if (my_strlen(line) <= 2 || my_str_isnum(&line[2]))
        return (1);
    if (line[0] == 'x')
        npc->pos.x = my_atoi(&line[2]) * 16;
    else if (line[0] == 'y')
        npc->pos.y = my_atoi(&line[2]) * 16;
    return (0);
}

int get_lines(npc_t *npc, char *line)
{
    if (my_strlen(line) <= 5)
        return (1);
    npc->lines = my_str_to_word_array(&line[5], ':');
    if (!npc->lines || my_arrlen(npc->lines) < 2)
        return (1);
    return (0);
}