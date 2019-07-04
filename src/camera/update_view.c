/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** update_view
*/

#include <SFML/Graphics/View.h>
#include <SFML/Graphics/RenderTexture.h>
#include "structure.h"

void update_view(game_t *game)
{
    sfVector2f pos = {game->player.pos.x + 8, game->player.pos.y + 8};

    sfView_setCenter(game->cam.view, pos);
    sfRenderTexture_setView(game->cam.rt, game->cam.view);
}