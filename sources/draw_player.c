/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/04 06:09:59 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_player(t_data *data)
{
	int		count_w;
	int		count_h;
	float	px;
	float	py;
	float	pdx;
	float	pdy;
	t_img	*img;
	t_mlx	*mlx;

	px = data->player.px;
	py = data->player.py;
	pdx = data->player.pdx;
	pdy = data->player.pdy;
	img = &data->player.img_player;
	mlx = &data->mlx;
	img->img_ptr = mlx_new_image(mlx->mlx_ptr, PLAYER_SIZE, PLAYER_SIZE);
	img->data = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_l, &img->endian);
	count_h = -1;
	while (++count_h < PLAYER_SIZE)
	{
		count_w = -1;
		while (++count_w < PLAYER_SIZE)
		{
			img->data[count_h * PLAYER_SIZE + count_w] = 0xE3E316;
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, img->img_ptr, px, py);
	draw_line(data, px, py, px + pdx * 5, py + pdy * 5, 3, 0xE3E316);
}
