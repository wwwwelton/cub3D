/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/30 21:50:48 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_menu(t_data *data)
{
	data->menu.main = 0;
	data->menu.options = 0;
	data->menu.game = 0;
	data->menu.opt_mouses = 3;
	data->menu.opt_rots = 2;
	data->menu.opt_moves = 1;
}

static void	init_player(t_data *data)
{
	data->player.x = WIN_WIDTH / 2;
	data->player.y = WIN_HEIGHT / 2;
	data->player.width = PLAYER_SIZE;
	data->player.height = PLAYER_SIZE;
	data->player.turn_dir = 0;
	data->player.walk_dir = 0;
	data->player.rot_angle = 270 * (PI / 180);
	data->player.walk_speed = 10;
	data->player.turn_speed = 10 * (PI / 180);
}

static void	init_images(t_data *data)
{
	init_img(data, &data->img[SCREEN], IMG_WIDTH, IMG_HEIGHT);
	init_img(data, &data->img[RAYS], IMG_WIDTH, IMG_HEIGHT);
	init_img(data, &data->img[BG], IMG_WIDTH, IMG_HEIGHT);
	init_img(data, &data->img[MAP], IMG_WIDTH, IMG_HEIGHT);
	init_img(data, &data->img[PLAYER], IMG_WIDTH, IMG_HEIGHT);
	init_xpm(data, &data->img[TEX_NO], data->params.north);
	init_xpm(data, &data->img[TEX_EA], data->params.east);
	init_xpm(data, &data->img[TEX_SO], data->params.south);
	init_xpm(data, &data->img[TEX_WE], data->params.west);
	init_xpm(data, &data->img[TEX_FL], TEXTURE7);
	init_xpm(data, &data->img[TEX_CE], TEXTURE8);
	init_xpm(data, &data->img[MEN_LOGO], PATHLOGO);
	init_xpm(data, &data->img[MEN_BG], PATHBG);
	init_xpm(data, &data->img[MEN_START], PATHSTART);
	init_xpm(data, &data->img[MEN_OPT], PATHOPTION);
	init_xpm(data, &data->img[SENSI], PATHSENSI);
	init_xpm(data, &data->img[RESUME], PATHRESUME);
	init_xpm(data, &data->img[BACK], PATHBACK);
	init_xpm(data, &data->img[RSPD], PATHRSPD);
	init_xpm(data, &data->img[MSPD], PATHMSPD);
	init_xpm(data, &data->img[ARROW], PATHARROW);
	init_xpm(data, &data->img[EXIT], PATHEXIT);
}

void	init_data(t_data *data)
{
	data->mlx.mlx_ptr = mlx_init();
	data->mlx.win
		= mlx_new_window(data->mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	init_menu(data);
	init_player(data);
	init_images(data);
	data->fps.fps = 60;
	data->fps.current_time = timestamp();
}
