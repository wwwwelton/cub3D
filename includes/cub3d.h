/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 09:06:24 by jofelipe          #+#    #+#             */
/*   Updated: 2022/02/05 23:19:08 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include "textures.h"
# include "defs.h"
# include "errors.h"
# include "graphics.h"
# include "keys.h"
# include "colors.h"
# include "mouse.h"
# include "../libraries/libft/libft.h"
# include "../libraries/minilibx/mlx.h"
# include "time.h"
# include <sys/time.h>

# define CLEAR "\e[1;1H\e[2J"
# define DEBUG 0

# define MENU 0
# define GAME 1
# define OPTIONS 3

# define NORTH 1
# define WEST 2
# define SOUTH 3
# define EAST 4

# define YOFF 250
# define XOFF 100

# define OPTYOFF 200
# define OPTXOFF 100

# define PI 3.14159265
# define TWO_PI 6.28318530

# define EDGE '9'
# define OUTER '!'
# define INNER '@'
# define FILLER '#'
# define VALID_PLAYER "NSEW"
# define VALID_MAP "01"

# define FRAME_DELAY 500

# define MINIMAP_SCALE_FACTOR 0.1
# define TILE_SIZE 64

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
t_bool	is_border(char **map, int x, int y, char c);
int		check_end(char **map, int x, int y, char c);
char	**fetch_map_array(int fd);
t_bool	are_inner_polygons_closed(char **map);
t_xy	get_coordinates(char **map, int x, int y);
t_bool	is_player_inside(char **map, int i, int j);
t_bool	validate_map_characters(char **map);
void	remove_outer_characters(char **map);
t_bool	is_first_character_invalid(int fd, char **tmp);
t_bool	all_params_valid(t_params *params);
void	initial_map_cleanup(char **map);
t_bool	is_char_adjacent_to(char **map, int x, int y, char c);

//debug
void	print_map(char **map);
void	print_colored_map(char **map);

//raycasting
void	draw_rays(t_data *data);

//map
void	draw_map(t_data *data, char **map, int x, int y);
int		map_has_wall_at(float x, float y, t_data *data);
int		map_height(t_data *data);
int		map_width(t_data *data);
int		is_inside_map(float x, float y, t_data *data);
int		get_map_value_at(int i, int j, t_data *data);

//player
void	draw_player(t_data *data);
void	update_player(t_data *data);
void	update_player_matrix(t_data *data);
char	get_player_direction(char **map);
float	set_player_direction(char c);
void	set_player_position(t_data *data, char **map);
void	decrease_step(float *move_step, float *side_step);
void	lock_view_angle(float *view_angle);
void	draw_crosshair(t_data *data);

//utils
t_bool	ftex_is_in_set(char c, char *set);
void	pixel_put(t_img *img, int x, int y, int color);
void	free_matrix(char **matrix);
char	*ftex_strerase(char *str, char *set);
void	ftex_tr(char *str, char *del, char *ret);
t_bool	print_error(char *error);
void	tr_matrix(char **matrix, char *del, char *replace);
void	draw_rect(t_img *img, t_rect rect);
void	normalize_angle(float *angle);
float	get_perp_distance(t_ray ray, t_data *data);
float	distance_between_points(float x1, float y1, float x2, float y2);
void	draw_line(t_img *img, t_line line);
int		middle_x(t_img img);
int		middle_y(t_img img);
void	put_menu_item(t_data *data, int src, int offy, int offx);
int		count_commas(char *str);

//render
void	draw_game(t_data *data);
void	draw_menu(t_data *data);
void	draw_options(t_data *data);
void	draw_background(t_data *data);
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

//wall
void	draw_wall(t_data *data);
void	init_wall_data(t_wall_data *wall, t_player player);
int		get_wall_facing_side(t_ray ray);
int		get_wall_pixel_color(t_img texture, t_wall_data *wall);
void	check_inverse_offset_x(t_ray ray, int *texture_offset_x);
int		get_texture_offset_x(t_ray ray);

#endif
