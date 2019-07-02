/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_quest
*/

#include <stdlib.h>
#include <stdio.h>
#include "structure.h"
#include "function.h"

static const char *paths[NB_QUEST] = {
    "src/quest/config/discover_quest",
    "src/quest/config/kevin_quest",
    "src/quest/config/chloe_quest",
    "src/quest/config/polo_quest",
    "src/quest/config/corentin_quest",
    "src/quest/config/finished_quest"
};

static int open_quest_file(game_t *game, FILE *fd, int quest_index)
{
    char *buffer = NULL;
    size_t size = 10;

    for (int i = 0; i < NB_QUEST_INFO; ++i) {
        if (getline(&buffer, &size, fd) == 1)
            return (ERROR);
        if (i == 0) {
            game->quest[quest_index].name = my_strcpy(buffer);
        } else
            game->quest[quest_index].info = my_str_to_word_array(buffer, ':');
        free(buffer);
        buffer = NULL;
        size = 10;
    }
    if (!game->quest[quest_index].name || !game->quest[quest_index].info)
        return (ERROR);
    game->quest[quest_index].done = false;
    game->quest[quest_index].is_active = false;
    game->quest[quest_index].goal_index = 0;
    return (SUCCESS);
}

int init_quest(game_t *game)
{
    FILE *fd;

    for (int i = 0; i < NB_QUEST; ++i) {
        fd = fopen(paths[i], "r");
        if (fd == NULL || open_quest_file(game, fd, i))
            return (ERROR);
        fclose(fd);
    }
    game->quest[DISCOVER_EPITECH].is_active = true;
    return (SUCCESS);
}