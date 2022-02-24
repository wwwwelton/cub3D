/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_doors_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/24 03:16:18 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	replace_wall_by_doorside(int i, int j, t_data *data)
{
	if (ftex_is_in_set(data->map[i - 1][j], VALID_WALLS)
		&& ftex_is_in_set(data->map[i + 1][j], VALID_WALLS))
	{
		set_map_value_at(i - 1, j, DOOR_WALL1, data);
		set_map_value_at(i + 1, j, DOOR_WALL2, data);
		return ;
	}
	if (ftex_is_in_set(data->map[i][j - 1], VALID_WALLS)
		&& ftex_is_in_set(data->map[i][j + 1], VALID_WALLS))
	{
		set_map_value_at(i, j - 1, DOOR_WALL3, data);
		set_map_value_at(i, j + 1, DOOR_WALL4, data);
		return ;
	}
}

void	replace_wall_next_door(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map_height(data))
	{
		j = -1;
		while (++j < map_width(data))
		{
			if (data->map[i][j] == DOOR)
				replace_wall_by_doorside(i, j, data);
		}
	}
}
