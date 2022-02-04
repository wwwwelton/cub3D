/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/28 22:19:47 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	reinit_images(t_data *data)
{
	mlx_destroy_image(data->mlx.mlx_ptr, data->img[PLAYER].img_ptr);
	mlx_destroy_image(data->mlx.mlx_ptr, data->img[RAYS].img_ptr);
	mlx_destroy_image(data->mlx.mlx_ptr, data->img[SCREEN].img_ptr);
	init_img(data, &data->img[PLAYER], IMG_WIDTH, IMG_HEIGHT);
	init_img(data, &data->img[RAYS], IMG_WIDTH, IMG_HEIGHT);
	init_img(data, &data->img[SCREEN], IMG_WIDTH, IMG_HEIGHT);
}

void	draw_game(t_data *data)
{
	t_mlx	*mlx;

	mlx = &data->mlx;
	draw_background(data);
	draw_player(data);
	draw_rays(data);
	draw_wall(data);
	copy_layer(&data->img[BG], &data->img[SCREEN], 0, 0);
	copy_layer(&data->img[FRAME], &data->img[SCREEN], 0, 0);
	copy_layer(&data->img[MAP], &data->img[SCREEN], 0, 0);
	copy_layer(&data->img[PLAYER], &data->img[SCREEN], 0, 0);
	copy_layer(&data->img[RAYS], &data->img[SCREEN], 0, 0);
	draw_map(data, data->map, -1, -1);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, data->img->img_ptr, 0, 0);
	reinit_images(data);
}
