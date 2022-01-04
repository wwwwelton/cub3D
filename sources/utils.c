/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/04 06:08:17 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int sx, int sy, int line_length, int color)
{
	int		x;
	int		y;
	t_img	img;
	t_mlx	*mlx;

	mlx = &data->mlx;
	img.img_ptr = mlx_new_image(mlx->mlx_ptr, line_length, line_length);
	img.data = (int *)mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_l, &img.endian);
	y = -1;
	while (++y < line_length)
	{
		x = -1;
		while (++x < line_length)
		{
			img.data[y * line_length + x] = color;
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, img.img_ptr, sx, sy);
}
