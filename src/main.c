/*
** EPITECH PROJECT, 2019
** workshop
** File description:
** main
*/

#include <SFML/Graphics/View.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/RenderTexture.h>
#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#include "macro.h"
#include "structure.h"

static void preset_game3(game_t *game)
{
    game->window.render = NULL;
    game->part.logo = NULL;
    game->part.entity = NULL;
}

static void preset_game2(game_t *game)
{
    for (int i = 0; i < NB_FIGHT; i++) {
        game->fight[i].fight = NULL;
        game->fight[i].npc = NULL;
    }
    for (int i = 0; i < NB_MUSIC; i++)
        game->audio.music[i] = NULL;
    for (int i = 0; i < NB_SOUND; i++) {
        game->audio.sound[i] = NULL;
        game->audio.buffer[i] = NULL;
    }
    game->ui.quest = NULL;
    game->game_time.game_clock = NULL;
    game->text.text = NULL;
    for (int i = 0; i < NB_FONT; i++)
        game->text.font[i] = NULL;
    game->cam.rt = NULL;
    game->cam.sp = NULL;
    game->cam.view = NULL;
    preset_game3(game);
}

static void preset_game(game_t *game)
{
    for (int i = 0; i < 3; i++)
        game->maps[0] = NULL;
    for (int i = 0; i < NB_BUTTON; i++)
        game->button[i].rect_shape = NULL;
    for (int i = 0; i < NB_SPRITE; i++) {
        game->spr[i].spr = NULL;
        game->spr[i].tex = NULL;
    }
    for (int i = 0; i < NB_SLOT; i++) {
        game->inv[i].rect_shape = NULL;
        game->inv[i].spr = NULL;
    }
    for (int i = 0; i < NB_QUEST; i++) {
        game->quest[i].info = NULL;
        game->quest[i].name = NULL;
    }
    for (int i = 0; i < NB_NPC; i++)
        game->npcs[i].lines = NULL;
    preset_game2(game);
}

static int my_rpg(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (!game)
        return (ERROR);
    preset_game(game);
    if (create_game_structure(game) == ERROR) {
        free_all(game);
        return (ERROR);
    }
    while (sfRenderWindow_isOpen(game->window.render)) {
        manage_update(game);
        manage_event(game);
        manage_display(game);
    }
    free_all(game);
    return (SUCCESS);
}

int main(int ac, char **av)
{
    (void)av;
    if (ac != 1)
        return (84);
    return (my_rpg());
}