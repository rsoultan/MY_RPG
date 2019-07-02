/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** map_hit_box
*/

#include "structure.h"
#include "function.h"

int segvicide(char **map, int y, int x)
{
    int check_y = my_arrlen(map);
    int check_x;

    if (y < 0 || y >= check_y)
        return (0);
    check_x = my_strlen(map[y]);
    if (x < 0 || x >= check_x)
        return (0);
    return (1);
}

int map_hitbox(game_t *game)
{
    sfVector2i dir[4] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
    int orientation = game->player.status[ORIENTATION];
    int x = (int)game->player.pos.x / 16;
    int y = (int)game->player.pos.y / 16;

    if (segvicide(game->maps[FG][game->map_id], y + dir[orientation].y,
        x + dir[orientation].x) && game->maps[FG][game->map_id]
        [y + dir[orientation].y][x + dir[orientation].x] != ' ')
        return (1);
    return (0);
}