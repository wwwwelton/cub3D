/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/04 22:17:17 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_player(t_data *data)
{
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
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, img->img_ptr, px, py);
	draw_line(data, &data->img_pixel1, px, py, px + pdx * 5, py + pdy * 5);
}
