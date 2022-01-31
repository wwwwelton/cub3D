/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 00:18:15 by jofelipe          #+#    #+#             */
/*   Updated: 2022/01/30 22:15:43 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_menu(t_data *data)
{
	t_mlx		*mlx;
	t_img		*img;

	img = data->img;
	mlx = &data->mlx;
	put_menu_item(data, MEN_BG, 0, 0);
	if (data->game_running)
		put_menu_item(data, RESUME, 0, -XOFF);
	else
		put_menu_item(data, MEN_START, 0, -XOFF);
	put_menu_item(data, MEN_OPT, 0, 0);
	put_menu_item(data, EXIT, 0, XOFF);
	put_menu_item(data, ARROW, YOFF, -XOFF + XOFF * data->menu.main);
	copy_layer(&img[MEN_LOGO], &img[SCREEN], 0, 0);
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
	copy_layer(&img[MEN_BG], &img[SCREEN], 0, 0);
	put_menu_item(data, SENSI, OPTYOFF, XOFF * -3);
	fill(img, fillparams(50, 600, 100 * data->menu.opt_mouses, 70), RED);
	put_menu_item(data, MSPD, OPTYOFF, XOFF * -2);
	fill(img, fillparams(150, 600, 100 * data->menu.opt_moves, 70), RED);
	put_menu_item(data, RSPD, OPTYOFF, XOFF * -1);
	fill(img, fillparams(250, 600, 100 * data->menu.opt_rots, 70), RED);
	put_menu_item(data, BACK, OPTYOFF, XOFF * 0);
	put_menu_item(data, ARROW, OPTYOFF + 250, XOFF * (data->menu.options - 3));
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, img->img_ptr, 0, 0);
	mlx_destroy_image(mlx->mlx_ptr, img[SCREEN].img_ptr);
	init_img(data, &img[SCREEN], IMG_WIDTH, IMG_HEIGHT);
}
