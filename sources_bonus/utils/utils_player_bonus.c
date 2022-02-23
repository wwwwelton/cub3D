/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_player_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/23 15:02:37 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	check_player_hitted(t_data *data)
{
	if (data->player.hitted)
	{
		data->player.life--;
		data->player.hitted = 0;
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
	while (step <= DOOR_DIST)
	{
		new_player_x = player->x + cos(player->rot_angle) * step;
		new_player_y = player->y + sin(player->rot_angle) * step;
		if (get_map_value_at_pos(new_player_x, new_player_y, data) == 'D'
			&& data->player.action_door == true)
		{
			set_map_value_at_pos(new_player_x, new_player_y, 'H', data);
			break ;
		}
		step += 50;
	}
	data->player.action_door = false;
}

static void	bullet_calculation(t_data *data)
{
	int			step;
	float		bullet_x;
	float		bullet_y;
	t_player	*player;

	if (!data->player.action_shoot)
		return ;
	step = 0;
	player = &data->player;
	while (step <= SHOT_DIST)
	{
		bullet_x = player->x + cos(player->rot_angle) * step;
		bullet_y = player->y + sin(player->rot_angle) * step;
		if (has_sprite_hittable_at(bullet_x, bullet_y, data))
		{
			hit_sprite_at_pos(bullet_x, bullet_y, data);
			break ;
		}
		step += 50;
	}
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
	bullet_calculation(data);
	check_player_hitted(data);
	move_player(move_step, side_step, data);
}
