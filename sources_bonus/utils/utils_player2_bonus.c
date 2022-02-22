/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_player2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/22 05:58:54 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	update_player_matrix(t_data *data)
{
	t_xy	xy;
	int		player_x;
	int		player_y;

	xy = get_coordinates(data->map, 0, 0);
	player_x = data->player.x / TILE_SIZE;
	player_y = data->player.y / TILE_SIZE;
	if ((xy.x != player_x || xy.y != player_y)
		&& player_x < map_height(data) - 1
		&& player_x >= 0 && player_y >= 0
		&& player_y < map_width(data))
	{
		if (data->map[player_y][player_x] == '0')
		{
			data->map[xy.x][xy.y] = '0';
			data->map[player_y][player_x] = 'P';
			printf(CLEAR);
			print_colored_map(data->map);
		}
	}
}
