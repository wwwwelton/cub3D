/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:16:54 by jofelipe          #+#    #+#             */
/*   Updated: 2022/02/22 19:05:32 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_BONUS_H
# define STRUCTS_BONUS_H

typedef struct s_ray
{
	float	ray_angle;
	float	wall_hit_x;
	float	wall_hit_y;
	float	distance;
	int		was_hit_vertical;
	int		texture;
}	t_ray;

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

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win;
}				t_mlx;

typedef struct s_player
{
	float	x;
	float	y;
	float	width;
	float	height;
	t_bool	action_door;
	t_bool	action_shoot;
	t_bool	hitted;
	int		turn_dir;
	int		walk_dir;
	int		side_dir;
	int		look_dir;
	int		init_pos;
	float	view_angle;
	float	rot_angle;
	float	walk_speed;
	float	turn_speed;
	int		turn_speed_var;
	float	look_speed;
	int		weapon;
	int		frame;
	int		life;
}	t_player;

typedef struct s_map
{
	int		**matrix;
	char	**charmatrix;
	int		width;
	int		height;
}	t_map;

typedef struct s_params
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	int		ceilcolor;
	int		floorcolor;
}	t_params;

typedef struct s_frame
{
	float	delta_time;
	char	fps[4];
	int		cycle;
}	t_frame;

typedef struct s_sprite
{
	float	x;
	float	y;
	float	distance;
	float	angle;
	t_bool	visible;
	int		index;
	int		id;
	int		texture;
	int		tex_index;
	int		i;
	int		j;
	int		frame;
	int		action_dist;
	t_bool	animated;
	t_bool	collidable;
	t_bool	hitted;
	t_bool	visited;
}	t_sprite;

typedef struct s_sprite_data
{
	float		height;
	float		width;
	float		top_y;
	float		bottom_y;
	float		left_x;
	float		right_x;
	float		dist_proj_plane;
	int			win_height;
	int			texture;
	int			pixel_color;
	int			texture_offset_y;
	int			texture_offset_x;
	float		pixel_width;
	float		pixel_height;
	int			distance_from_top;
	float		distance;
}	t_sprite_data;

typedef struct s_data
{
	int			state;
	int			mouse_lock;
	int			num_sprites;
	int			num_visible_sprites;
	t_bool		game_running;
	char		**map;
	char		**devmap;
	t_mlx		mlx;
	t_img		img[TEX_NB];
	t_menu		menu;
	t_params	params;
	t_player	player;
	t_ray		rays[NUM_RAYS];
	t_sprite	sprites[NUM_SPRITES];
	t_sprite	visible_sprites[NUM_SPRITES];
	t_frame		frame;
}	t_data;

#endif
