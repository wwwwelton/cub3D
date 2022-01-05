/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/05 01:35:52 by wleite           ###   ########.fr       */
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
	init_background(data);
	init_box(data, &data->img_box1, 64, 0xFFFFFF);
	init_box(data, &data->img_box2, 64, 0);
	init_box(data, &data->player.img_player, PLAYER_SIZE, 0xE3E316);
	init_box(data, &data->img_pixel1, LINE_LENGTH, 0xE3E316);
	init_box(data, &data->img_pixel2, 1, 0xE31616);
}
