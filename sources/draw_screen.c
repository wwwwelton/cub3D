/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/20 04:39:21 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_menu(t_data *data)
{
	t_mlx		*mlx;

	mlx = &data->mlx;
	_copy_layer(&data->img[MEN_BG], &data->img[SCREEN], 0, 0);
	_copy_layer(&data->img[MEN_START], &data->img[SCREEN]
	, IMG_WIDTH / 2 - (data->img[MEN_START].width / 2)
	, IMG_HEIGHT / 2 - (data->img[MEN_START].height / 2) - YOFFSET);
	_copy_layer(&data->img[MEN_OPT], &data->img[SCREEN]
	, IMG_WIDTH / 2 - (data->img[MEN_OPT].width / 2)
	, IMG_HEIGHT / 2 - (data->img[MEN_OPT].height / 2));
	_copy_layer(&data->img[MEN_ARROW], &data->img[SCREEN]
	, IMG_WIDTH / 2 - (data->img[MEN_ARROW].width / 2) - 250
	, IMG_HEIGHT / 2 - (data->img[MEN_ARROW].height / 2) - YOFFSET + YOFFSET * data->menu.main);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, data->img->img_ptr, 0, 0);
	mlx_destroy_image(data->mlx.mlx_ptr, data->img[SCREEN].img_ptr);
	init_img(data, &data->img[SCREEN], IMG_WIDTH, IMG_HEIGHT);
}

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
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, data->img->img_ptr, 0, 0);
	mlx_destroy_image(data->mlx.mlx_ptr, data->img[RAYS].img_ptr);
	init_img(data, &data->img[RAYS], IMG_WIDTH, IMG_HEIGHT);
}
