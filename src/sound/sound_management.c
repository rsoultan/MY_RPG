/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** sound_management
*/

#include <SFML/Audio/Sound.h>
#include <SFML/Audio/SoundBuffer.h>
#include "structure.h"
#include "macro.h"

static const char *filepath[NB_SOUND] = {
    "assets/sound/selected_button.wav", "assets/sound/clicked_button.wav",
    "assets/sound/quest_completed.wav", "assets/sound/oof.wav",
    "assets/sound/fight_sound.wav"
};

void update_sound_volume(game_t *game)
{
    for (int i = 0; i < NB_SOUND; ++i)
        sfSound_setVolume(game->audio.sound[i], game->audio.volume_sound);
}

int init_sound(game_t *game)
{
    for (unsigned short int i = 0; i < NB_SOUND; ++i) {
        game->audio.sound[i] = sfSound_create();
        game->audio.buffer[i] = sfSoundBuffer_createFromFile(filepath[i]);
        if (!game->audio.sound[i] || !game->audio.buffer[i])
            return (ERROR);
        sfSound_setBuffer(game->audio.sound[i], game->audio.buffer[i]);
    }
    return (SUCCESS);
}

void play_sound(game_t *game, int i)
{
    sfSound_setVolume(game->audio.sound[i], game->audio.volume_sound);
    sfSound_play(game->audio.sound[i]);
}