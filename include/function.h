/*
** EPITECH PROJECT, 2019
** workshop
** File description:
** workshop
*/

#ifndef FUNCTION_H
    #define FUNCTION_H
    #include <SFML/Window/Event.h>
    #include "structure.h"

typedef struct s_particles particles_t;

/* Manage functions */
void manage_display(game_t *);
void manage_event(game_t *);
void manage_update(game_t *);
void manage_player_hair_color(game_t *, sfEvent);
void manage_player_skin_color(game_t *, sfEvent);
void manage_player_clothes(game_t *, sfEvent);
void manage_player_orientation(game_t *);
void manage_player_step(game_t *);
int manage_quest(game_t *game);
void manage_quest_ui(game_t *game);
void manage_ui(game_t *game);

/* Update functions */
void update_music_volume(game_t *);
void update_sound_volume(game_t *);
void update_view(game_t *);
void intro_update(game_t *game);
void update_ratio_window(game_t *game);
void update_button_rect(game_t *game, int index);
void update_inv_shape_rect(game_t *game, sfFloatRect *rect);
void time_forward(game_t *);

/* Display functions */
int credits_display(game_t *);
int fight_display(game_t *);
int game_display(game_t *);
int game_over_display(game_t *);
int introduction_display(game_t *);
int inventory_fight_display(game_t *);
int main_menu_display(game_t *);
int pause_display(game_t *);
int save_display(game_t *);
int settings_display(game_t *);
void display_game_character(game_t *game);
void display_creator_character(game_t *game);
int display_player_creator(game_t *);
void display_text(game_t *, const char *, sfVector2f);
void display_map(game_t *);
void display_map_npc(game_t *, int);
void display_line(game_t *, int);
void display_inventory(game_t *);
int display_quest(game_t *game);
void display_npc(game_t *, int, sfVector2f);
void display_particles(particles_t *part, window_t *win);
void display_particles_on_map(particles_t *part, cam_t *cam);
void display_life(game_t *game);
int display_htp(game_t *game);

/* Button functions */
void volume_button(game_t *, int, int, int);
void fps_button_event(game_t *, sfEvent, int, unsigned int);
void button_event(game_t *, sfEvent, int, void(*)(game_t*));
void draw_button(game_t *, sfVector2f, sfVector2f, int);
void play_button_function(game_t *);
void settings_button_function(game_t *);
void scale_button(game_t *);
void cancel_button(game_t *);
void confirm_button(game_t *);
void resume_button_function(game_t *game);
void main_menu_button_function(game_t *game);
void htp_button(game_t *game);

/* Player functions */
int player_creator_event(game_t *);
void player_inputs(game_t *, sfEvent);
void player_movement(game_t *);
void skin_plus(game_t *);
void skin_less(game_t *);
void clothes_plus(game_t *);
void clothes_less(game_t *);
void hair_plus(game_t *);
void hair_less(game_t *);
void tp_player(game_t *);
void set_character_scale(game_t *, sfVector2f);
void set_character_pos(game_t *, sfVector2f);

/* Init functions */
int init_button(game_t *);
int init_text(game_t *);
int init_window(game_t *);
int init_game_time(game_t *);
int init_music(game_t *);
int init_sprite(game_t *);
void init_character(game_t *);
char init_maps(game_t *);
int init_sound(game_t *);
int init_npc(game_t *);
int init_view(game_t *);
int init_tp(game_t *);
int init_inventory(game_t *game);
int init_fight(game_t *game);
int init_quest(game_t *game);
int init_ui(game_t *game);
int init_particles(particles_t *part);
int create_game_structure(game_t *);
int get_fight(fight_t *fight, char *line, int size);
int get_state(fight_t *fight, char *line, int size);
int get_fight_npc(fight_t *fight, char *line, int size);
int get_lines(npc_t *npc, char *line);
int get_coo(npc_t *npc, char *line);
int get_map_id(npc_t *npc, char *line);
int get_stat(npc_t *npc, char *line);
int get_skin(npc_t *npc, char *line);
int get_music(fight_t *fight, char *line, int size);

