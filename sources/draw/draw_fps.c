/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/31 22:41:20 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_fps(t_data *data)
{
	static clock_t	clock_cur;
	static int		fps = 60;
	int				fps_calc;
	static long		current_time = -1;
	long			last_time;

	last_time = timestamp();
	if (current_time == -1)
		current_time = timestamp();
	fps_calc = CLOCKS_PER_SEC / (clock() - clock_cur);
	clock_cur = clock();
	if ((last_time - current_time) > FRAME_DELAY)
	{
		current_time = timestamp();
		fps = fps_calc;
	}
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.win, 1000, 20, WHITE, \
	(char []){'0' + fps / 100, '0' + fps / 10 % 10, '0' + fps % 10, '\0'});
}
