LIBFT_PATH		=	./libraries/libft
LIBFT			=	$(LIBFT_PATH)/libft.a

MINILIBX_PATH	=	./libraries/minilibx
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a

SOURCES_FILES	=	cub3d.c \
					init.c \
					init_utils.c \
					graphics_utils.c \
					graphics_draw_line.c \
					graphics_draw_rect.c \
					graphics_fill.c \
					print_map.c \
					cleanup.c \
					draw_bg.c \
					draw_map.c \
					draw_player.c \
					draw_rays.c \
					draw_menu.c \
					draw.c \
					draw_utils.c \
					game_loop.c \
					keys_utils.c \
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
					utils_tr.c \
					utils_strerase.c \
					utils_math.c \
					utils.c \
					keys_wasd.c \
					keys_controller.c \
					keys_menu_wasd.c

SOURCES_BONUS	=

SOURCES_DIR		=	sources
BONUS_DIR		=	sources_bonus

OBJ_DIR			=	objects

HEADER			=	$(SOURCES_DIR)/cub3d.h
HEADER_BONUS	=	$(BONUS_DIR)/cub3d.h


OBJECTS			=	$(SOURCES_FILES:%.c=$(OBJ_DIR)/%.o)
OBJECTS_BONUS	=	$(BONUS_FILES:$(BONUS_DIR)/%.c=$(OBJ_DIR)/%.o)

VPATH			=	sources sources/draw sources/validation sources/keys \
					sources/graphics sources/utils sources/init

NAME			=	cub3D
NAME_BONUS		=	cub3D_bonus

INCLUDES		=	-I./sources -I./sources/validation
CC				=	gcc
RM				=	rm -rf

CFLAGS			=	-Wall -Wextra -Werror -g3
# CFLAGS			=
LDFLAGS			=	-lXext -lX11 -lm

$(OBJ_DIR)/%.o:		%.c $(HEADER)
					$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJ_DIR)/%.o:		%.c $(HEADER_BONUS)
					$(CC) $(CFLAGS) -c $< -o $@ -I ./sources_bonus

all:				$(NAME)

bonus:				$(NAME_BONUS)

$(NAME):			$(LIBFT) $(OBJ_DIR) $(MINILIBX) $(OBJECTS) $(HEADER)
					$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MINILIBX) \
					$(LDFLAGS) -o $(NAME)

$(NAME_BONUS):		$(LIBFT) $(OBJ_DIR) $(MINILIBX) $(OBJECTS_BONUS) \
					$(HEADER_BONUS)
					$(CC) $(CFLAGS) $(OBJECTS_BONUS) $(LIBFT) $(MINILIBX) \
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

fclean:				clean
					$(MAKE) -C $(LIBFT_PATH) fclean
					$(RM) $(NAME) $(NAME_BONUS)

run:
					make && clear && ./$(NAME) assets/maps/minimap.cub

runv:
					make && clear && valgrind ./$(NAME) assets/maps/minimap.cub

re:					fclean all

.PHONY:				all clean fclean re libft minilibx bonus
