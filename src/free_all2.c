/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** free_all2
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

void free_ui(ui_t ui)
{
    if (ui.quest)
        sfRectangleShape_destroy(ui.quest);
}

void free_audio(audio_t audio)
{
    if (audio.music) {
        for (unsigned short int i = 0; i < NB_MUSIC; ++i)
            audio.music[i] ? sfMusic_destroy(audio.music[i]) : 0;
    }
    if (audio.sound) {
        for (unsigned short int i = 0; i < NB_SOUND; ++i)
            audio.sound[i] ? sfSound_destroy(audio.sound[i]) : 0;
    }
    if (audio.buffer) {
        for (unsigned short int i = 0; i < NB_SOUND; ++i)
            audio.buffer[i] ? sfSoundBuffer_destroy(audio.buffer[i]) : 0;
    }
}

void free_fight(fight_t *fight)
{
    if (!fight)
        return;
    for (unsigned short int i = 0; i < NB_FIGHT; ++i) {
        if (fight[i].fight)
            free(fight[i].fight);
        if (fight[i].npc)
            free(fight[i].npc);
    }
}

void free_npc(npc_t *npc)
{
    if (!npc)
        return;
    for (unsigned short int i = 0; i < NB_NPC; ++i) {
        if (npc[i].lines)
            free_array(npc[i].lines);
    }
}

void free_quest(quest_t *quest)
{
    if (!quest)
        return;
    for (unsigned short int i = 0; i < NB_QUEST; ++i) {
        if (quest[i].info)
            free_array(quest[i].info);
        if (quest[i].name)
            free(quest[i].name);
    }
}