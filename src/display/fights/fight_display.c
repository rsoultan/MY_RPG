/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** fight_display
*/

#include <SFML/Graphics/RectangleShape.h>
#include "structure.h"
#include "macro.h"
#include "function.h"

static const float ori[4] = {
    270,
    180,
    90,
    0
};
static const sfVector2f pos[4] = {
    {500, 700},
    {920, 500},
    {720, 80},
    {300, 280}
};

static void display_fight_button(game_t *game, int i)
{
    int fight = game->cur_fight;

    sfRectangleShape_setRotation(game->button[FIGHT_BUTTON].rect_shape,
        ori[i]);
    sfRectangleShape_setFillColor(game->button[FIGHT_BUTTON].rect_shape,
        sfColor_fromRGB(0, 0, 255));
    if (game->fight[fight].fight[game->fight[fight].i] == '0' + i)
        sfRectangleShape_setFillColor(game->button[FIGHT_BUTTON].rect_shape,
            sfColor_fromRGB(0, 255, 0));
    if (game->fight[fight].key == '4' || (game->fight[fight].key >= '0' &&
        game->fight[fight].key <= '3' && game->fight[fight].key == i + '0'))
        sfRectangleShape_setFillColor(game->button[FIGHT_BUTTON].rect_shape,
        sfBlack);
    if (game->fight[fight].key == '5') {
        sfRectangleShape_setFillColor(game->button[FIGHT_BUTTON].rect_shape,
            sfColor_fromRGB(0, 0, 0));
        game->fight[fight].key = 0;
    }
    draw_button(game, pos[i], (sfVector2f){20, 20}, FIGHT_BUTTON);
}

static void display_enemy(game_t *game)
{
    int i = game->cur_fight;
    sfSprite *sp = game->spr[game->fight[i].sprite].spr;

    if (game->fight[i].sprite < 0)
        display_npc(game, game->fight[i].nb_npc, (sfVector2f){1030, 100});
    else {
        sfSprite_setScale(sp, (sfVector2f){5, 5});
        sfSprite_setOrigin(sp,
            (sfVector2f){0, sfSprite_getTextureRect(sp).height});
        sfSprite_setPosition(sp, (sfVector2f){1160, 500});
        sfRenderWindow_drawSprite(game->window.render, sp, NULL);
    }
}

static void end_fight(game_t *game, int i)
{
    char *message;
    sfColor color;

    if (game->fight[i].life <= 0 || game->fight[i].life > 3) {
        message = "Defaite";
        color = sfColor_fromRGBA(100, 0, 0, 200);
    } else {
        color = sfColor_fromRGBA(0, 100, 0, 200);
        message = "Victoire";
    }
    sfRectangleShape_setFillColor(game->ui.quest, color);
    sfRectangleShape_setPosition(game->ui.quest, (sfVector2f){0, 0});
    sfRectangleShape_setOutlineThickness(game->ui.quest, 0);
    sfRectangleShape_setSize(game->ui.quest, (sfVector2f){1600, 900});
    sfRenderWindow_drawRectangleShape(game->window.render,
        game->ui.quest, NULL);
    change_text_size(game, 200);
    display_text(game, message,
        (sfVector2f){100, 150});
}

static void prepare_fight(game_t *game)
{
    sfRectangleShape_setFillColor(game->ui.quest,
        sfColor_fromRGBA(100, 0, 0, 200));
    sfRectangleShape_setPosition(game->ui.quest, (sfVector2f){0, 300});
    sfRectangleShape_setOutlineThickness(game->ui.quest, 0);
    sfRectangleShape_setSize(game->ui.quest, (sfVector2f){1600, 300});
    sfRenderWindow_drawRectangleShape(game->window.render,
        game->ui.quest, NULL);
    change_text_size(game, 50);
    display_text(game, "Appuyez sur une touche pour\n     lancer le combat",
        (sfVector2f){210, 340});
}

int fight_display(game_t *game)
{
    sfRenderWindow_drawSprite(game->window.render, game->spr[BG_FIGHT].spr,
        NULL);
    display_enemy(game);
    display_life(game);
    for (int i = 0; i < 4; ++i)
        display_fight_button(game, i);
    if (game->fight[game->cur_fight].phase == 0)
        prepare_fight(game);
    else if (game->fight[game->cur_fight].phase == 2)
        end_fight(game, game->cur_fight);
    return (SUCCESS);
}