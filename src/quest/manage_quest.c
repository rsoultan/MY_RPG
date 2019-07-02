/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** manage_quest
*/

#include "structure.h"
#include "function.h"

static int(*ptr[])(game_t*) = {
    discover_epitech, kevin_quest, chloe_quest, polo_quest, corentin_quest,
    end_quest
};

unsigned short int get_index_active_quest(game_t *game)
{
    unsigned short int index = 0;

    while (index < NB_QUEST) {
        if (game->quest[index].is_active == true)
            return (index);
        index++;
    }
    return (-1);
}

int manage_quest(game_t *game)
{
    unsigned short int index = get_index_active_quest(game);

    return (ptr[index](game));
}

void next_step_quest(game_t *game, unsigned short int index)
{
    ++game->quest[index].goal_index;
    play_sound(game, QUEST_COMPLETED_SOUND);
}

void next_quest(game_t *game, unsigned short int index)
{
    game->quest[index].done = true;
    game->quest[index].is_active = false;
    game->quest[index + 1].is_active = true;
    game->quest[index + 1].goal_index = 0;
    play_sound(game, QUEST_COMPLETED_SOUND);
}