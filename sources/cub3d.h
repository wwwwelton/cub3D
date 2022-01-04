#ifndef _CUB3D_H
# define _CUB3D_H

# include <stdio.h>
# include <string.h>
# include <math.h>
# include "../libraries/minilibx/mlx.h"

# define PI 3.1415926535

# define WIN_WIDTH 1024
# define WIN_HEIGHT 512

# define IMG_WIDTH 1024
# define IMG_HEIGHT 512

# define PLAYER_SIZE 10

# define X_EVENT_KEY_PRESS 2

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

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_player
{
	t_img		img_player;
	float		px;
	float		py;
	float		pdx;
	float		pdy;
	float		pa;
}				t_player;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;
}				t_mlx;

typedef struct	s_data
{
	t_mlx		mlx;
	t_img		img_bg;
	t_player	player;
}				t_data;


void	mlx_start(t_data *data);
void	draw_background(t_data *data);
void	draw_map(t_data *data);
void	draw_player(t_data *data);
void	draw_screen(t_data *data);
int		key_press(int key, t_data *data);

#endif
