/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 06:04:56 by jofelipe          #+#    #+#             */
/*   Updated: 2022/02/05 06:28:29 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

# define WIN_WIDTH 1024
# define WIN_HEIGHT 768

# define IMG_WIDTH 1024
# define IMG_HEIGHT 768

# define NUM_RAYS WIN_WIDTH
# define FLT_MAX 3.40282346638528859812e+38F
# define FOV_ANGLE 1.0472
# define FOG_DIST 400
# define FOG_SIDE 0.7

# define PLAYER_SIZE 64
# define VIEW_ANGLE 400

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

typedef struct s_player
{
	float	x;
	float	y;
	float	width;
	float	height;
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
}	t_player;
//player

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

//wall
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
//wall

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

typedef struct s_data
{
	int			img_width;
	int			img_height;
	int			state;
	t_bool		game_running;
	char		**map;
	char		**devmap;
	t_mlx		mlx;
	t_img		img[TEX_NB];
	t_menu		menu;
	t_params	params;
	t_player	player;
	t_ray		rays[NUM_RAYS];
}	t_data;

#endif
