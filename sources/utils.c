/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/06 01:37:02 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, t_img *img, int x, int y)
{
	t_mlx	*mlx;

	mlx = &data->mlx;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, img->img_ptr, x, y);
}

void	draw_box(t_data *data, t_img *img, int x, int y)
{
	t_mlx	*mlx;

	mlx = &data->mlx;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, img->img_ptr, x, y);
}

void	init_box(t_data *data, t_img *img, int size, int color)
{
	int		x;
	int		y;
	t_mlx	*mlx;

	mlx = &data->mlx;
	img->img_ptr = mlx_new_image(mlx->mlx_ptr, size, size);
	img->data = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_l, &img->endian);
	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
			img->data[y * size + x] = color;
	}
}

int	exit_game(t_data *data)
{
	mlx_destroy_image(data->mlx.mlx_ptr, data->img_bg.img_ptr);
	mlx_destroy_image(data->mlx.mlx_ptr, data->img_box1.img_ptr);
	mlx_destroy_image(data->mlx.mlx_ptr, data->img_box2.img_ptr);
	mlx_destroy_image(data->mlx.mlx_ptr, data->player.img_player.img_ptr);
	mlx_destroy_image(data->mlx.mlx_ptr, data->img_pixel1.img_ptr);
	mlx_destroy_image(data->mlx.mlx_ptr, data->img_pixel2.img_ptr);
	mlx_destroy_image(data->mlx.mlx_ptr, data->img_pixel3.img_ptr);
	mlx_destroy_image(data->mlx.mlx_ptr, data->img_pixel4.img_ptr);
	mlx_destroy_image(data->mlx.mlx_ptr, data->img_pixel5.img_ptr);
	mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.win);
	mlx_destroy_display(data->mlx.mlx_ptr);
	free(data->mlx.mlx_ptr);
	exit(0);
	return (0);
}
