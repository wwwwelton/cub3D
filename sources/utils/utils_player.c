/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/04 00:48:34 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player_position(t_data *data, char **map)
{
	t_xy	xy;

	xy = get_coordinates(map, 0, 0);
	data->player.y = xy.x * TILE_SIZE + (TILE_SIZE / 2);
	data->player.x = xy.y * TILE_SIZE + (TILE_SIZE / 2);
}

char	get_player_direction(char **map)
{
	t_xy	xy;

	xy = get_coordinates(map, 0, 0);
	return (map[xy.x][xy.y]);
}

float	set_player_direction(char c)
{
	printf("%c\n", c);
	if (c == 'N')
		return (270 * (PI / 180));
	else if (c == 'E')
		return (360 * (PI / 180));
	else if (c == 'W')
		return (180 * (PI / 180));
	else if (c == 'S')
		return (90 * (PI / 180));
	else
		return (0);
}

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
			printf("player x %d player y %d\n", player_x, player_y);
			printf("xy.x %d xy.y %d\n", xy.x, xy.y);
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
	normalize_angle(&player->rot_angle);
	move_step = player->walk_dir * player->walk_speed;
	side_step = player->side_dir * player->walk_speed;
	if (move_step && side_step)
	{
		move_step /= 2;
		side_step /= 2;
	}
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
