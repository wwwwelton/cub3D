/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/04 22:27:14 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int key, t_data *data)
{
	usleep(100);
	if (key == KEY_W)
	{
		data->player.px += data->player.pdx;
		data->player.py += data->player.pdy;
	}
	if (key == KEY_S)
	{
		data->player.px -= data->player.pdx;
		data->player.py -= data->player.pdy;
	}
	if (key == KEY_A)
	{
		data->player.pa -= 0.1;
		if (data->player.pa < 0)
			data->player.pa += 2 * PI;
		data->player.pdx = cos(data->player.pa) * 5;
		data->player.pdy = sin(data->player.pa) * 5;
	}
	if (key == KEY_D)
	{
		data->player.pa += 0.1;
		if (data->player.pa > 2 * PI)
			data->player.pa -= 2 * PI;
		data->player.pdx = cos(data->player.pa) * 5;
		data->player.pdy = sin(data->player.pa) * 5;
	}
	if (key == KEY_Q || key == KEY_ESC)
		exit_game(data);
	draw_screen(data);
	return (0);
}
