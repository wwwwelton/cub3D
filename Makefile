LIBFT_PATH		=	./libraries/libft
LIBFT			=	$(LIBFT_PATH)/libft.a

MINILIBX_PATH	=	./libraries/minilibx
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a

SOURCES_FILES	=	cub3d.c draw_bg.c init.c draw_screen.c init_map.c
SOURCES_FILES	+=	key_press.c utils.c draw_rays.c validation.c
SOURCES_FILES	+=	validate_map.c validation_utils.c

SOURCES_BONUS	=

SOURCES_DIR		=	sources
BONUS_DIR		=	sources_bonus

OBJ_DIR			=	objects

HEADER			=	$(SOURCES_DIR)/cub3d.h
HEADER_BONUS	=	$(BONUS_DIR)/cub3d.h

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))
BONUS_FILES		=	$(addprefix $(BONUS_DIR)/, $(SOURCES_BONUS))

OBJECTS			=	$(SOURCES:$(SOURCES_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJECTS_BONUS	=	$(BONUS_FILES:$(BONUS_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME			=	cub3d
NAME_BONUS		=	cub3d_bonus

CC				=	gcc
RM				=	rm -rf

CFLAGS			=	-O3 -Wall -Wextra -Werror -g3
# CFLAGS			=
LDFLAGS			=	-lXext -lX11 -lm

$(OBJ_DIR)/%.o:		$(SOURCES_DIR)/%.c $(HEADER)
					$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o:		$(BONUS_DIR)/%.c $(HEADER_BONUS)
					$(CC) $(CFLAGS) -c $< -o $@

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
					make && clear && ./$(NAME)

re:					fclean all

.PHONY:				all clean fclean re libft minilibx bonus
