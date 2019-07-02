/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** init_text
*/

#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Font.h>
#include "structure.h"
#include "macro.h"

static const char *font[NB_FONT] = {
    "assets/font/menu_font.ttf",
    "assets/font/dialogue_font2.ttf"
};

int init_text(game_t *game)
{
    for (int i = 0; i < NB_FONT; ++i) {
        game->text.font[i] = sfFont_createFromFile(font[i]);
        if (!game->text.font[i])
            return (ERROR);
    }
    game->text.text = sfText_create();
    if (!game->text.text)
        return (ERROR);
    sfText_setFont(game->text.text, game->text.font[MENU_FONT]);
    sfText_setColor(game->text.text, sfBlack);
    sfText_scale(game->text.text, (sfVector2f){2, 2});
    return (SUCCESS);
}