/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_player_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/15 20:48:51 by jofelipe         ###   ########.fr       */
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
	if (xy.x != player_x || xy.y != player_y)
	{
		if (data->map[player_y][player_x] == '0')
		{
			data->map[xy.x][xy.y] = '0';
			data->map[player_y][player_x] = 'N';
			printf(CLEAR);
			print_colored_map(data->map);
		}
	}
}

void	update_player(t_data *data)
{
	float		move_step;
	float		side_step;
	float		new_player_x;
	float		new_player_y;
	t_player	*player;

	player = &data->player;
	player->rot_angle += player->turn_dir * player->turn_speed;
	player->view_angle += player->look_dir * player->look_speed;
	normalize_angle(&player->rot_angle);
	lock_view_angle(&player->view_angle);
	move_step = player->walk_dir * player->walk_speed;
	side_step = player->side_dir * player->walk_speed;
	if (move_step && side_step)
		decrease_step(&move_step, &side_step);
	new_player_x = player->x + cos(player->rot_angle) * move_step;
	new_player_y = player->y + sin(player->rot_angle) * move_step;
	new_player_x = new_player_x - sin(-player->rot_angle) * side_step;
	new_player_y = new_player_y - cos(-player->rot_angle) * side_step;
	if (!map_has_wall_at(new_player_x, new_player_y, data))
	{
		player->x = new_player_x;
		player->y = new_player_y;
	}
}
