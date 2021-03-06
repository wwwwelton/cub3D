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
	mlx_destroy_image(data->mlx.mlx_ptr, data->img[SCREEN].img_ptr);
	init_img(data, &data->img[SCREEN], WIN_WIDTH, WIN_HEIGHT);
}

void	draw_game(t_data *data)
{
	t_mlx	*mlx;

	mlx = &data->mlx;
	draw_wall(data);
	copy_layer(&data->img[FRAME], &data->img[SCREEN], 0, 0);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, data->img->img_ptr, 0, 0);
	reinit_images(data);
}
