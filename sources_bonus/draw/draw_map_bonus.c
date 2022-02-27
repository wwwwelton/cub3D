/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/27 17:12:07 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	init_draw_map(t_data *data, t_xy *pl)
{
	t_fill	vars;

	data->h = map_height(data);
	data->l = map_width(data);
	*pl = get_coordinates(data->map, 0, 0);
	vars = fillparams(503, 55, 10 * 23 + 2, 10 * 23 + 2);
	vars.x = WIN_HEIGHT - 271;
	vars.y = middle_y(data->img[MAP]) + 49;
	fill(&data->img[MAP], vars, BLACKB);
	vars = fillparams(498, 50, 10 * 23 + 2, 10 * 23 + 2);
	vars.x = WIN_HEIGHT - 265;
	vars.y = middle_y(data->img[MAP]) + 55;
	fill(&data->img[MAP], vars, BLACKB);
}

void	draw_map(t_data *data, char **map, int x, int y)
{
	t_xy	pl;
	t_fill	vars;

	init_draw_map(data, &pl);
	while (++x < 21)
	{
		while (++y < 21)
		{
			vars = fillparams(WIN_HEIGHT - 270 + 11 * x, 50 + 11 * y, 10, 10);
			if (pl.x + x - 10 < 0 || pl.y + y - 10 < 0
				|| pl.x + x - 9 > data->h || pl.y + y - 9 > data->l)
				fill(&data->img[MAP], vars, GRAY);
			else if (ftex_is_in_set(map[pl.x + x - 10][pl.y + y - 10], SSPRITE))
				fill(&data->img[MAP], vars, RED);
			else if (ftex_is_in_set(map[pl.x + x - 10][pl.y + y - 10], "@! "))
				fill(&data->img[MAP], vars, BLUE);
			else if (ftex_is_in_set(map[pl.x + x - 10][pl.y + y - 10], "DH"))
				fill(&data->img[MAP], vars, GREEN);
			else if (ftex_is_in_set(map[pl.x + x - 10][pl.y + y - 10], "NSEWP"))
				fill(&data->img[MAP], vars, YELLOW);
			else
				fill(&data->img[MAP], vars, GRAY);
		}
		y = -1;
	}
}
