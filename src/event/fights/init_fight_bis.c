/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** init_fight_bis.c
*/

#include "function.h"
#include "structure.h"

int get_fight_npc(fight_t *fight, char *line, int size)
{
    if (my_strlen(line) <= size)
        return (1);
    fight->npc = my_strcpy(&line[size]);
    if (!fight->npc)
        return (1);
    return (0);
}

int get_state(fight_t *fight, char *line, int size)
{
    if (my_strlen(line) <= size || my_str_isnum(&line[size]))
        return (1);
    fight->state = my_atoi(&line[size]);
    return (0);
}

int get_fight(fight_t *fight, char *line, int size)
{
    int i = size;

    if (my_strlen(line) <= size)
        return (1);
    while (line[i] != '\0') {
        if (line[i] < '0' || line[i] > '3')
            return (1);
        ++i;
    }
    fight->fight = my_strcpy(&line[size]);
    if (!fight->fight)
        return (1);
    return (0);
}

int get_music(fight_t *fight, char *line, int size)
{
    if (my_strlen(line) <= size || my_str_isnum(&line[size]))
        return (1);
    fight->music = my_atoi(&line[size]);
    if (fight->music >= NB_MUSIC)
        fight->music = -1;
    return (0);
}

int get_sprite(fight_t *fight, char *line, int size)
{
    if (my_strlen(line) <= size || my_str_isnum(&line[size]))
        return (1);
    fight->sprite = my_atoi(&line[size]);
    if (fight->sprite >= NB_SPRITE)
        fight->sprite = -1;
    return (0);
}