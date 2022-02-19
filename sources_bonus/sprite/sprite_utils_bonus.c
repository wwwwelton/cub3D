/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/18 22:53:06 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

float	get_sprite_dist(t_sprite sprite, t_data *data)
{
	float	ret;

	ret = distance_between_points(sprite.x,
			sprite.y, data->player.x, data->player.y);
	return (ret);
}

float	get_angle_sprite_player(t_sprite sprite, t_data *data)
{
	float	ret;

	ret = data->player.rot_angle - atan2(sprite.y - data->player.y,
			sprite.x - data->player.x);
	return (ret);
}

void	sort_visible_sprites(t_sprite *visible_sprites, int num_sprites)
{
	int			i;
	int			j;
	t_sprite	temp;

	i = -1;
	while (++i < num_sprites)
	{
		j = -1;
		while (++j < num_sprites)
		{
			if (visible_sprites[i].distance > visible_sprites[j].distance)
			{
				temp = visible_sprites[i];
				visible_sprites[i] = visible_sprites[j];
				visible_sprites[j] = temp;
			}
		}
	}
}

int	map_has_sprite_at(float x, float y, t_data *data)
{
	int	map_x;
	int	map_y;

	map_x = floor(x / TILE_SIZE);
	map_y = floor(y / TILE_SIZE);
	if (map_y < 0 || map_y > (map_height(data) - 1)
		|| map_x < 0 || map_x > (map_width(data) - 1))
	{
		return (false);
	}
	return (ftex_is_in_set(data->map[map_y][map_x], VALID_SPRITE));
}
