/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_wasd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 09:22:26 by jofelipe          #+#    #+#             */
/*   Updated: 2022/01/27 13:59:57 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_w(t_data *data)
{

	data->player.walk_dir = 1;
	move_player(data);
	data->player.walk_dir = 0;
}

void	key_a(t_data *data)
{
	data->player.turn_dir = -1;
	move_player(data);
	data->player.turn_dir = 0;
}

void	key_s(t_data *data)
{
	data->player.walk_dir = -1;
	move_player(data);
	data->player.walk_dir = 0;
}

void	key_d(t_data *data)
{
	data->player.turn_dir = 1;
	move_player(data);
	data->player.turn_dir = 0;
}

void	keys_wasd(int key, t_data *data)
{
	if (key == KEY_W)
		key_w(data);
	if (key == KEY_A)
		key_a(data);
	if (key == KEY_S)
		key_s(data);
	if (key == KEY_D)
		key_d(data);
}
