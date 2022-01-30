/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 00:18:15 by jofelipe          #+#    #+#             */
/*   Updated: 2022/01/30 18:54:55 by jofelipe         ###   ########.fr       */
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
	put_menu_item(data, MEN_START, 0, -XOFF);
	put_menu_item(data, MEN_OPT, 0, 0);
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
	put_menu_item(data, MEN_START, OPTYOFF, XOFF * -3);
	fill(img, fillparams(50, 500, 100 * data->menu.opt_mouses, 70), RED);
	put_menu_item(data, MEN_OPT, OPTYOFF, XOFF * -2);
	fill(img, fillparams(150, 500, 100 * data->menu.opt_rots, 70), RED);
	put_menu_item(data, MEN_OPT, OPTYOFF, XOFF * -1);
	fill(img, fillparams(250, 500, 100 * data->menu.opt_moves, 70), RED);
	put_menu_item(data, MEN_OPT, OPTYOFF, XOFF * 0);
	fill(img, fillparams(350, 500, 100 * data->menu.opt_rots, 70), RED);
	put_menu_item(data, MEN_OPT, OPTYOFF, XOFF * 1);
	put_menu_item(data, ARROW, OPTYOFF + 250, XOFF * (data->menu.options - 3));
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, img->img_ptr, 0, 0);
	mlx_destroy_image(mlx->mlx_ptr, img[SCREEN].img_ptr);
	init_img(data, &img[SCREEN], IMG_WIDTH, IMG_HEIGHT);
}
