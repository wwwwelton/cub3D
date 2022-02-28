/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_player2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/28 19:12:35 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	update_player_matrix(t_data *data)
{
	static char	old = '0';
	t_xy		xy;
	int			player_x;
	int			player_y;

	xy = get_coordinates(data->map, 0, 0);
	player_x = data->player.x / TILE_SIZE;
	player_y = data->player.y / TILE_SIZE;
	if ((xy.x != player_y || xy.y != player_x)
		&& player_y < map_height(data) - 1
		&& player_x >= 0 && player_y >= 0
		&& player_x < map_width(data))
	{
		if (!ftex_is_in_set(data->map[player_y][player_x], WALLS))
		{
			data->map[xy.x][xy.y] = old;
			old = data->map[player_y][player_x];
			data->map[player_y][player_x] = 'P';
			printf(CLEAR);
			print_colored_map(data->map, -1, -1);
		}
	}
}
