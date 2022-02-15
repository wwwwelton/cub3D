/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:16:54 by jofelipe          #+#    #+#             */
/*   Updated: 2022/02/14 23:28:52 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

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
