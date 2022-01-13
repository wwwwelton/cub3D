/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/13 20:39:19 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_screen(t_data *data)
{
	t_mlx	*mlx;

	mlx = &data->mlx;
	fill_color(&data->img[SCREEN], BLACK);
	fill_color(&data->img[BG], BLACK);
	draw_background(data);
	draw_rays(data);
	copy_layer(&data->img[RAYS], &data->img[SCREEN], BLACK);
	copy_layer(&data->img[BG], &data->img[SCREEN], BLACK);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, data->img[SCREEN].img_ptr, 0, 0);
	mlx_destroy_image(data->mlx.mlx_ptr, data->img[RAYS].img_ptr);
	init_img(data, &data->img[RAYS], IMG_WIDTH, IMG_HEIGHT);
}
