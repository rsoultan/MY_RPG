/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** dialogue_quest
*/

#include "structure.h"
#include "function.h"

static void dialogue_kevin_quest(game_t *game, short index)
{
    if (game->quest[KEVIN_QUEST].goal_index == 0 && index == KEVIN)
        next_step_quest(game, KEVIN_QUEST);
    if (item_is_in_inv(game, "Bueno") == true &&
        game->quest[KEVIN_QUEST].goal_index == 2 && index == KEVIN) {
        ++game->npcs[KEVIN].voice_line;
        remove_item(game, "Bueno");
        next_step_quest(game, KEVIN_QUEST);
    }
}

static void dialogue_chloe_quest(game_t *game, short index)
{
    if (game->quest[CHLOE_QUEST].goal_index == 0 && index == CHLOE)
        next_step_quest(game, CHLOE_QUEST);
    if (game->quest[CHLOE_QUEST].goal_index == 1 && index == ELRIC) {
        next_step_quest(game, CHLOE_QUEST);
        ++game->npcs[ELRIC].voice_line;
        ++game->npcs[CHLOE].voice_line;
        game->npcs[CHLOE].pos.x = 3 * 16;
        game->npcs[CHLOE].pos.y = 11 * 16;
        game->npcs[CHLOE].skin.status[ORIENTATION] = 3;
    }
    if (game->quest[CHLOE_QUEST].goal_index == 4 && index == CHLOE) {
        ++game->npcs[MARIN].voice_line;
        switch_music(CHLOE_QUEST_MUSIC, POLO_QUEST_MUSIC, game);
        next_quest(game, CHLOE_QUEST);
    }
}

static void dialogue_polo_quest(game_t *game, short index)
{
    if (game->quest[POLO_QUEST].goal_index == 0 && index == MARIN) {
        ++game->npcs[KABEN].voice_line;
        next_step_quest(game, POLO_QUEST);
    }
    if (game->quest[POLO_QUEST].goal_index == 2 && index == MARIN) {
        remove_item(game, "Rapport de Kaben");
        add_item(game, "Cle du QG",
            create_inventory_sprite(game->spr[ITEM].spr, KEY));
        next_step_quest(game, POLO_QUEST);
    }
}

static void dialogue_corentin_quest(game_t *game, short index)
{
    if (game->quest[CORENTIN_QUEST].goal_index == 0 && index == CORENTIN) {
        ++game->npcs[QUENTINK].voice_line;
        next_step_quest(game, CORENTIN_QUEST);
    }
}

void dialogue_quest(game_t *game, short index)
{
    if (game->quest[KEVIN_QUEST].is_active == true)
        dialogue_kevin_quest(game, index);
    if (game->quest[CHLOE_QUEST].is_active == true)
        dialogue_chloe_quest(game, index);
    if (game->quest[POLO_QUEST].is_active == true)
        dialogue_polo_quest(game, index);
    if (game->quest[CORENTIN_QUEST].is_active == true)
        dialogue_corentin_quest(game, index);
}