/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 00:18:15 by jofelipe          #+#    #+#             */
/*   Updated: 2022/02/14 21:16:04 by jofelipe         ###   ########.fr       */
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
	put_menu_item(data, MEN_LOGO, 0, -250);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, img->img_ptr, 0, 0);
	mlx_destroy_image(mlx->mlx_ptr, img[SCREEN].img_ptr);
	init_img(data, &img[SCREEN], WIN_WIDTH, WIN_HEIGHT);
}

void	draw_options(t_data *data)
{
	t_mlx		*mlx;
	t_img		*img;

	mlx = &data->mlx;
	img = data->img;
	(void) mlx;
	put_menu_item(data, MEN_BG, 0, 0);
	put_menu_item(data, SENSI, OPTYOFF, XOFF * -3);
	put_menu_item(data, MSPD, OPTYOFF, XOFF * -2);
	put_menu_item(data, RSPD, OPTYOFF, XOFF * -1);
	put_menu_item(data, BACK, OPTYOFF, XOFF * 0);
	fill_menu_item(data, data->menu.opt_mouses, -238, -300);
	fill_menu_item(data, data->menu.opt_moves, -238, -200);
	fill_menu_item(data, data->menu.opt_rots, -238, -100);
	put_menu_item(data, HUDFRAME, -238, -300);
	put_menu_item(data, HUDFRAME, -238, -200);
	put_menu_item(data, HUDFRAME, -238, -100);
	put_menu_item(data, ARROW, OPTYOFF + 250, XOFF * (data->menu.options - 3));
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, img->img_ptr, 0, 0);
	mlx_destroy_image(mlx->mlx_ptr, img[SCREEN].img_ptr);
	init_img(data, &img[SCREEN], WIN_WIDTH, WIN_HEIGHT);
}
