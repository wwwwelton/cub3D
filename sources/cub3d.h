#ifndef _CUB3D_H
# define _CUB3D_H

# include <stdio.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include "errors.h"
# include "../libraries/libft/libft.h"
# include "../libraries/minilibx/mlx.h"

# define TEXTURE3 "assets/images/no_redbrick.xpm"
# define TEXTURE4 "assets/images/we_redbrick.xpm"
# define TEXTURE5 "assets/images/so_redbrick.xpm"
# define TEXTURE6 "assets/images/ea_redbrick.xpm"
# define TEXTURE7 "assets/images/floor_greystone.xpm"
# define TEXTURE8 "assets/images/ceil_bluestone.xpm"

# define TEX_WIDTH 64
# define TEX_HEIGHT 64

# define DEBUG 1

# define SCREEN 0
# define RAYS 1
# define BG 2
# define TEX_NO 3
# define TEX_WE 4
# define TEX_SO 5
# define TEX_EA 6
# define TEX_FL 7
# define TEX_CE 8
# define TEX_NB 9

# define MENU 0
# define GAME 1

# define NORTH 1
# define WEST 2
# define SOUTH 3
# define EAST 4

# define RED 0xff0000
# define RED_BLACK 0xd20000
# define YELLOW 0xE3E316
# define BLACK 0x000000
# define BLACKB 0x010101
# define WHITE 0xFFFFFF
# define GRAY 0x484848
# define GRAYC 0x383838
# define GRAYF 0x707070
# define PINK 0xff00fe
# define BLUE 0x0171FF

# define WIN_WIDTH 1024
# define WIN_HEIGHT 768

# define IMG_WIDTH 1024
# define IMG_HEIGHT 768

# define PLAYER_SIZE 10
# define PLAYER_CENTER 4
# define LINE_LENGTH 3

# define EDGE '9'
# define OUTER '!'
# define INNER '@'
# define FILLER '#'
# define VALID_PLAYER "NSEW"
# define VALID_MAP "012"

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_DESTROY_NOTIFY 17

# define KEY_ESC 65307
# define KEY_Q 113

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_xy
{
	int	x;
	int	y;
}	t_xy;

typedef struct	s_img
{
	int			bpp;
	int			size_l;
	int			endian;
	int			width;
	int			height;
	int			color;
	void		*img_ptr;
	int			*dump;
}				t_img;

typedef struct	s_player
{
	double	pos_x;
	double	pos_y;
	double	move_speed;
	double	rot_speed;
	t_img	img_player;
}				t_player;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;
}				t_mlx;

typedef struct s_ray
{
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_ray;

typedef struct s_map
{
	int		**matrix;
	char	**charmatrix;
	int	width;
	int	height;
}	t_map;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_params
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	int		ceilcolor;
	int		floorcolor;
}	t_params;

typedef struct	s_data
{
	int			img_width;
	int			img_height;
	int			state;
	t_map		map;
	t_mlx		mlx;
	t_ray		ray;
	t_player	player;
	t_img		img[TEX_NB];
	t_params	params;
}	t_data;

//init
void	init_data(t_data *data, char **argv);
t_bool	validation(t_data *data, int argc, char **argv);
void	init_img(t_data *data, t_img *img, int width, int heigth);
int		exit_game(t_data *data);
void	init_xpm(t_data *data, t_img *img, char *image_path);
void	init_map(t_data *data, char **argv);

//validation
t_bool	argument_validation(t_data *data, int argc, char **argv);
t_bool	files_validation(t_params *params, char *file);
t_bool	validation_cleanup(t_params *params);
void	clean_gnl(char *tmp, int fd);

//map validation
t_bool	is_player_polygon_closed(char **map);
t_bool	crawl_polygon(char **map, int x, int y, char fill);
t_bool	recurse_polygon(char **map, int x, int y);
void	outline_polygon(char **map);
void	outline_useless_walls(char **map);
t_bool	is_char_adjacent(char **map, int x, int y, char c);
int		check_end(char **map, int x, int y, char c);
char	**fetch_map_array(char **argv);
t_bool	are_inner_polygons_closed(char **map);
t_xy	get_coordinates(char **map, int x, int y);
t_bool	is_player_inside(char **map, int i, int j);
t_bool	validate_map_characters(char **map);
void	remove_outer_characters(char **map);
t_bool	is_first_character_invalid(int fd, char **tmp);
t_bool	all_params_valid(t_params *params);

//debug
void	print_colored_map(char **map);
void	print_map(char **map);

//controller
int		key_press(int key, t_data *data);
int		screen_controller(int key, t_data *data);

//raycasting
void	draw_rays(t_data *data);

//utils
t_bool	ftex_is_in_set(char c, char *set);
void	fill_color(t_img *img, int color);
int		get_pixel_color(t_img *img, int x, int y, int width, int height);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	free_matrix(char **matrix);
char	*ftex_strerase(char *str, char *set);
void	ftex_tr(char *str, char *del, char *ret);
int		get_color(int r, int g, int b);
t_bool	print_error(char *error);
void	tr_matrix(char **matrix, char *del, char *replace);

//render
void	draw_screen(t_data *data);
void	draw_background(t_data *data);
void	copy_layer(t_img *img_src, t_img *img_dst, int color);


int		loop_hook(t_data *data);


#endif
