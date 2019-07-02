/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** fight_event
*/

#include <SFML/Audio/Sound.h>
#include <SFML/Graphics/RectangleShape.h>
#include "function.h"
#include "structure.h"
#include "macro.h"

static const int keys[4] = {
    sfKeyDown,
    sfKeyRight,
    sfKeyUp,
    sfKeyLeft
};
static const int keys1[4] = {
    sfKeyS,
    sfKeyD,
    sfKeyZ,
    sfKeyQ
};
static const char fight[4] = {
    '0',
    '1',
    '2',
    '3'
};

static void fight_fail_click(game_t *game, int mem)
{
    sfSound_play(game->audio.sound[OOF]);
    game->fight[mem].life--;
    game->fight[mem].key = '4';
}

static void check_fight_event(game_t *game, sfEvent event)
{
    int mem = game->cur_fight;
    int key = -1;
    char pressed;

    game->fight[mem].key = 0;
    for (int i = 0; i < 4; ++i) {
        if (game->fight[mem].fight[game->fight[mem].i] == fight[i]) {
            key = i;
            pressed = fight[i];
        }
    }
    if (event.type == sfEvtKeyPressed) {
        game->fight[mem].time = 0;
        game->fight[mem].i++;
        if (event.key.code != keys[key] && event.key.code != keys1[key])
            fight_fail_click(game, mem);
        else {
            game->fight[mem].key = pressed;
            sfSound_play(game->audio.sound[FIGHT_SOUND]);
        }
    }
}

static void reset_text(game_t *game)
{
    sfRectangleShape_setSize(game->ui.quest, (sfVector2f){500, 100});
    sfRectangleShape_setFillColor(game->ui.quest,
        sfColor_fromRGBA(40, 40, 255, 220));
    sfRectangleShape_setOutlineColor(game->ui.quest, sfBlack);
    sfRectangleShape_setOutlineThickness(game->ui.quest, 10);
    game->ui.display_quest == true ?
        sfRectangleShape_setPosition(game->ui.quest,
        (sfVector2f){1100, 100}) :
        sfRectangleShape_setPosition(game->ui.quest,
        (sfVector2f){1610, 100});
}

static void fight_conditions(game_t *game, int i)
{
    if (game->fight[i].fight[game->fight[i].i] == '\0' &&
        game->fight[i].life > 0 && game->fight[i].phase == 1) {
        game->fight[i].phase++;
        game->npcs[game->fight[i].nb_npc].voice_line++;
        fight_quest(game, i);
    }
    else if (game->fight[i].life <= 0 && game->fight[i].phase == 1) {
        game->fight[i].i = 0;
        game->fight[i].phase++;
    }
    if (game->fight[i].phase == 3) {
        reset_text(game);
        game->scene = GAME_SCENE;
        switch_music((game->fight[i].music != -1 ? game->fight[i].music :
            BATTLE_MUSIC), game->audio.game_music, game);
    }
}

int fight_event(game_t *game)
{
    int i = game->cur_fight;
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window.render, &event)) {
        if (game->fight[i].phase == 1)
            check_fight_event(game, event);
        else if (event.type == sfEvtKeyPressed)
            game->fight[i].phase++;
        global_event(game, event);
    }
    fight_conditions(game, i);
    return (SUCCESS);
}