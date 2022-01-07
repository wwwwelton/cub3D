/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/07 01:09:48 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlx_start(t_data *data)
{
	data->player.px = 300;
	data->player.py = 300;
	data->player.pa = 0;
	data->player.pdx = cos(data->player.pa) * 5;
	data->player.pdy = sin(data->player.pa) * 5;
	data->mlx.mlx_ptr = mlx_init();
	data->mlx.win = mlx_new_window(data->mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	init_img(data, &data->img_screen, IMG_WIDTH, IMG_HEIGHT);
	init_img(data, &data->img_bg, IMG_WIDTH, IMG_HEIGHT);
	init_img(data, &data->img_map, IMG_WIDTH, IMG_HEIGHT);
	init_img(data, &data->img_rays, IMG_WIDTH, IMG_HEIGHT);
	init_img(data, &data->player.img_player, IMG_WIDTH, IMG_HEIGHT);
}
