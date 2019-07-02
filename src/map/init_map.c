/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** initiaslise the map using the parsing
*/

#include <stdlib.h>
#include "structure.h"
#include "enum.h"
#include "function.h"

static const char *maps[NB_MAPS * 3] = {
    "assets/map/bg/epitech_hall.txt",
    "assets/map/bg/first_floor.txt", "assets/map/bg/street.txt",
    "assets/map/bg/amphi.txt", "assets/map/bg/corridor_hub.txt",
    "assets/map/bg/toillette.txt","assets/map/bg/banette.txt",
    "assets/map/bg/zimmer.txt", "assets/map/bg/crossing_road.txt",
    "assets/map/bg/antre.txt", "assets/map/bg/kfc.txt",
    "assets/map/fg/epitech_hall.txt", "assets/map/fg/first_floor.txt",
    "assets/map/fg/street.txt", "assets/map/fg/amphi.txt",
    "assets/map/fg/corridor_hub.txt", "assets/map/fg/toillette.txt",
    "assets/map/fg/banette.txt", "assets/map/fg/zimmer.txt",
    "assets/map/fg/crossing_road.txt", "assets/map/fg/antre.txt",
    "assets/map/fg/kfc.txt",
    "assets/map/obj/epitech_hall.txt",
    "assets/map/obj/first_floor.txt", "assets/map/obj/street.txt",
    "assets/map/obj/amphi.txt", "assets/map/obj/corridor_hub.txt",
    "assets/map/obj/toillette.txt", "assets/map/obj/banette.txt",
    "assets/map/obj/zimmer.txt", "assets/map/obj/crossing_road.txt",
    "assets/map/obj/antre.txt", "assets/map/obj/kfc.txt"
};

static char init_depth_maps(game_t *game, int depth)
{
    int index = 0;

    game->maps[depth] = malloc(sizeof(char **) * (NB_MAPS + 1));
    if (!game->maps[depth])
        return (ERROR);
    game->maps[depth][NB_MAPS] = NULL;
    for (int i = 0; i < NB_MAPS; ++i) {
        index = i + (depth * NB_MAPS);
        if (!(game->maps[depth][i] = parse_file(maps[index]))) {
            my_putchar('b');
            return (ERROR);
        }
    }
    return (SUCCESS);
}

char init_maps(game_t *game)
{
    game->map_id = STREET;
    for (int i = 0; i < NB_MAPS_TYPE; ++i) {
        if (init_depth_maps(game, i) == ERROR)
            return (ERROR);
    }
    return (SUCCESS);
}