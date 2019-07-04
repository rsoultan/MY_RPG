/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_view
*/

#include <SFML/Graphics/View.h>
#include <SFML/Graphics/RenderTexture.h>
#include "structure.h"

int init_view(game_t *game)
{
    sfFloatRect rect = {80, 0, 0, 142};

    rect.height = 176;
    rect.left = 0;
    rect.top = 0;
    rect.width = 336;
    game->cam.view = sfView_createFromRect(rect);
    game->cam.rt = sfRenderTexture_create(1600, 900, sfTrue);
    game->cam.sp = sfSprite_create();
    if (game->cam.view == NULL || !game->cam.rt || !game->cam.sp)
        return (ERROR);
    return (SUCCESS);
}