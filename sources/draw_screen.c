/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/27 11:28:43 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	middle_x(t_img img)
{
	return (IMG_WIDTH / 2 - (img.width / 2));
}

int	middle_y(t_img img)
{
	return (IMG_HEIGHT / 2 - (img.height / 2));
}

void	draw_menu(t_data *data)
{
	t_mlx		*mlx;
	t_img		*img;

	img = data->img;
	mlx = &data->mlx;
	_copy_layer(&img[MEN_BG], &img[SCREEN], 0, 0);
	_copy_layer(&img[MEN_START], &img[SCREEN]
		, middle_x(img[MEN_START])
		, middle_y(img[MEN_START]) - XOFFSET);

	_copy_layer(&img[MEN_OPT], img
	, middle_x(img[MEN_OPT])
	, middle_y(img[MEN_OPT]));

	_copy_layer(&img[MEN_ARROW], img
	, middle_x(img[MEN_ARROW]) - YOFFSET
	, middle_y(img[MEN_ARROW]) - XOFFSET + XOFFSET * data->menu.main);

	_copy_layer(&img[MEN_LOGO], &img[SCREEN], 0, 0);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, img->img_ptr, 0, 0);
	mlx_destroy_image(mlx->mlx_ptr, img[SCREEN].img_ptr);
	init_img(data, &img[SCREEN], IMG_WIDTH, IMG_HEIGHT);
}

void	draw_options(t_data *data)
{
	t_mlx		*mlx;
	t_img		*img;

	mlx = &data->mlx;
	img = data->img;
	(void) mlx;
	_copy_layer(&img[MEN_BG], &img[SCREEN], 0, 0);
	_copy_layer(&img[MEN_START], &img[SCREEN]
	, middle_x(img[MEN_START]) - OPTYOFFSET
	, middle_y(img[MEN_START]) + XOFFSET * -3);
	fill(img, fillparams(50, 500, 100 * data->menu.opt_mouses, 70), RED);

	_copy_layer(&img[MEN_OPT], &img[SCREEN]
	, middle_x(img[MEN_OPT]) - OPTYOFFSET
	, middle_y(img[MEN_OPT]) + XOFFSET * -2);
	fill(img, fillparams(150, 500, 100 * data->menu.opt_rots, 70), RED);

	_copy_layer(&img[MEN_OPT], &img[SCREEN]
	, middle_x(img[MEN_OPT]) - OPTYOFFSET
	, middle_y(img[MEN_OPT]) + XOFFSET * -1);
	fill(img, fillparams(250, 500, 100 * data->menu.opt_moves, 70), RED);

	_copy_layer(&img[MEN_OPT], &img[SCREEN]
	, middle_x(img[MEN_OPT]) - OPTYOFFSET
	, middle_y(img[MEN_OPT]));
	fill(img, fillparams(350, 500, 100 * data->menu.opt_rots, 70), RED);

	_copy_layer(&img[MEN_ARROW], &img[SCREEN]
	, middle_x(img[MEN_ARROW]) - OPTYOFFSET - 250
	, middle_y(img[MEN_ARROW]) + XOFFSET * (data->menu.options - 3));

	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, img->img_ptr, 0, 0);
	mlx_destroy_image(mlx->mlx_ptr, img[SCREEN].img_ptr);
	init_img(data, &img[SCREEN], IMG_WIDTH, IMG_HEIGHT);
}

void	draw_screen(t_data *data)
{
	t_mlx	*mlx;

	mlx = &data->mlx;
	fill_color(&data->img[SCREEN], BLACK);
	fill_color(&data->img[BG], BLACK);
	fill_color(&data->img[MAP], BLACK);
	draw_background(data);
	draw_map(data);
	draw_player(data);
	draw_rays(data);
	copy_layer(&data->img[RAYS], &data->img[SCREEN], BLACK);
	copy_layer(&data->img[MAP], &data->img[SCREEN], BLACK);
	copy_layer(&data->img[BG], &data->img[SCREEN], BLACK);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, data->img->img_ptr, 0, 0);
	mlx_destroy_image(data->mlx.mlx_ptr, data->img[RAYS].img_ptr);
	init_img(data, &data->img[RAYS], IMG_WIDTH, IMG_HEIGHT);
}
