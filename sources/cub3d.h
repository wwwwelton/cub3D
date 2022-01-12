#ifndef _CUB3D_H
# define _CUB3D_H

# include <stdio.h>
# include <string.h>
# include <math.h>
# include "../libraries/libft/libft.h"
# include "../libraries/minilibx/mlx.h"

# define PI 3.1415926535
# define P2 PI / 2
# define P3 3 * PI / 2
# define DR 0.0174533

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

# define TEXTURE1 "assets/images/piston_top_sticky.xpm"
# define TEXTURE2 "assets/images/acacia_planks.xpm"

# define TEX_SIZE 64


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
	t_img	img_player;
}				t_player;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;
}				t_mlx;

typedef struct	s_data
{
	int			img_width;
	int			img_height;
	t_mlx		mlx;
	t_img		img_bg;
	t_img		img_map;
	t_img		img_screen;
	t_img		img_rays;
	t_img		img_tex1;
	t_img		img_tex2;
	t_player	player;

	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	time;
	double	oldTime;
	double	move_speed;
	double	rot_speed;
}				t_data;


void	mlx_start(t_data *data);
void	draw_map(t_data *data);
void	draw_player(t_data *data);
void	draw_screen(t_data *data);
int		key_press(int key, t_data *data);
void	draw_line(t_img *img, int x0, int y0, int x1, int y1, int color);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

void	draw_background(t_data *data);

void	init_box(t_data *data, t_img *img, int size, int color);
void	draw_box(t_img *img, int x, int y, int size, int color);
int		exit_game(t_data *data);

void	draw_rays(t_data *data);

void	init_img(t_data *data, t_img *img, int width, int heigth);
void	put_image_to_screen(t_img *img_src, t_img *img_dst, int color);

void	fill_color(t_img *img, int color);

void	draw_vert_line(t_img *img, int x0, int y0, int y1, int thick, int color);
void	draw_vert_pixel(t_img *img, int x0, int y0, int thick, int color);

void	img_init(t_data *data, t_img *img, char *image_path);

int		get_pixel_color(t_img *img, int x, int y, int width, int height);

#endif
