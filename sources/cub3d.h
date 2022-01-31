/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 09:06:24 by jofelipe          #+#    #+#             */
/*   Updated: 2022/01/31 16:25:42 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include "errors.h"
# include "../libraries/libft/libft.h"
# include "../libraries/minilibx/mlx.h"
# include "time.h"
# include <sys/time.h>

# define TEXTURE3 "assets/images/no_redbrick.xpm"
# define TEXTURE4 "assets/images/we_redbrick.xpm"
# define TEXTURE5 "assets/images/so_redbrick.xpm"
# define TEXTURE6 "assets/images/ea_redbrick.xpm"
# define TEXTURE7 "assets/images/floor_greystone.xpm"
# define TEXTURE8 "assets/images/ceil_bluestone.xpm"

# define PATHLOGO "assets/images/cube_logo.xpm"
# define PATHBG "assets/images/background_menu.xpm"
# define PATHSTART "assets/images/game_start.xpm"
# define PATHOPTION "assets/images/options.xpm"
# define PATHARROW "assets/images/seta.xpm"

# define TEX_WIDTH 64
# define TEX_HEIGHT 64

# define DEBUG 0
# define CLEAR "\e[1;1H\e[2J"

# define SCREEN 0
# define RAYS 1
# define BG 2
# define TEX_NO 3
# define TEX_WE 4
# define TEX_SO 5
# define TEX_EA 6
# define TEX_FL 7
# define TEX_CE 8

# define MEN_LOGO 9
# define MEN_BG 10
# define MEN_START 11
# define MEN_OPT 12
# define MEN_ARROW 13
# define MAP 14
# define PLAYER 15

# define TEX_NB 16

# define MENU 0
# define GAME 1
# define OPTIONS 3

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

# define YOFFSET 250
# define XOFFSET 100

# define OPTYOFFSET 200
# define OPTXOFFSET 100

# define WIN_WIDTH 1024
# define WIN_HEIGHT 768

# define IMG_WIDTH 1024
# define IMG_HEIGHT 768

# define PI 3.14159265
# define TWO_PI 6.28318530

# define EDGE '9'
# define OUTER '!'
# define INNER '@'
# define FILLER '#'
# define VALID_PLAYER "NSEW"
# define VALID_MAP "012"

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_DESTROY_NOTIFY 17
# define K_PRESS 0
# define K_RELEASE 1

# define KEY_ESC 65307
# define KEY_Q 113

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ENTER 65293

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

# define FRAME_DELAY 500

//map
# define MINIMAP_SCALE_FACTOR 0.29
# define TILE_SIZE 64

typedef struct s_line
{
	int	sx;
	int	sy;
	int	dx;
	int	dy;
	int	err;
	int	e2;
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	color;
}	t_line;
//map

//player
# define PLAYER_SIZE 64

typedef struct s_player
{
	float	x;
	float	y;
	float	width;
	float	height;
	int		turn_dir;
	int		walk_dir;
	float	rot_angle;
	float	walk_speed;
	float	turn_speed;
}	t_player;
//player

//line
typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rect;
//line

//ray
# define NUM_RAYS WIN_WIDTH
# define FLT_MAX 3.40282346638528859812e+38F

typedef struct s_hit_data
{
	float	wall_hit_x;
	float	wall_hit_y;
	int		wall_texture;
	float	next_touch_x;
	float	next_touch_y;
	float	hit_distance;
	float	x_intercept;
	float	y_intercept;
	float	x_step;
	float	y_step;
	float	x_to_check;
	float	y_to_check;
	int		found_vert_wall_hit;
}	t_hit_data;

typedef struct s_ray
{
	float	ray_angle;
	float	wall_hit_x;
	float	wall_hit_y;
	float	distance;
	int		was_hit_vertical;
	int		texture;
}	t_ray;
//ray

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_fill
{
	int	x;
	int	y;
	int	xlen;
	int	ylen;
}	t_fill;

typedef struct s_xy
{
	int	x;
	int	y;
}	t_xy;

typedef struct s_menu
{
	int		game;
	int		main;
	int		options;
	int		opt_moves;
	int		opt_rots;
	int		opt_mouses;
	t_bool	sound;
}	t_menu;

typedef struct s_img
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

typedef struct s_menuelem
{
	t_img	*src;
	t_img	*dst;
	int		x;
	int		y;
}	t_menuelem;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win;
}				t_mlx;

typedef struct s_map
{
	int		**matrix;
	char	**charmatrix;
	int		width;
	int		height;
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

typedef struct s_fps
{
	int		fps;
	long	current_time;
	long	last_time;
}	t_fps;

typedef struct s_data
{
	t_fps		fps;
	int			img_width;
	int			img_height;
	int			state;
	char		**map;
	char		**devmap;
	t_mlx		mlx;
	t_img		img[TEX_NB];
	t_menu		menu;
	t_params	params;
	t_player	player;
	t_ray		rays[NUM_RAYS];
}	t_data;

//init
void	init_data(t_data *data);
t_bool	validation(t_data *data, int argc, char **argv);
void	init_img(t_data *data, t_img *img, int width, int heigth);
void	init_xpm(t_data *data, t_img *img, char *image_path);
int		exit_game(t_data *data);

//loop
int		game_loop(t_data *data);

//validation
t_bool	argument_validation(t_data *data, int argc, char **argv);
t_bool	files_validation(t_params *params, char *file);
t_bool	validation_failed(t_params *params, char **map);
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
void	initial_map_cleanup(char **map);
t_bool	is_not_adjacent(char **map, int x, int y, char c);

//debug
void	print_colored_map(char **map);
void	print_map(char **map);

//controller
int		screen_controller(int key, t_data *data, int event_type);
void	keys_wasd(int key, t_data *data, int event_type);
void	keys_menu_wasd(int key, t_data *data);

//keys
int		key_press(int key, t_data *data);
int		key_release(int key, t_data *data);

//raycasting
void	draw_rays(t_data *data);

//map
void	draw_map(t_data *data);
int		map_has_wall_at(float x, float y, t_data *data);
int		map_height(t_data *data);
int		map_width(t_data *data);
int		is_inside_map(float x, float y, t_data *data);
int		get_map_value(int i, int j, t_data *data);

//player
void	draw_player(t_data *data);
void	update_player(t_data *data);

//utils
t_bool	ftex_is_in_set(char c, char *set);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	free_matrix(char **matrix);
char	*ftex_strerase(char *str, char *set);
void	ftex_tr(char *str, char *del, char *ret);
int		get_color(int r, int g, int b);
t_bool	print_error(char *error);
void	tr_matrix(char **matrix, char *del, char *replace);
void	fill(t_img *img, t_fill fill, int color);
t_fill	fillparams(int x, int y, int xlen, int ylen);
void	draw_rect(t_img *img, t_rect rect);
void	normalize_angle(float *angle);
float	distance_between_points(float x1, float y1, float x2, float y2);
void	draw_line(t_img *img, t_line line);
int		middle_x(t_img img);
int		middle_y(t_img img);
void	create_menu_item(t_data *data, int src, int offy, int offx);

//render
void	draw_game(t_data *data);
void	draw_menu(t_data *data);
void	draw_options(t_data *data);
void	draw_background(t_data *data);
void	copy_layer(t_img *from, t_img *to, int x, int y);
int		game_loop(t_data *data);

//fps counter uses time.h and <sys/time.h
void	draw_fps(t_data *data);
long	timestamp(void);

//raycaster
int		is_ray_facing_down(float angle);
int		is_ray_facing_up(float angle);
int		is_ray_facing_right(float angle);
int		is_ray_facing_left(float angle);

void	init_horz_hit_data(float ray_angle,	t_hit_data *horz, t_player player);
void	init_vert_hit_data(float ray_angle,	t_hit_data *vert, t_player player);
void	check_horz_hit(float ray_angle, t_hit_data *horz, t_data *data);
void	check_vert_hit(float ray_angle, t_hit_data *vert, t_data *data);
void	cast_ray(float ray_angle, int col_id, t_data *data);
void	cast_all_rays(t_data *data);
int		get_map_texture(t_hit_data *hit_data, t_data *data);
float	get_hit_distance(t_hit_data *hit_data, t_data *data);

#endif
