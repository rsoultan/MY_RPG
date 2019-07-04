/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** player_inputs
*/

#include <SFML/Graphics/RenderWindow.h>
#include "macro.h"
#include "structure.h"
#include "function.h"

static const int key[4] = {
    sfKeyRight, sfKeyDown, sfKeyLeft, sfKeyUp
};

static const int key1[4] = {
    sfKeyD, sfKeyS, sfKeyQ, sfKeyZ
};

static const sfVector2f move[4] = {
    {2, 0}, {0, 2}, {-2, 0}, {0, -2}
};
static const int orientation[4] = {
    RIGHT, DOWN, LEFT, UP
};

void check_fight(game_t *game, int npc)
{
    for (int i = 0; i < NB_FIGHT; ++i)
        if (game->fight[i].state != -1 &&
            game->fight[i].state == game->npcs[npc].voice_line &&
            my_strcmp(game->fight[i].npc, game->npcs[npc].lines[0])) {
            game->cur_fight = i;
            game->fight[i].time = 0;
            game->fight[i].nb_npc = npc;
            game->fight[i].life = 3;
            game->fight[i].key = 0;
            game->fight[i].phase = 0;
            game->scene = FIGHT_SCENE;
            switch_music(game->audio.game_music,
                (game->fight[i].music != -1 ? game->fight[i].music :
                BATTLE_MUSIC), game);
        }
}

void choose_direction(game_t *game, int i)
{
    if (game->inputs.move_mem == 1)
        return;
    if (sfKeyboard_isKeyPressed(key[i]) || sfKeyboard_isKeyPressed(key1[i])) {
        game->player.status[ORIENTATION] = orientation[i];
        if (!npc_hitbox(game) && !map_hitbox(game)) {
            game->inputs.pos = game->player.pos;
            game->inputs.move = move[i];
            game->inputs.move_mem = 1;
            manage_player_step(game);
        }
    }
}

void change_orientation(game_t *game, int npc, int i)
{
    int tmp = game->player.status[ORIENTATION];
    int new = tmp - 2;
    static int npcs;
    static int mem;

    if (new < 0) {
        new += 4;
    }
    if (i == 0) {
        mem = game->npcs[npc].skin.status[ORIENTATION];
        npcs = npc;
        game->npcs[npcs].skin.status[ORIENTATION] = new;
    } else
        game->npcs[npcs].skin.status[ORIENTATION] = mem;
}

void player_interaction(game_t *game, sfEvent event)
{
    int npc = npc_hitbox(game);

    if (npc && event.type == sfEvtKeyReleased &&
        (event.key.code == sfKeyE || event.key.code == sfKeySpace)) {
        if (game->player.dialogue == -1) {
            game->player.dialogue = npc - 1;
            change_orientation(game, npc - 1, 0);
        } else {
            check_fight(game, npc - 1);
            game->player.dialogue = -1;
            change_orientation(game, npc - 1, 1);
        }
    }
    if (npc - 1 != game->player.dialogue) {
        game->player.dialogue = -1;
        change_orientation(game, npc - 1, 1);
    }
}

void player_inputs(game_t *game, sfEvent event)
{
    player_interaction(game, event);
}