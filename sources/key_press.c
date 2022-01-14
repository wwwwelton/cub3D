/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/14 15:49:10 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	worldMappsu[24][24] =
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int	key_press(int key, t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;
	t_ray		*ray;
	t_player	*player;

	player = &data->player;
	ray = &data->ray;
	if (key == KEY_W)
	{
		if (!worldMappsu[(int)(player->pos_x + ray->dir_x * player->move_speed)][(int)(data->player.pos_y)])
			player->pos_x += ray->dir_x * player->move_speed;
		if (!worldMappsu[(int)(player->pos_x)][(int)(player->pos_y + ray->dir_y * player->move_speed)])
			player->pos_y += ray->dir_y * player->move_speed;
	}
	if (key == KEY_S)
	{
		if (!worldMappsu[(int)(player->pos_x - ray->dir_x * player->move_speed)][(int)(player->pos_y)])
			player->pos_x -= ray->dir_x * player->move_speed;
		if (!worldMappsu[(int)(player->pos_x)][(int)(player->pos_y - ray->dir_y * player->move_speed)])
			player->pos_y -= ray->dir_y * player->move_speed;
	}
	if (key == KEY_A)
	{
		old_dir_x = ray->dir_x;
		ray->dir_x = ray->dir_x * cos(player->rot_speed) - ray->dir_y * sin(player->rot_speed);
		ray->dir_y = old_dir_x * sin(player->rot_speed) + ray->dir_y * cos(player->rot_speed);
		old_plane_x = ray->plane_x;
		ray->plane_x = ray->plane_x * cos(player->rot_speed) - ray->plane_y * sin(player->rot_speed);
		ray->plane_y = old_plane_x * sin(player->rot_speed) + ray->plane_y * cos(player->rot_speed);
	}
	if (key == KEY_D)
	{
		old_dir_x = ray->dir_x;
		ray->dir_x = ray->dir_x * cos(-player->rot_speed) - ray->dir_y * sin(-player->rot_speed);
		ray->dir_y = old_dir_x * sin(-player->rot_speed) + ray->dir_y * cos(-player->rot_speed);
		old_plane_x = ray->plane_x;
		ray->plane_x = ray->plane_x * cos(-player->rot_speed) - ray->plane_y * sin(-player->rot_speed);
		ray->plane_y = old_plane_x * sin(-player->rot_speed) + ray->plane_y * cos(-player->rot_speed);
	}
	if (key == KEY_Q || key == KEY_ESC)
		exit_game(data);
	return (0);
}
