/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** structure
*/

#ifndef STRUCTURE_H
    #define STRUCTURE_H
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Graphics/Sprite.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/System/Clock.h>
    #include <SFML/Audio/Music.h>
    #include <stdbool.h>
    #include <time.h>
    #include "macro.h"
    #include "enum.h"
    #include "map.h"
    #include "particles.h"

typedef struct s_fight {
    char *npc;
    char *fight;
    int music;
    int i;
    int nb_npc;
    short int state;
    short int sprite;
    short int life;
    float time;
    char key;
    char phase;
} fight_t;

typedef struct s_sprite {
    sfSprite *spr;
    sfTexture *tex;
} sprite_t;

typedef struct s_tp {
    sfVector2f pos;
    sfVector2f tp;
    unsigned short int current_id;
    unsigned short int tp_id;
} tp_t;

typedef struct s_inv {
    char *item_name;
    sfRectangleShape *rect_shape;
    sfSprite *spr;
    unsigned short int nb_item;
} inv_t;

typedef struct s_cam {
    sfView *view;
    sfFloatRect rect;
    sfRenderTexture *rt;
    sfSprite *sp;
} cam_t;

typedef struct s_map_tile {
    sprite_t *sprite;
    sfIntRect rect;
} map_tile_t;

typedef struct s_character {
    sfVector2f pos;
    char skin[NB_SKIN];
    char status[NB_STATUS];
    short int dialogue;
} character_t;

typedef struct s_npc {
    character_t skin;
    sfVector2f pos;
    unsigned short int map;
    char **lines;
    unsigned short int voice_line;
} npc_t;

typedef struct s_object {
    sfSprite *spr;
    sfFloatRect rect;
    sfVector2f pos;
    unsigned short int depth;
} object_t;

typedef struct s_button {
    sfRectangleShape *rect_shape;
    sfVector2f pos;
    sfVector2f scale;
    sfVector2f size;
    sfFloatRect rect;
} button_t;

typedef struct s_game_time {
    sfClock *game_clock;
    float clock_time;
    float seconds;
    sfTime time;
    float fac;
} game_time_t;

typedef struct s_text {
    sfFont *font[NB_FONT];
    sfText *text;
}  text_t;

typedef struct s_window {
    sfRenderWindow *render;
    sfVideoMode mode;
    sfVector2i pos_mouse;
    unsigned int fps;
    sfVector2f ratio;
} window_t;

typedef struct s_input {
    sfVector2f pos;
    sfVector2f move;
    unsigned short int move_mem;
} input_t;

typedef struct s_audio {
    sfMusic *music[NB_MUSIC];
    sfSound *sound[NB_SOUND];
    sfSoundBuffer *buffer[NB_SOUND];
    int game_music;
    float volume_music;
    float volume_sound;
} audio_t;

typedef struct s_quest {
    char **info;
    char *name;
    unsigned short int goal_index;
    bool is_active;
    bool done;
} quest_t;

typedef struct s_ui {
    sfRectangleShape *quest;
    bool display_quest;
    bool display_inv;
} ui_t;

typedef struct s_game {
    char ***maps[NB_MAPS_TYPE];
    tp_t tp[NB_TP];
    button_t button[NB_BUTTON];
    sprite_t spr[NB_SPRITE];
    inv_t inv[NB_SLOT];
    quest_t quest[NB_QUEST];
    npc_t npcs[NB_NPC];
    fight_t fight[NB_FIGHT];
    audio_t audio;
    ui_t ui;
    character_t player;
    game_time_t game_time;
    text_t text;
    cam_t cam;
    window_t window;
    input_t inputs;
    particles_t part;
    unsigned short int map_id;
    unsigned short int scene;
    unsigned short int old_scene;
    unsigned short int screen;
    unsigned short int cur_fight;
    unsigned short int htp_index;
} game_t;

typedef struct s_scene {
    int (*ptr)(game_t*);
    unsigned short int index;
} scene_t;

#endif
