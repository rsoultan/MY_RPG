/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** quest_discovering
*/

#include "function.h"
#include "structure.h"

int discover_epitech(game_t *game)
{
    if (game->quest[DISCOVER_EPITECH].goal_index == 0 &&
        (game->map_id == HALL || game->map_id == CORRIDOR_HUB))
        next_step_quest(game, DISCOVER_EPITECH);
    if (game->map_id == AMPHI &&
        game->quest[DISCOVER_EPITECH].goal_index == 1 &&
        game->player.pos.x == 192 && game->player.pos.y == 128) {
        switch_music(EPITECH_MUSIC, KEVIN_QUEST_MUSIC, game);
        next_quest(game, DISCOVER_EPITECH);
        game->npcs[MATTHIEUR].voice_line++;
    }
    return (SUCCESS);
}

int kevin_quest(game_t *game)
{
    if (game->quest[KEVIN_QUEST].goal_index == 1 &&
        item_is_in_inv(game, "Bueno") == true) {
        next_step_quest(game, KEVIN_QUEST);
    }
    return (SUCCESS);
}

int chloe_quest(game_t *game)
{
    if (game->map_id == AMPHI &&
        game->quest[CHLOE_QUEST].goal_index == 3 &&
        game->player.pos.x == 192 && game->player.pos.y == 128) {
        next_step_quest(game, CHLOE_QUEST);
        game->npcs[CHLOE].voice_line++;
    }
    return (SUCCESS);
}

int polo_quest(game_t *game)
{
    if (game->quest[POLO_QUEST].goal_index == 3 && game->map_id == FLOOR1 &&
        game->player.pos.x == 1104 && game->player.pos.y == 144) {
        game->maps[FG][game->map_id][8][69] = ' ';
        remove_item(game, "Cle du QG");
        next_step_quest(game, POLO_QUEST);
    }
    return (SUCCESS);
}

int corentin_quest(game_t *game)
{
    if (game->npcs[CORENTIN].voice_line == 4)
        next_quest(game, CORENTIN_QUEST);
    return (SUCCESS);
}