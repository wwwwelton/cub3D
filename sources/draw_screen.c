/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/13 19:40:08 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_screen(t_data *data)
{
	t_img	*img;
	t_mlx	*mlx;

	img = &data->img_screen;
	mlx = &data->mlx;
	fill_color(&data->img_screen, BLACK);
	fill_color(&data->img_bg, BLACK);
	// fill_color(&data->img_rays, BLACK);
	draw_background(data);
	draw_rays(data);
	put_image_to_screen(&data->img_rays, &data->img_screen, BLACK);
	put_image_to_screen(&data->img_bg, &data->img_screen, BLACK);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, img->img_ptr, 0, 0);
	mlx_destroy_image(data->mlx.mlx_ptr, data->img_rays.img_ptr);
	init_img(data, &data->img_rays, IMG_WIDTH, IMG_HEIGHT);
	printf("x: %f y: %f\n", data->player.pos_x, data->player.pos_y);
	printf("dx: %f dy: %f\n",data->ray.dir_y, data->ray.dir_y);
}
