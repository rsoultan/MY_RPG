SRC	=	lib/my/my_itoa.c \
		lib/my/my_str_isnum.c \
		lib/my/free_array.c \
		lib/my/my_strcpy.c \
		lib/my/my_arrlen.c \
		lib/my/print_array.c \
		lib/my/my_strncmp.c \
		lib/my/my_strcmp.c \
		lib/my/my_atoi.c \
		lib/my/my_str_to_word_array.c \
		lib/my/my_putstr.c \
		lib/my/string.c \
		lib/my/clean_str.c \
		lib/my/my_revstr.c \
		lib/my/my_putchar.c \
		src/game_structure.c \
		src/free_all3.c \
		src/free_all.c \
		src/main.c \
		src/free_all2.c \
		src/update/time.c \
		src/update/window_update.c \
		src/update/update_player_pos.c \
		src/how_to_play/how_to_play.c \
		src/inventory/sprite_inventory.c \
		src/inventory/init_inventory.c \
		src/inventory/display_inventory.c \
		src/inventory/inventory_management.c \
		src/display/manage_display.c \
		src/display/menus/main_menu_display.c \
		src/display/menus/menu_bg_part.c \
		src/display/menus/pause_display.c \
		src/display/menus/settings_display.c \
		src/display/game/map_depth_display.c \
		src/display/game/introduction_display.c \
		src/display/game/game_display.c \
		src/display/game/map_display.c \
		src/display/fights/fight_display_bis.c \
		src/display/fights/fight_display.c \
		src/camera/update_view.c \
		src/camera/init_view.c \
		src/window/update_size_window.c \
		src/window/init_window.c \
		src/introduction/manage_introduction.c \
		src/event/player_inputs.c \
		src/event/tp_player.c \
		src/event/manage_event.c \
		src/event/menus/pause_event.c \
		src/event/menus/main_menu_event.c \
		src/event/menus/settings_event.c \
		src/event/game/introduction_event.c \
		src/event/game/game_event.c \
		src/event/fights/fight_event.c \
		src/event/fights/init_fight.c \
		src/event/fights/init_fight_bis.c \
		src/sound/sound_management.c \
		src/particles/manage_particles.c \
		src/particles/toilets_particles.c \
		src/map/parsing.c \
		src/map/init_map.c \
		src/map/map_hit_box.c \
		src/map/init_tp.c \
		src/font/init_text.c \
		src/font/text_function.c \
		src/user_interface/init_user_interface.c \
		src/user_interface/manage_ui.c \
		src/button/manage_button.c \
		src/button/init_button.c \
		src/button/params/fps_button.c \
		src/button/params/volume_button.c \
		src/button/button_types/window_button.c \
		src/button/button_types/confirm_button.c \
		src/button/button_types/cancel_button.c \
		src/button/button_types/function_button.c \
		src/quest/init_quest.c \
		src/quest/check_quest.c \
		src/quest/dialogue_quest.c \
		src/quest/manage_quest.c \
		src/quest/fight_quest.c \
		src/quest/display_quest.c \
		src/quest/end_quest.c \
		src/sprite/draw_sprite.c \
		src/sprite/init_sprite.c \
		src/sprite/scale_sprite.c \
		src/npc/display_npc.c \
		src/npc/init_npc.c \
		src/npc/npc_hit_box.c \
		src/npc/init_npc_bis.c \
		src/npc/npc_dialogue.c \
		src/character/move_character.c \
		src/character/display_character.c \
		src/character/init_character.c \
		src/character/player_creator/character_creation_less.c \
		src/character/player_creator/player_creator_event.c \
		src/character/player_creator/character_creation_plus.c \
		src/character/player_creator/display_player_creator.c \
		src/music/music_management.c \

OBJ		=	$(SRC:.c=.o)

GREEN	=	\033[3m

ITALIC	=	\033[32m

DEFAULT	=	\033[0m

CC		=	@gcc -o

NAME	=	my_rpg_launcher

CFLAGS	=	-W			\
			-Wall		\
			-Wextra		\
			-Iinclude	\

LDFLAGS	=	-lcsfml-graphics	\
			-lcsfml-window		\
			-lcsfml-audio		\
			-lcsfml-system		\
			-lm

$(NAME):	$(OBJ)
		$(CC) $(NAME) $(OBJ) $(LDFLAGS)

all:		$(NAME)
	@echo -e "$(GREEN)$(ITALIC)>>>Compiled successfuly$(DEFAULT)"

clean:
	@rm -f $(OBJ)
	@echo -e "$(GREEN)$(ITALIC)>>>Cleaned objects successfuly$(DEFAULT)"

fclean:	clean
	@rm -f $(NAME)
	@echo -e "$(GREEN)$(ITALIC)>>>Cleaned binaries succesfully$(DEFAULT)"

re:	fclean all

test:	re
	@./$(NAME)

debug:		CFLAGS	+=	-g
debug:		re
	valgrind ./$(NAME)

.PHONY: all clean fclean re debug