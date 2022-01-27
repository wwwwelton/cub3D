/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/27 13:04:36 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_xpm(t_data *data, t_img *img, char *image_path)
{
	t_mlx	*mlx;

	mlx = &data->mlx;
	img->img_ptr = mlx_xpm_file_to_image
		(mlx->mlx_ptr, image_path, &img->width, &img->height);
	img->dump = (int *)
		mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_l, &img->endian);
}

void	init_img(t_data *data, t_img *img, int width, int heigth)
{
	t_mlx	*mlx;

	mlx = &data->mlx;
	img->img_ptr = mlx_new_image(mlx->mlx_ptr, width, heigth);
	img->height = WIN_HEIGHT;
	img->width = WIN_WIDTH;
	img->dump = (int *)
		mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_l, &img->endian);
}

void	init_data(t_data *data, char **argv)
{
	(void)argv;
	data->mlx.mlx_ptr = mlx_init();
	data->mlx.win
		= mlx_new_window(data->mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	data->menu.main = 0;
	data->menu.options = 0;
	data->menu.game = 0;
	data->menu.opt_mouses = 3;
	data->menu.opt_rots = 2;
	data->menu.opt_moves = 1;

	data->player.x = WIN_WIDTH / 2;
	data->player.y = WIN_HEIGHT / 2;
	data->player.width = PLAYER_SIZE;
	data->player.height = PLAYER_SIZE;
	data->player.turn_dir = 0;
	data->player.walk_dir = 0;
	data->player.rot_angle = PI / 2;
	data->player.walk_speed = 10;
	data->player.turn_speed = 30 * (PI / 180);

	init_img(data, &data->img[BG], IMG_WIDTH, IMG_HEIGHT);
	init_img(data, &data->img[RAYS], IMG_WIDTH, IMG_HEIGHT);
	init_img(data, &data->img[MAP], IMG_WIDTH, IMG_HEIGHT);
	init_img(data, &data->img[SCREEN], IMG_WIDTH, IMG_HEIGHT);

	init_xpm(data, &data->img[TEX_NO], data->params.north);
	init_xpm(data, &data->img[TEX_EA], data->params.east);
	init_xpm(data, &data->img[TEX_SO], data->params.south);
	init_xpm(data, &data->img[TEX_WE], data->params.west);
	init_xpm(data, &data->img[TEX_FL], TEXTURE7);
	init_xpm(data, &data->img[TEX_CE], TEXTURE8);


	init_xpm(data, &data->img[MEN_LOGO], PATHLOGO);
	init_xpm(data, &data->img[MEN_BG], PATHBG);
	init_xpm(data, &data->img[MEN_START], PATHSTART);
	init_xpm(data, &data->img[MEN_OPT], PATHOPTION);
	init_xpm(data, &data->img[MEN_ARROW], PATHARROW);
}
