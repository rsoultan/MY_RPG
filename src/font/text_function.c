/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** text_function
*/

#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/RenderWindow.h>
#include "structure.h"

void change_text_color(game_t *game, sfColor color)
{
    sfText_setColor(game->text.text, color);
}

void change_text_size(game_t *game, unsigned int size)
{
    sfText_setCharacterSize(game->text.text, size);
}

void change_text_font(game_t *game, int font)
{
    sfText_setFont(game->text.text, game->text.font[font]);
}

void display_text(game_t *game, const char *content, sfVector2f pos)
{
    sfText_setPosition(game->text.text, pos);
    sfText_setString(game->text.text, content);
    sfRenderWindow_drawText(game->window.render, game->text.text, NULL);
}