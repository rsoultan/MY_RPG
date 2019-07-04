/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_tp
*/

#include <stdlib.h>
#include <stdio.h>
#include "structure.h"
#include "macro.h"
#include "function.h"

char *paths[NB_TP] = {
    "src/map/config/tpstreet1",
    "src/map/config/tpstreet2", "src/map/config/tpstreet1back",
    "src/map/config/tpstreet1_2back", "src/map/config/tpstreet2back",
    "src/map/config/tphall1", "src/map/config/tphall2",
    "src/map/config/tphall3", "src/map/config/tphall1back",
    "src/map/config/tphall2back", "src/map/config/tphall3back",
    "src/map/config/tpfloor1", "src/map/config/tpfloor1back",
    "src/map/config/tpfloor1_2back", "src/map/config/tpcorridor1",
    "src/map/config/tpcorridor1_2", "src/map/config/tpcorridor1_3",
    "src/map/config/tpcorridor2", "src/map/config/tpcorridor2_2",
    "src/map/config/tpamphi1", "src/map/config/tpamphi1_2",
    "src/map/config/tpamphi2", "src/map/config/tpamphi2_2",
    "src/map/config/tpfloor1_2", "src/map/config/tptoillete1",
    "src/map/config/tptoillette1back", "src/map/config/tptoillette2",
    "src/map/config/tpbanette1", "src/map/config/tpbanette2",
    "src/map/config/tpbanette3", "src/map/config/tpbanette4",
    "src/map/config/tpbanette5", "src/map/config/tpbanette1back",
    "src/map/config/tproad1", "src/map/config/tproad1back",
    "src/map/config/tpamphistreet", "src/map/config/tpamphistreetback",
    "src/map/config/tproad2", "src/map/config/tproad3",
    "src/map/config/tproad4", "src/map/config/tproad5",
    "src/map/config/tproad2back", "src/map/config/tproad3back",
    "src/map/config/tproad4back", "src/map/config/tproad5back",
    "src/map/config/tpzimmer1", "src/map/config/tpzimmer2",
    "src/map/config/tpzimmer3", "src/map/config/tpzimmer4",
    "src/map/config/tpzimmer5", "src/map/config/tpzimmer1back",
    "src/map/config/tpkfc1", "src/map/config/tpkfc2", "src/map/config/tpkfc3",
    "src/map/config/tpkfc4", "src/map/config/tpkfc5",
    "src/map/config/tpkfcback1", "src/map/config/tpkfcback2",
    "src/map/config/tpantre", "src/map/config/tpantreback"
};

static int get_tp_coo(tp_t *tp, char *line)
{
    if (my_strlen(line) <= 3 || my_str_isnum(&line[3]))
        return (1);
    if (line[0] == 'x') {
        line[1] == '1' ? tp->pos.x = my_atoi(&line[3]) * 16 : 0;
        line[1] == '2' ? tp->tp.x = my_atoi(&line[3]) * 16 : 0;
    } else if (line[0] == 'y') {
        line[1] == '1' ? tp->pos.y = my_atoi(&line[3]) * 16 : 0;
        line[1] == '2' ? tp->tp.y = my_atoi(&line[3]) * 16 : 0;
    }
    return (0);
}

static int get_tp_map(tp_t *tp, char *line)
{
    if (my_strlen(line) <= 5 || my_str_isnum(&line[5]))
        return (1);
    if (line[3] == '1')
        tp->current_id = my_atoi(&line[5]);
    if (line[3] == '2')
        tp->tp_id = my_atoi(&line[5]);
    return (0);
}

static int create_tp(char **file, tp_t *tp)
{
    static char *flags[6] = {"map1:", "map2:", "x1:", "x2:", "y1:", "y2:"};
    static int size[6] = {5, 5, 3, 3, 3, 3};
    int(*ptr[6])(tp_t *, char *) = {&get_tp_map, &get_tp_map, &get_tp_coo,
        &get_tp_coo, &get_tp_coo, &get_tp_coo};

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; j++)
            my_strncmp(file[i], flags[j], size[j]) ? ptr[j](tp, file[i]) : 0;
        free(file[i]);
    }
    return (0);
}

static int open_tp_file(FILE *fd, tp_t *tp)
{
    char *file[6];
    size_t size = 10;

    for (int i = 0; i < 6; ++i) {
        file[i] = NULL;
        if (getline(&file[i], &size, fd) == 1)
            return (1);
        file[i] = clean_str(file[i]);
    }
    return (create_tp(file, tp));
}

int init_tp(game_t *game)
{
    FILE *fd;

    for (int i = 0; i < NB_TP; ++i) {
        fd = fopen(paths[i], "r");
        if (fd == NULL)
            return (1);
        if (open_tp_file(fd, &game->tp[i]))
            return (1);
        fclose(fd);
    }
    return (0);
}