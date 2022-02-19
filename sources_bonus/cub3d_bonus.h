/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 09:06:24 by jofelipe          #+#    #+#             */
/*   Updated: 2022/02/19 04:20:43 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <stdio.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include "defines_bonus.h"
# include "errors_bonus.h"
# include "textures_bonus.h"
# include "structs_bonus.h"
# include "graphics_bonus.h"
# include "raycaster_bonus.h"
# include "draw_bonus.h"
# include "keys_bonus.h"
# include "mouse_bonus.h"
# include "../libraries/libft/libft.h"
# include "../libraries/minilibx/mlx.h"
# include <time.h>
# include <sys/time.h>

//init
void	init_data(t_data *data);
t_bool	validation(t_data *data, int argc, char **argv);
void	init_img(t_data *data, t_img *img, int width, int heigth);
void	init_xpm(t_data *data, t_img *img, char *image_path, t_bool *valid);
t_bool	init_fps_textures(t_data *data);
t_bool	init_sprite_textures(t_data *data);
t_bool	init_xpm_textures(t_data *data);
void	init_fps(t_data *data);
int		exit_game(t_data *data);

//loop
int		game_loop(t_data *data);
void	update_player(t_data *data);
void	update_player_matrix(t_data *data);
void	sprite_update(t_data *data);

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
t_bool	is_char_adjacent_to_set(char **map, int x, int y, char *set);

//debug
void	print_map(char **map);
void	print_colored_map(char **map);

//player
char	get_player_direction(char **map);
float	set_player_direction(char c);
void	set_player_position(t_data *data, char **map);
void	decrease_step(float *move_step, float *side_step);
void	lock_view_angle(float *view_angle);
void	draw_crosshair(t_data *data);

//utils
char	*ftex_strerase(char *str, char *set);
t_bool	ftex_is_in_set(char c, char *set);
void	ftex_tr(char *str, char *del, char *ret);
void	tr_matrix(char **matrix, char *del, char *replace);
void	free_matrix(char **matrix);
void	pixel_put(t_img *img, int x, int y, int color);
t_bool	print_error(char *error);
int		count_commas(char *str);
int		middle_x(t_img img);
int		middle_y(t_img img);
int		map_height(t_data *data);
int		map_width(t_data *data);
char	get_map_value_at(int i, int j, t_data *data);
void	set_map_value_at(int i, int j, char value, t_data *data);
int		get_map_value_at_pos(float x, float y, t_data *data);
void	set_map_value_at_pos(float x, float y, char value, t_data *data);
int		map_has_wall_at(float x, float y, t_data *data);
int		is_inside_map(float x, float y, t_data *data);
void	put_menu_item(t_data *data, int src, int offy, int offx);
void	fill_menu_item(t_data *data, int i, int offy, int offx);
void	sync_time(t_data *data);

//render
void	draw_game(t_data *data);
void	draw_menu(t_data *data);
void	draw_options(t_data *data);
int		game_loop(t_data *data);

//fps
void	draw_fps(t_data *data);
long	timestamp(void);

//sprite
void	init_visible_sprites(t_data *data);
void	sort_visible_sprites(t_sprite *visible_sprites, int num_sprites);
int		map_has_sprite_at(float x, float y, t_data *data);
void	init_sprites(char **map, t_data *data);
float	get_sprite_dist(t_sprite sprite, t_data *data);
float	get_angle_sprite_player(t_sprite sprite, t_data *data);
int		get_sprite_texture(int id);
void	animate_sprites(t_data *data);

#endif
