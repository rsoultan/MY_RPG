/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** display_quest
*/

#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Text.h>
#include "function.h"

static void draw_quest_text(game_t *game, unsigned short int quest_index)
{
    change_text_font(game, DIALOGUE_FONT);
    change_text_size(game, 18);
    sfText_setStyle(game->text.text, sfTextBold);
    sfText_setOutlineThickness(game->text.text, 1);
    change_text_color(game, sfRed);
    display_text(game, game->quest[quest_index].name,
        (sfVector2f){sfRectangleShape_getPosition(game->ui.quest).x, 100});
    change_text_color(game, sfWhite);
    sfText_setStyle(game->text.text, sfTextItalic);
    change_text_size(game, 17);
    display_text(game,
        game->quest[quest_index].info[game->quest[quest_index].goal_index],
        (sfVector2f){sfRectangleShape_getPosition(game->ui.quest).x, 150});
}

int display_quest(game_t *game)
{
    sfRenderWindow_drawRectangleShape(game->window.render,
        game->ui.quest, NULL);
    draw_quest_text(game, get_index_active_quest(game));
    return (0);
}