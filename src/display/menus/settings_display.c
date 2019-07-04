/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** settings_display
*/

#include <stdlib.h>
#include "structure.h"
#include "function.h"

static int settings_text(game_t *game)
{
    char *str_music = my_itoa(game->audio.volume_music);
    char *str_sound = my_itoa(game->audio.volume_sound);

    if (!str_music || !str_sound)
        return (ERROR);
    display_text(game, "Options:", (sfVector2f){690, 25});
    display_text(game, "Volume des musiques:", (sfVector2f){570, 100});
    display_text(game, str_music, (sfVector2f){750, 170});
    display_text(game, "Volume des sons:", (sfVector2f){610, 350});
    display_text(game, str_sound, (sfVector2f){750, 415});
    display_text(game, "Image par Seconde:", (sfVector2f){570, 520});
    display_text(game, "30", (sfVector2f){340, 625});
    display_text(game, "42", (sfVector2f){750, 625});
    display_text(game, "60", (sfVector2f){1150, 625});
    free(str_music);
    free(str_sound);
    return (SUCCESS);
}

static void settings_button(game_t *game)
{
    draw_button(game, (sfVector2f){820, 180}, (sfVector2f){3, 3},
        VOLUME_MUSIC_PLUS);
    draw_button(game, (sfVector2f){670, 180}, (sfVector2f){3, 3},
        VOLUME_MUSIC_LESS);
    draw_button(game, (sfVector2f){670, 425}, (sfVector2f){3, 3},
        VOLUME_SOUND_LESS);
    draw_button(game, (sfVector2f){820, 425}, (sfVector2f){3, 3},
        VOLUME_SOUND_PLUS);
    draw_button(game, (sfVector2f){725, 725}, (sfVector2f){10, 10}, CONFIRM);
    draw_button(game, (sfVector2f){190, 600}, (sfVector2f){3, 3},
        LOW_FPS);
    draw_button(game, (sfVector2f){590, 600}, (sfVector2f){3, 3},
        EPITECH_FPS);
    draw_button(game, (sfVector2f){990, 600}, (sfVector2f){3, 3},
        HIGH_FPS);
    volume_button(game, VOLUME_MUSIC_LESS, -1, 0);
    volume_button(game, VOLUME_MUSIC_PLUS, 1, 0);
    volume_button(game, VOLUME_SOUND_LESS, 0, -1);
    volume_button(game, VOLUME_SOUND_PLUS, 0, 1);
}

int settings_display(game_t *game)
{
    sfRenderWindow_clear(game->window.render, (sfColor){80, 120, 255, 255});
    time_forward(game);
    display_particles(&game->part, &game->window);
    settings_button(game);
    if (settings_text(game))
        return (ERROR);
    return (SUCCESS);
}