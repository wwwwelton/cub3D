/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 09:22:26 by jofelipe          #+#    #+#             */
/*   Updated: 2022/02/15 00:25:38 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	check_mouse_visibility(t_data *data)
{
	if (data->mouse_lock == false)
		mlx_mouse_show(data->mlx.mlx_ptr, data->mlx.win);
	else
		mlx_mouse_hide(data->mlx.mlx_ptr, data->mlx.win);
}

static void	mouse_handler_x(int x, int mid_x, int mid_y, t_data *data)
{
	static int	new_x;
	t_player	*player;

	player = &data->player;
	if (x != new_x && (abs(new_x - x) > 30))
	{
		if (new_x > x)
			player->rot_angle -= player->turn_speed / 5;
		if (new_x < x)
			player->rot_angle += player->turn_speed / 5;
		if (x > mid_x || x < mid_x)
			mlx_mouse_move(data->mlx.mlx_ptr, data->mlx.win, mid_x, mid_y);
		new_x = mid_x;
	}
}

static void	mouse_handler_y(int y, int mid_x, int mid_y, t_data *data)
{
	static int	new_y;
	t_player	*player;

	player = &data->player;
	if (y != new_y && (abs(new_y - y) > 30))
	{
		if (new_y > y)
			player->view_angle += player->look_speed / 5;
		if (new_y < y)
			player->view_angle -= player->look_speed / 5;
		if (y > mid_y || y < mid_y)
			mlx_mouse_move(data->mlx.mlx_ptr, data->mlx.win, mid_x, mid_y);
		new_y = mid_y;
	}
}

int	mouse_handler(int x, int y, t_data *data)
{
	int	mid_x;
	int	mid_y;

	if (data->state != GAME || data->mouse_lock == false)
		return (0);
	mid_x = WIN_WIDTH / 2;
	mid_y = WIN_HEIGHT / 2;
	mouse_handler_x(x, mid_x, mid_y, data);
	mouse_handler_y(y, mid_x, mid_y, data);
	return (0);
}
