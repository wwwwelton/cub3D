/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 00:18:15 by jofelipe          #+#    #+#             */
/*   Updated: 2022/02/24 15:40:59 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	put_resized_bg(t_data *data)
{
	float		scale_vert;
	float		scale_horiz;
	t_img		*newbg;
	t_menu_elem	elem;

	scale_vert = (float)WIN_HEIGHT / (float)data->img[MEN_BG].height;
	scale_horiz = (float)WIN_WIDTH / (float)data->img[MEN_BG].width;
	if (scale_horiz > scale_vert)
		scale_vert = scale_horiz;
	newbg = resize_image(&data->img[MEN_BG], scale_vert, data);
	elem.src = newbg;
	elem.dst = &data->img[SCREEN];
	elem.x = middle_x(*newbg);
	elem.y = middle_y(*newbg);
	if (elem.y < 0)
		elem.y = 0;
	copy_layer(elem.src, elem.dst, elem.x, elem.y);
	destroy_resized_image(newbg, data);
}

void	draw_menu(t_data *data)
{
	t_mlx		*mlx;
	t_img		*img;

	img = data->img;
	mlx = &data->mlx;
	if (data->img[MEN_BG].height != WIN_HEIGHT
		|| data->img[MEN_BG].width != WIN_WIDTH)
		put_resized_bg(data);
	else
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
	if (data->img[MEN_BG].height != WIN_HEIGHT)
		put_resized_bg(data);
	else
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
