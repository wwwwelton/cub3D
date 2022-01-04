/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/04 01:57:55 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_box(t_data *data, int size, int bx, int by, int color)
{
	int	x;
	int	y;
	t_img	img;
	t_mlx	*mlx;

	mlx = &data->mlx;
	img.img_ptr = mlx_new_image(mlx->mlx_ptr, size, size);
	img.data = (int *)mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_l, &img.endian);
	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
		{
			img.data[y * size + x] = color;
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, img.img_ptr, bx, by);
}

void	draw_map(t_data *data)
{
	int		mapX = 8, mapY = 8;
	int		map[64] =
	{
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 1, 0, 0, 0, 0, 1,
		1, 0, 1, 0, 0, 0, 0, 1,
		1, 0, 1, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 1, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1,
	};
	int		x;
	int		y;

	y = -1;
	while (++y < mapY)
	{
		x = -1;
		while (++x < mapX)
		{
			if (map[y * mapX + x] == 1)
				draw_box(data, 64, x * 66, y * 66, 0xFFFFFF);
			else
				draw_box(data, 64, x * 66, y * 66, 0);
		}
	}
}
