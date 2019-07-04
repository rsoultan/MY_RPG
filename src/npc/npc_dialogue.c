/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** npc_dialogue
*/

#include <SFML/Graphics/Text.h>
#include "structure.h"
#include "function.h"

static void set_dialogue_font(game_t *game)
{
    change_text_font(game, DIALOGUE_FONT);
    change_text_color(game, sfBlack);
    change_text_size(game, 34);
    sfText_setStyle(game->text.text, sfTextRegular);
    sfText_setOutlineThickness(game->text.text, 0);
}

void npc_dialogue(game_t *game)
{
    int line;
    char *name;
    char *dialogue;
    sfVector2f pos = {100, 680};

    if (game->player.dialogue != -1) {
        sfRenderWindow_drawSprite(game->window.render, game->spr[TALK_BAR].spr,
            NULL);
        line = game->npcs[game->player.dialogue].voice_line;
        name = game->npcs[game->player.dialogue].lines[0];
        dialogue = game->npcs[game->player.dialogue].lines[line];
        set_dialogue_font(game);
        display_text(game, name, pos);
        display_text(game, " : ",
            (sfVector2f){(pos.x + (24 * (my_strlen(name) + 1))), pos.y});
        change_text_size(game, 20);
        display_text(game, dialogue,
            (sfVector2f){pos.x, pos.y + 80});
    }
    dialogue_quest(game, game->player.dialogue);
}