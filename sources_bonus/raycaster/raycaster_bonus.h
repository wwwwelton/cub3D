/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 21:42:58 by jofelipe          #+#    #+#             */
/*   Updated: 2022/02/16 18:29:15 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_BONUS_H
# define RAYCASTER_BONUS_H

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

typedef struct s_wall_data
{
	float	height;
	int		top_y;
	int		bottom_y;
	float	perp_distance;
	float	dist_proj_plane;
	int		pixel_color;
	int		texture_offset_x;
	int		texture_offset_y;
	int		distance_from_top;
	int		win_height;
}	t_wall_data;

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
char	get_map_texture(t_hit_data *hit_data, t_data *data);
float	get_hit_distance(t_hit_data *hit_data, t_data *data);

//utils
void	normalize_angle(float *angle);
float	get_perp_distance(t_ray ray, t_data *data);
float	distance_between_points(float x1, float y1, float x2, float y2);

#endif
