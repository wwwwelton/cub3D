/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/12 03:10:31 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlx_start(t_data *data)
{
	data->pos_x = 9.326093;
	data->pos_y = 18.390340;
	data->dir_x = -1;
	data->dir_y = 0;
	data->plane_x = 0;
	data->plane_y = 0.66;
	data->move_speed = 0.15;
	data->rot_speed = 0.05;

	data->mlx.mlx_ptr = mlx_init();
	data->mlx.win = mlx_new_window(data->mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	init_img(data, &data->img_screen, IMG_WIDTH, IMG_HEIGHT);
	init_img(data, &data->img_bg, IMG_WIDTH, IMG_HEIGHT);
	init_img(data, &data->img_map, IMG_WIDTH, IMG_HEIGHT);
	init_img(data, &data->img_rays, IMG_WIDTH, IMG_HEIGHT);
	init_img(data, &data->player.img_player, IMG_WIDTH, IMG_HEIGHT);
	img_init(data, &data->img_tex1, TEXTURE1);
	img_init(data, &data->img_tex2, TEXTURE2);
}
