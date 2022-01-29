/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/29 02:42:56 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_fps(t_data *data)
{
	static clock_t	clock_cur;
	int				fps;

	data->fps.last_time = timestamp();
	fps = CLOCKS_PER_SEC / (clock() - clock_cur);
	clock_cur = clock();
	if ((data->fps.last_time - data->fps.current_time) > FRAME_DELAY)
	{
		data->fps.fps = fps;
		data->fps.current_time = timestamp();
	}
	fps = data->fps.fps;
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.win, 500, 20, WHITE, \
	(char []){'0' + fps / 100, '0' + fps / 10 % 10, '0' + fps % 10, '\0'});
}
