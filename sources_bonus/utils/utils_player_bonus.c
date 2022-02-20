/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_player_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/19 21:05:39 by wleite           ###   ########.fr       */
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

static void	move_player(float move_step, float side_step, t_data *data)
{
	float		new_player_x;
	float		new_player_y;
	t_player	*player;

	player = &data->player;
	new_player_x = player->x + cos(player->rot_angle) * move_step;
	new_player_y = player->y + sin(player->rot_angle) * move_step;
	new_player_x = new_player_x - sin(-player->rot_angle) * side_step;
	new_player_y = new_player_y - cos(-player->rot_angle) * side_step;
	if (!map_has_wall_at(new_player_x, new_player_y, data)
		&& !has_sprite_collision_at(new_player_x, new_player_y, data))
	{
		player->x = new_player_x;
		player->y = new_player_y;
	}
}

static void	open_door(t_data *data)
{
	int			step;
	float		new_player_x;
	float		new_player_y;
	t_player	*player;

	step = 0;
	player = &data->player;
	while (step < ACTION_DIST)
	{
		new_player_x = player->x + cos(player->rot_angle) * step;
		new_player_y = player->y + sin(player->rot_angle) * step;
		if (get_map_value_at_pos(new_player_x, new_player_y, data) == 'D'
			&& data->player.action_door == true)
		{
			set_map_value_at_pos(new_player_x, new_player_y, 'H', data);
			break ;
		}
		step += 10;
	}
	data->player.action_door = false;
}

void	update_player(t_data *data)
{
	float		move_step;
	float		side_step;
	float		delta_time;
	t_player	*player;

	player = &data->player;
	delta_time = data->frame.delta_time;
	player->rot_angle += player->turn_dir * player->turn_speed * delta_time;
	player->view_angle += player->look_dir * player->look_speed * delta_time;
	normalize_angle(&player->rot_angle);
	lock_view_angle(&player->view_angle);
	move_step = player->walk_dir * player->walk_speed * delta_time;
	side_step = player->side_dir * player->walk_speed * delta_time;
	if (move_step && side_step)
		decrease_step(&move_step, &side_step);
	open_door(data);
	move_player(move_step, side_step, data);
}
