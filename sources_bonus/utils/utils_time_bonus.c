/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 08:14:33 by jofelipe          #+#    #+#             */
/*   Updated: 2022/02/16 02:22:31 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	fps_to_str(int fps, char *str)
{
	str[0] = (fps / 100) + '0';
	str[1] = (fps / 10 % 10) + '0';
	str[2] = (fps % 10) + '0';
}

void	sync_time(t_data *data)
{
	static float	old_time;
	static int		fps = 60;
	int				fps_calc;
	static long		current_time = -1;
	long			last_time;

	last_time = timestamp();
	if (current_time == -1)
		current_time = timestamp();
	data->frame.delta_time = clock() - old_time;
	fps_calc = (1.0 / data->frame.delta_time) * CLOCKS_PER_SEC;
	data->frame.cycle++;
	data->frame.cycle = (data->frame.cycle % 30);
	data->frame.delta_time = data->frame.delta_time / 1000.0f;
	old_time = clock();
	if ((last_time - current_time) > FRAME_DELAY)
	{
		current_time = timestamp();
		fps = fps_calc;
		fps_to_str(fps, data->frame.fps);
	}
	data->frame.delta_time = data->frame.delta_time / 30;
}
