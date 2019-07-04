/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** init_music_and_sounds
*/

#include "structure.h"
#include "macro.h"

static const char *tab_music[NB_MUSIC] = {
    "assets/music/main_menu.ogg",
    "assets/music/player_creator.ogg",
    "assets/music/epitech.ogg",
    "assets/music/kevin_quest.ogg",
    "assets/music/chloe_quest.ogg",
    "assets/music/polo_quest.ogg",
    "assets/music/corentin_quest.ogg",
    "assets/music/battle.ogg",
    "assets/music/kevin_battle.ogg",
    "assets/music/chloe_battle.ogg",
    "assets/music/polo_battle.ogg",
    "assets/music/corentin_battle.ogg"
};

void stop_all_music(game_t *game)
{
    for (int i = 0; i < NB_MUSIC; ++i)
        sfMusic_stop(game->audio.music[i]);
}

void update_music_volume(game_t *game)
{
    for (int i = 0; i < NB_MUSIC; ++i)
        sfMusic_setVolume(game->audio.music[i], game->audio.volume_music);
}

int init_music(game_t *game)
{
    for (int i = 0; i < NB_MUSIC; ++i) {
        game->audio.music[i] = sfMusic_createFromFile(tab_music[i]);
        if (!game->audio.music[i])
            return (ERROR);
    }
    return (SUCCESS);
}

void switch_music(int actual, int new, game_t *game)
{
    sfMusic_stop(game->audio.music[actual]);
    if (sfMusic_getStatus(game->audio.music[new]) != sfPlaying) {
        sfMusic_setVolume(game->audio.music[new], game->audio.volume_music);
        sfMusic_play(game->audio.music[new]);
        sfMusic_setLoop(game->audio.music[new], sfTrue);
    }
    if (new < BATTLE_MUSIC)
        game->audio.game_music = new;
}