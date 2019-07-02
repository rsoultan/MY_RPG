/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_fight
*/

#include <stdlib.h>
#include <stdio.h>
#include "structure.h"
#include "function.h"

static const char *paths[NB_FIGHT] = {
    "src/event/fights/config/fight_baptiste",
    "src/event/fights/config/fight_chloe",
    "src/event/fights/config/fight_corentin",
    "src/event/fights/config/fight_guillaumed",
    "src/event/fights/config/fight_kaben",
    "src/event/fights/config/fight_kevin",
    "src/event/fights/config/fight_lucas",
    "src/event/fights/config/fight_matthieur",
    "src/event/fights/config/fight_polo",
    "src/event/fights/config/fight_quentink"
};
static char *flags[5] = {
    "npc:", "state:", "fight:", "sp:", "mc:"
};
static int size[5] = {
    4, 6, 6, 3, 3
};

static void preset_fight(fight_t *fight)
{
    fight->sprite = -1;
    fight->i = 0;
    fight->key = 0;
    fight->music = -1;
    fight->npc = NULL;
    fight->fight = NULL;
    fight->state = 1;
}

static int create_fight(char **file, fight_t *fight)
{
    int(*ptr[5])(fight_t *, char *, int) = {
        &get_fight_npc, &get_state,
        &get_fight, &get_sprite, &get_music
    };
    int ret = 0;

    preset_fight(fight);
    for (int i = 0; i < 5 && file[i]; ++i) {
        for (int j = 0; j < 5; ++j) {
            my_strncmp(file[i], flags[j], size[j]) ?
                ret = ptr[j](fight, file[i], size[j]) : 0;
        }
        if (file[i])
            free(file[i]);
        if (ret)
            return (1);
    }
    if (!fight->npc || !fight->fight)
        return (1);
    return (0);
}

static int open_fight_file(FILE *fd, fight_t *fight)
{
    char *file[5];
    size_t size = 10;

    fight->fight = NULL;
    fight->sprite = -1;
    for (int i = 0; i < 5; ++i) {
        file[i] = NULL;
        if (getline(&file[i], &size, fd) == -1) {
            free(file[i]);
            file[i] = NULL;
            break;
        }
        if (file[i])
            file[i] = clean_str(file[i]);
    }
    return (create_fight(file, fight));
}

int init_fight(game_t *game)
{
    FILE *fd;

    for (int i = 0; i < NB_FIGHT; ++i) {
        fd = fopen(paths[i], "r");
        if (fd == NULL)
            return (1);
        if (open_fight_file(fd, &game->fight[i]))
            return (1);
        fclose(fd);
    }
    return (0);
}