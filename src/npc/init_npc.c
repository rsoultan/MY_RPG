/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_pnj
*/

#include <stdlib.h>
#include <stdio.h>
#include "function.h"
#include "structure.h"

static const char *paths[NB_NPC] = {
    "src/npc/config/alexis",
    "src/npc/config/anthony",
    "src/npc/config/antoine",
    "src/npc/config/antoinez",
    "src/npc/config/arthurd",
    "src/npc/config/arthurk",
    "src/npc/config/auguste",
    "src/npc/config/augustin",
    "src/npc/config/axel",
    "src/npc/config/banette",
    "src/npc/config/baptistem",
    "src/npc/config/benjamin",
    "src/npc/config/billeray",
    "src/npc/config/chaillard",
    "src/npc/config/chapau",
    "src/npc/config/chloe",
    "src/npc/config/clementr",
    "src/npc/config/clements",
    "src/npc/config/corentin",
    "src/npc/config/dimitri",
    "src/npc/config/elia",
    "src/npc/config/elric",
    "src/npc/config/emilien",
    "src/npc/config/felix",
    "src/npc/config/florent",
    "src/npc/config/florianm",
    "src/npc/config/florians",
    "src/npc/config/fred",
    "src/npc/config/guillaume",
    "src/npc/config/guillaumed",
    "src/npc/config/helena",
    "src/npc/config/hindowa",
    "src/npc/config/hoanggiang",
    "src/npc/config/hugo",
    "src/npc/config/hugod",
    "src/npc/config/theo",
    "src/npc/config/ibrahim",
    "src/npc/config/isg1",
    "src/npc/config/isg2",
    "src/npc/config/isg3",
    "src/npc/config/ismail",
    "src/npc/config/jeanepp",
    "src/npc/config/jeanfrancois",
    "src/npc/config/jg",
    "src/npc/config/jonathann",
    "src/npc/config/julien",
    "src/npc/config/kaben",
    "src/npc/config/kaiser",
    "src/npc/config/kevin",
    "src/npc/config/kilianp",
    "src/npc/config/kilians",
    "src/npc/config/kiliant",
    "src/npc/config/laurent",
    "src/npc/config/leok",
    "src/npc/config/leos",
    "src/npc/config/lienhart",
    "src/npc/config/loic",
    "src/npc/config/louisk",
    "src/npc/config/louisl",
    "src/npc/config/louisp",
    "src/npc/config/lucas",
    "src/npc/config/lucash",
    "src/npc/config/lucasz",
    "src/npc/config/lucien",
    "src/npc/config/marcha",
    "src/npc/config/marin",
    "src/npc/config/marius",
    "src/npc/config/mathieuh",
    "src/npc/config/matthieup",
    "src/npc/config/matthieur",
    "src/npc/config/maxime",
    "src/npc/config/melanie",
    "src/npc/config/paul",
    "src/npc/config/pauld",
    "src/npc/config/polomack",
    "src/npc/config/quentinc",
    "src/npc/config/quentinh",
    "src/npc/config/quentink",
    "src/npc/config/quentint",
    "src/npc/config/remy",
    "src/npc/config/romuald",
    "src/npc/config/sax_guy",
    "src/npc/config/seichepine",
    "src/npc/config/timothee",
    "src/npc/config/tom",
    "src/npc/config/valentina",
    "src/npc/config/valentinm",
    "src/npc/config/victork",
    "src/npc/config/victorl",
    "src/npc/config/yanis",
    "src/npc/config/yann",
    "src/npc/config/yuantao",
    "src/npc/config/yvan",
    "src/npc/config/omar"
};
static const char *flags[6] = {
    "sk:", "st:", "map:", "x:", "y:", "line:"
};
static const int size[6] = {
    3, 3, 4, 2, 2, 5
};

static void preset_npc(npc_t *npc)
{
    npc->voice_line = 1;
    npc->lines = NULL;
    npc->map = 0;
    npc->pos.x = 0;
    npc->pos.y = 0;
    for (int i = 0; i < 3; i++)
        npc->skin.skin[i] = 0;
    for (int i = 0; i < 3; i++)
        npc->skin.status[i] = 0;
}

int create_npc(char **file, npc_t *npc)
{
    int(*ptr[6])(npc_t *, char *) = {
        &get_skin, &get_stat, &get_map_id,
        &get_coo, &get_coo, &get_lines};
    int ret = 0;

    preset_npc(npc);
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; j++) {
            if (my_strncmp(file[i], flags[j], size[j]))
                ptr[j](npc, file[i]);
        }
        free(file[i]);
        if (ret)
            return (1);
    }
    if (!npc->lines || my_arrlen(npc->lines) < 2)
        return (1);
    return (0);
}

int open_npc_file(FILE *fd, npc_t *npc)
{
    char *file[6];
    size_t size = 10;

    for (int i = 0; i < 6; ++i) {
        file[i] = NULL;
        if (getline(&file[i], &size, fd) == 1)
            return (1);
        file[i] = clean_str(file[i]);
    }
    return (create_npc(file, npc));
}

int init_npc(game_t *game)
{
    FILE *fd;

    for (int i = 0; i < NB_NPC; ++i) {
        fd = fopen(paths[i], "r");
        if (fd == NULL)
            return (1);
        if (open_npc_file(fd, &game->npcs[i]))
            return (1);
        fclose(fd);
    }
    return (0);
}