/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** game_display
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/RenderTexture.h>
#include "function.h"
#include "structure.h"
#include "macro.h"

static void display_window_game(game_t *game)
{
    sfSprite_setTexture(game->cam.sp,
        sfRenderTexture_getTexture(game->cam.rt), sfTrue);
    sfSprite_setScale(game->cam.sp, (sfVector2f){1, -1});
    sfSprite_setOrigin(game->cam.sp, (sfVector2f){0, 900});
    sfRenderWindow_drawSprite(game->window.render, game->cam.sp, sfFalse);
}

void display_line(game_t *game, int y)
{
    if (y == (int)game->player.pos.y / 16)
        display_game_character(game);
    display_map_npc(game, y);
}

int game_display(game_t *game)
{
    clear_buffer(game->part.buf, sfTransparent);
    update_view(game);
    sfRenderTexture_clear(game->cam.rt, sfBlack);
    display_map(game);
    do_map_particles(game);
    display_window_game(game);
    npc_dialogue(game);
    display_inventory(game);
    if (display_quest(game) == 84)
        return (84);
    return (SUCCESS);
}