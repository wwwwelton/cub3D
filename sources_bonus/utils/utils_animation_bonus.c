/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_animation_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/28 20:01:00 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	enemy_hit_player(t_sprite *sprite, t_data *data)
{
	t_bool	hit;

	hit = 0;
	if (sprite->distance < sprite->action_dist && !sprite->hitted)
	{
		if (sprite->frame == 0)
			sprite->texture = sprite->tex_index + 2;
		if (sprite->frame == 1)
		{
			sprite->texture = sprite->tex_index + 3;
			sprite->frame = -1;
			hit = 1;
		}
		if (data->frame.cycle % 4 == 0)
			sprite->frame++;
		sprite->frame = sprite->frame % 2;
		data->sprites[sprite->index].visited = 1;
		return (hit);
	}
	return (hit);
}

static void	animate_enemy(t_sprite *sprite, t_data *data)
{
	if (sprite->visited && !sprite->hitted)
		sprite->texture = sprite->tex_index + 2;
	if (enemy_hit_player(sprite, data))
		data->player.hitted = 1;
	if (sprite->hitted && sprite->animated)
	{
		sprite->collidable = 0;
		if (sprite->frame > 2)
			sprite->animated = false;
		if (sprite->frame == 0)
			sprite->texture = sprite->tex_index + 4;
		if (sprite->frame == 1)
			sprite->texture = sprite->tex_index + 5;
		if (sprite->frame == 2)
			sprite->texture = sprite->tex_index + 6;
		if (data->frame.cycle % 6 == 0)
			sprite->frame++;
	}
}

static void	animate_weapon(t_data *data)
{
	if (data->player.action_shoot)
	{
		if (data->player.frame < 2)
		{
			data->player.weapon = WEAPON_2;
			data->player.frame = 2;
		}
		else
		{
			data->player.weapon = WEAPON_3;
			data->player.frame = 3;
		}
	}
	else
	{
		data->player.frame = 0;
		data->player.weapon = WEAPON_1;
	}
	data->player.frame = (data->frame.cycle % 4);
}

void	update_animations(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_sprites)
	{
		if (data->sprites[i].id == GUARD || data->sprites[i].id == MUTANT)
			animate_enemy(&data->sprites[i], data);
	}
	animate_weapon(data);
}
