LIBFT_PATH		=	./libraries/libft
LIBFT			=	$(LIBFT_PATH)/libft.a

MINILIBX_PATH	=	./libraries/minilibx
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a

SOURCES_FILES	=	cub3d.c \
					init.c \
					init_utils.c \
					graphics_utils.c \
					graphics_fill.c \
					graphics_copy_layer.c \
					print_map.c \
					cleanup.c \
					draw_menu.c \
					draw_crosshair.c \
					draw.c \
					draw_utils.c \
					draw_wall.c \
					draw_wall_utils.c \
					game_loop.c \
					keys_utils.c \
					raycaster.c \
					raycaster_init.c \
					raycaster_utils.c \
					raycaster_utils_direction.c \
					utils_map.c \
					validate.c \
					validate_map.c \
					validate_map_inner.c \
					validate_map_utils.c \
					validate_files.c \
					validate_files_utils.c \
					validate_arguments.c \
					validate_utils.c \
					validate_utils2.c \
					utils_player.c \
					utils_player_aux.c \
					utils_tr.c \
					utils_strerase.c \
					utils_math.c \
					utils.c \
					keys_wasd.c \
					keys_controller.c \
					keys_menu_wasd.c

BONUS_FILES	=		cub3d_bonus.c \
					init_bonus.c \
					init_fps_bonus.c \
					init_images_bonus.c \
					init_utils_bonus.c \
					init_sprites_bonus.c \
					graphics_utils_bonus.c \
					graphics_fill_bonus.c \
					graphics_alpha_layer_bonus.c \
					graphics_copy_layer_bonus.c \
					mouse_handler_bonus.c \
					print_map_bonus.c \
					cleanup_bonus.c \
					draw_map_bonus.c \
					draw_menu_bonus.c \
					draw_fps_bonus.c \
					draw_crosshair_bonus.c \
					draw_bonus.c \
					draw_utils_bonus.c \
					draw_sprites_bonus.c \
					draw_sprites_init_bonus.c \
					draw_sprites_utils_bonus.c \
					draw_wall_bonus.c \
					draw_wall_utils_bonus.c \
					game_loop_bonus.c \
					keys_utils_bonus.c \
					raycaster_bonus.c \
					raycaster_init_bonus.c \
					raycaster_utils_bonus.c \
					raycaster_utils_direction_bonus.c \
					sprite_init_bonus.c \
					sprite_update_bonus.c \
					sprite_utils_bonus.c \
					sprite_utils2_bonus.c \
					utils_map_bonus.c \
					utils_map_value_bonus.c \
					validate_bonus.c \
					validate_map_bonus.c \
					validate_map_inner_bonus.c \
					validate_map_utils_bonus.c \
					validate_files_bonus.c \
					validate_files_utils_bonus.c \
					validate_arguments_bonus.c \
					validate_utils_bonus.c \
					validate_utils2_bonus.c \
					utils_player_bonus.c \
					utils_player_aux_bonus.c \
					utils_animation_bonus.c \
					utils_tr_bonus.c \
					utils_strerase_bonus.c \
					utils_time_bonus.c \
					utils_math_bonus.c \
					utils_bonus.c \
					keys_wasd_bonus.c \
					keys_controller_bonus.c \
					keys_menu_wasd_bonus.c \
					keys_actions_bonus.c \

SOURCES_DIR		=	sources
BONUS_DIR		=	sources_bonus

OBJ_DIR			=	objects

HEADERS			=	cub3d.h \
					defines.h \
					textures.h \
					keys.h \
					graphics.h \
					raycaster.h \
					draw.h \

HEADERS_BONUS	=	cub3d_bonus.h \
					defines_bonus.h \
					textures_bonus.h \
					keys_bonus.h \
					graphics_bonus.h \
					mouse_bonus.h \
					raycaster_bonus.h \
					draw_bonus.h \

INCLUDES		=	-I./sources -I./sources/validation -I./sources/graphics \
					-I./sources/keys -I./sources/raycaster \
					-I./sources/draw

INCLUDES_BONUS	=	-I./sources_bonus -I./sources_bonus/validation \
					-I./sources_bonus/graphics -I./sources_bonus/keys \
					-I./sources_bonus/mouse -I./sources_bonus/raycaster \
					-I./sources_bonus/draw

VPATH			=	sources sources/draw sources/validation sources/keys \
					sources/graphics sources/utils sources/init \
					sources/raycaster \
					sources_bonus sources_bonus/draw sources_bonus/validation \
					sources_bonus/keys sources_bonus/graphics \
					sources_bonus/utils sources_bonus/init \
					sources_bonus/raycaster sources_bonus/mouse \
					sources_bonus/sprite \

HEADER_BONUS	=	$(BONUS_DIR)/cub3d_bonus.h

OBJECTS			=	$(SOURCES_FILES:%.c=$(OBJ_DIR)/%.o)
OBJECTS_BONUS	=	$(BONUS_FILES:%.c=$(OBJ_DIR)/%.o)


NAME			=	cub3D
NAME_BONUS		=	cub3D_bonus


CC				=	gcc
RM				=	rm -rf

CFLAGS			=	-Wall -Wextra -Werror -g3
LDFLAGS			=	-lXext -lX11 -lm

$(OBJ_DIR)/%.o:	%.c $(HEADERS) $(HEADERS_BONUS)
				$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES) $(INCLUDES_BONUS)

all:			$(NAME)

bonus:			$(NAME_BONUS)

$(NAME):		$(LIBFT) $(OBJ_DIR) $(MINILIBX) $(OBJECTS) $(HEADERS)
				$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MINILIBX) \
				$(LDFLAGS) -o $(NAME)

$(NAME_BONUS):	$(LIBFT) $(OBJ_DIR) $(MINILIBX) $(OBJECTS_BONUS) \
				$(HEADER_BONUS)
				$(CC) $(CFLAGS) $(OBJECTS_BONUS) $(LIBFT) $(MINILIBX)\
				$(LDFLAGS) -o $(NAME)
				cp $(NAME) $(NAME_BONUS)

$(LIBFT):
				$(MAKE) -C $(LIBFT_PATH) bonus

$(MINILIBX):
				$(MAKE) -C $(MINILIBX_PATH)

$(OBJ_DIR):
				mkdir -p $(OBJ_DIR)

clean:
				$(MAKE) -C $(LIBFT_PATH) clean
				$(MAKE) -C $(MINILIBX_PATH) clean
				$(RM) $(OBJ_DIR)

fclean:			clean
				$(MAKE) -C $(LIBFT_PATH) fclean
				$(RM) $(NAME) $(NAME_BONUS)

run:
				make && clear && ./$(NAME) assets/maps/minimap.cub

runv:
				make && clear && valgrind ./$(NAME) assets/maps/minimap.cub

runb:
				make bonus && clear && ./$(NAME_BONUS) assets/maps/minimap.cub

runvb:
				make bonus && clear && valgrind ./$(NAME_BONUS) assets/maps/minimap.cub

re:				fclean all

.PHONY:			all clean fclean re libft minilibx bonus
