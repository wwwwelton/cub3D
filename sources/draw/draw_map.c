/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/04 06:00:16 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	draw_map(t_data *data, char **map, int x, int y)
{
	t_xy	pl;
	t_fill	params;
	int		len;
	int		height;

	height = get_height(data->map);
	len = ft_strlen(data->map[0]);
	pl = get_coordinates(map, 0, 0);
	while (++x < 21)
	{
		while (++y < 21)
		{
			params = fillparams(498 + (11 * x), (11 * y) + 50, 10, 10);
			if (pl.x + x - 10 < 0 || pl.y + y - 10 < 0
				|| pl.x + x - 9 > height || pl.y + y - 9 > len)
				fill(&data->img[SCREEN], params, GRAY);
			else if (ftex_is_in_set(map[pl.x + x - 10][pl.y + y - 10], "@! "))
				fill(&data->img[SCREEN], params, RED);
			else if (ftex_is_in_set(map[pl.x + x - 10][pl.y + y - 10], "NSEW"))
				fill(&data->img[SCREEN], params, YELLOW);
			else
				fill(&data->img[SCREEN], params, GRAY);
		}
		y = -1;
	}
}
