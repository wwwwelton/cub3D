/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/08 02:09:00 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > IMG_WIDTH || y < 0 || y > IMG_HEIGHT)
		return ;
	dst = (char *)img->data + (y * img->size_l + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_pixel_color(t_img *img, int x, int y, int width, int height)
{
	char	*dst;

	if (x < 0 || x > width || y < 0 || y > height)
		return (1);
	dst = (char *)img->data + (y * img->size_l + x * (img->bpp / 8));
	return (*(unsigned int *)dst);
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

void	init_img(t_data *data, t_img *img, int width, int heigth)
{
	t_mlx	*mlx;

	mlx = &data->mlx;
	img->img_ptr = mlx_new_image(mlx->mlx_ptr, width, heigth);
	img->data = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_l, &img->endian);
}

void	draw_box(t_img *img, int x, int y, int size, int color)
{
	int		count_w;
	int		count_h;

	count_h = -1;
	while (++count_h < IMG_HEIGHT)
	{
		count_w = -1;
		while (++count_w < IMG_WIDTH)
		{
			if ((count_h >= y && count_h <= y + size)
				&& (count_w >= x && count_w <= x + size))
				img->data[count_h * IMG_WIDTH + count_w] = color;
		}
	}
}

void	fill_color(t_img *img, int color)
{
	int		count_w;
	int		count_h;

	count_h = -1;
	while (++count_h < IMG_HEIGHT)
	{
		count_w = -1;
		while (++count_w < IMG_WIDTH)
			img->data[count_h * IMG_WIDTH + count_w] = color;
	}
}

void	put_image_to_screen(t_img *img_src, t_img *img_dst, int color)
{
	int		count_w;
	int		count_h;

	count_h = -1;
	while (++count_h < IMG_HEIGHT)
	{
		count_w = -1;
		while (++count_w < IMG_WIDTH)
		{
			if (img_dst->data[count_h * IMG_WIDTH + count_w] == color)
				img_dst->data[count_h * IMG_WIDTH + count_w]
					= img_src->data[count_h * IMG_WIDTH + count_w];
		}
	}
}

void	img_init(t_data *data, t_img *img, char *image_path)
{
	t_mlx	*mlx;

	mlx = &data->mlx;
	img->img_ptr = mlx_xpm_file_to_image
		(mlx->mlx_ptr, image_path, &data->img_width, &data->img_height);
	img->data = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_l, &img->endian);
}

int	exit_game(t_data *data)
{
	mlx_destroy_image(data->mlx.mlx_ptr, data->img_bg.img_ptr);
	mlx_destroy_image(data->mlx.mlx_ptr, data->player.img_player.img_ptr);
	mlx_destroy_image(data->mlx.mlx_ptr, data->img_screen.img_ptr);
	mlx_destroy_image(data->mlx.mlx_ptr, data->img_map.img_ptr);
	mlx_destroy_image(data->mlx.mlx_ptr, data->img_rays.img_ptr);
	mlx_destroy_image(data->mlx.mlx_ptr, data->img_tex1.img_ptr);
	mlx_destroy_image(data->mlx.mlx_ptr, data->img_tex2.img_ptr);
	mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.win);
	mlx_destroy_display(data->mlx.mlx_ptr);
	free(data->mlx.mlx_ptr);
	exit(0);
	return (0);
}
