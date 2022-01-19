/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_wasd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 09:22:26 by jofelipe          #+#    #+#             */
/*   Updated: 2022/01/19 09:33:15 by jofelipe         ###   ########.fr       */
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

void	key_w(t_data *data)
{
	t_ray		*ray;
	t_player	*player;

	player = &data->player;
	ray = &data->ray;
	if (!worldMappsu[(int)(player->pos_x + ray->dir_x * player->move_speed)][(int)(data->player.pos_y)])
		player->pos_x += ray->dir_x * player->move_speed;
	if (!worldMappsu[(int)(player->pos_x)][(int)(player->pos_y + ray->dir_y * player->move_speed)])
		player->pos_y += ray->dir_y * player->move_speed;
}
void	key_a(t_data *data)
{
	double		old_dir_x;
	double		old_plane_x;
	t_ray		*ray;
	t_player	*player;

	player = &data->player;
	ray = &data->ray;
	old_dir_x = ray->dir_x;
	ray->dir_x = ray->dir_x * cos(player->rot_speed) - ray->dir_y * sin(player->rot_speed);
	ray->dir_y = old_dir_x * sin(player->rot_speed) + ray->dir_y * cos(player->rot_speed);
	old_plane_x = ray->plane_x;
	ray->plane_x = ray->plane_x * cos(player->rot_speed) - ray->plane_y * sin(player->rot_speed);
	ray->plane_y = old_plane_x * sin(player->rot_speed) + ray->plane_y * cos(player->rot_speed);
}

void	key_s(t_data *data)
{
	t_ray		*ray;
	t_player	*player;

	player = &data->player;
	ray = &data->ray;
	if (!worldMappsu[(int)(player->pos_x - ray->dir_x * player->move_speed)][(int)(player->pos_y)])
		player->pos_x -= ray->dir_x * player->move_speed;
	if (!worldMappsu[(int)(player->pos_x)][(int)(player->pos_y - ray->dir_y * player->move_speed)])
		player->pos_y -= ray->dir_y * player->move_speed;
}

void	key_d(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;
	t_ray		*ray;
	t_player	*player;

	player = &data->player;
	ray = &data->ray;
	old_dir_x = ray->dir_x;
	ray->dir_x = ray->dir_x * cos(-player->rot_speed) - ray->dir_y * sin(-player->rot_speed);
	ray->dir_y = old_dir_x * sin(-player->rot_speed) + ray->dir_y * cos(-player->rot_speed);
	old_plane_x = ray->plane_x;
	ray->plane_x = ray->plane_x * cos(-player->rot_speed) - ray->plane_y * sin(-player->rot_speed);
	ray->plane_y = old_plane_x * sin(-player->rot_speed) + ray->plane_y * cos(-player->rot_speed);
}

void	keys_wasd(int key, t_data *data)
{
	if (key == KEY_W)
		key_w(data);
	if (key == KEY_A)
		key_a(data);
	if (key == KEY_S)
		key_s(data);
	if (key == KEY_D)
		key_d(data);
}
