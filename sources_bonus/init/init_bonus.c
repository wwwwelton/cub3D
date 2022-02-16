/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/16 01:55:09 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	init_menu(t_data *data)
{
	data->game_running = false;
	data->menu.main = 0;
	data->menu.options = 0;
	data->menu.game = 0;
	data->menu.opt_mouses = 3;
	data->menu.opt_rots = 2;
	data->menu.opt_moves = 1;
	data->mouse_lock = 1;
}

static void	init_player(t_data *data)
{
	data->player.init_pos = get_player_direction(data->map);
	data->player.rot_angle = set_player_direction(data->player.init_pos);
	set_player_position(data, data->map);
	data->player.width = PLAYER_SIZE;
	data->player.height = PLAYER_SIZE;
	data->player.turn_dir = 0;
	data->player.walk_dir = 0;
	data->player.side_dir = 0;
	data->player.look_dir = 0;
	data->player.view_angle = 0;
	data->player.walk_speed = 10;
	data->player.turn_speed = 3 * (PI / 180);
	data->player.look_speed = 35;
	data->player.action_door = false;
}

static void	init_images(t_data *data)
{
	init_img(data, &data->img[SCREEN], WIN_WIDTH, WIN_HEIGHT);
	init_img(data, &data->img[MAP], WIN_WIDTH, WIN_HEIGHT);
	init_img(data, &data->img[FRAME], WIN_WIDTH, WIN_HEIGHT);
}

void	init_data(t_data *data)
{
	data->mlx.mlx_ptr = mlx_init();
	data->mlx.win
		= mlx_new_window(data->mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	init_menu(data);
	init_player(data);
	init_fps(data);
	init_images(data);
	if (init_fps_textures(data) == false || init_xpm_textures(data) == false)
		exit_game(data);
}