/* Music and sound functions */
void play_sound(game_t *, int);
void switch_music(int, int, game_t *);
void stop_all_music(game_t *);

/* Text functions */
void change_text_color(game_t *, sfColor);
void change_text_size(game_t *, unsigned int);
void change_text_font(game_t *, int);

/* Sprite functions */
void draw_sprite(game_t *, int, sfVector2f, sfVector2f);
void scale_sprite(game_t *);
int get_sprite(fight_t *fight, char *line, int size);

/* Event functions */
int introduction_event(game_t *);
int credits_event(game_t *);
int fight_event(game_t *);
int game_event(game_t *);
int main_menu_event(game_t *);
int settings_event(game_t *);
int pause_event(game_t *);
int save_event(game_t *);
void global_event(game_t *, sfEvent);
int event_htp(game_t *game);

/* Scene functions */
void go_main_menu_scene(game_t *);
void go_settings_scene(game_t *);

/* Parameters functions*/
void low_fps(game_t *);
void epitech_fps(game_t *);
void high_fps(game_t *);

/* Inventory and items functions */
bool item_is_in_inv(game_t *game, char *name);
sfSprite *create_inventory_sprite(sfSprite *spr, unsigned short int index);
void add_item(game_t *, char *, sfSprite *);
void remove_item(game_t *, char *);

/* Map / particles / hitbox functions */
int npc_hitbox(game_t *);
int map_hitbox(game_t *);
void choose_tile_bg(char tile, unsigned int pos[2], game_t *game);
void choose_tile_fg(char tile, unsigned int pos[2], game_t *game);
void choose_tile_obj(char tile, unsigned int pos[2], game_t *game);
void draw_tile(sprite_t *tile, unsigned int pos[2], game_t *game, sfIntRect);
void intro_animation(particles_t *part);
void put_pixel(sfUint8 [BUF_PART_SIZE * 4], unsigned int, sfColor);
int print_bg_intro(particles_t *part);
int print_inclined_square(particles_t *part);
int print_tansition(particles_t *part);
void clear_buffer(sfUint8 *buf, sfColor color);
void particles_toilets(particles_t *part, window_t *win);
void menu_bg_part_update(game_t *game);
void do_map_particles(game_t *game);

/* quest functions */
void npc_dialogue(game_t *);
void next_step_quest(game_t *game, unsigned short int index);
void next_quest(game_t *game, unsigned short int index);
void fight_quest(game_t *game, int i);
int discover_epitech(game_t *game);
void dialogue_quest(game_t *game, short index);
int chloe_quest(game_t *game);
int polo_quest(game_t *game);
int kevin_quest(game_t *game);
int corentin_quest(game_t *game);
int end_quest(game_t *game);
unsigned short int get_index_active_quest(game_t *game);

/* Free */
void free_all(game_t *game);
void free_part(game_t *game);
void free_window(window_t window);
void free_cam(cam_t cam);
void free_text(text_t text);
void free_time(game_time_t time);
void free_quest(quest_t *quest);
void free_text(text_t text);
void free_npc(npc_t *npc);
void free_fight(fight_t *fight);
void free_audio(audio_t audio);
void free_ui(ui_t ui);

/* Other functions */
void small_window(game_t *);
void high_window(game_t *);
void choose_direction(game_t *game, int i);
char *check_line_size(char *line, int line_size, int name_size);
void close_game(game_t *);

/* String manipulation functions (libmy) */
char **parse_file(const char *);
int my_strlen(char const *);
char *my_strcat(char *, char *);
char **my_str_to_word_array(char *, char);
int my_strcmp(const char *, const char *);
void free_array(char **);
unsigned int my_arrlen(char **);
int my_putchar(char);
int my_putstr(char const *);
void print_array(char **, char);
int my_strncmp(const char *,const char *, int);
int my_atoi(char *);
int my_str_isnum(char const *);
char *clean_str(char *);
char *my_itoa(unsigned int);
char *my_revstr(char *);
char *my_strcpy(char const *src);

#endif