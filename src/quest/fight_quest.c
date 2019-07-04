/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** fight_quest
*/

#include "structure.h"
#include "function.h"

static void fight_questbis(game_t *game, int i)
{
    switch (i) {
        case 9:
            ++game->npcs[CORENTIN].voice_line;
            return (next_step_quest(game, CORENTIN_QUEST));
        case 6:
            game->player.pos.x = 32;
            game->player.pos.y = 32;
            break;
        case 2:
            return (switch_music(CORENTIN_QUEST_MUSIC, EPITECH_MUSIC, game));
    }
}

void fight_quest(game_t *game, int i)
{
    switch (i) {
        case 7:
            return (add_item(game, "Bueno",
                create_inventory_sprite(game->spr[ITEM].spr, BUENO)));
        case 5:
            ++game->npcs[CHLOE].voice_line;
            switch_music(KEVIN_QUEST_MUSIC, CHLOE_QUEST_MUSIC, game);
            return (next_quest(game, KEVIN_QUEST));
        case 1:
            return (next_step_quest(game, CHLOE_QUEST));
        case 4:
            ++game->npcs[MARIN].voice_line;
            add_item(game, "Rapport de Kaben",
                create_inventory_sprite(game->spr[ITEM].spr, USB));
            return (next_step_quest(game, POLO_QUEST));
        case 8:
            ++game->npcs[CORENTIN].voice_line;
            switch_music(POLO_QUEST_MUSIC, CORENTIN_QUEST_MUSIC, game);
            return (next_quest(game, POLO_QUEST));
    }
    fight_questbis(game, i);
}