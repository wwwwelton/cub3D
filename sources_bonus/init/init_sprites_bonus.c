/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:23:27 by jofelipe          #+#    #+#             */
/*   Updated: 2022/02/23 17:16:49 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	fill_sprite_data(int i, int j, t_sprite *sprite, t_data *data)
{
	sprite->x = j * TILE_SIZE + (TILE_SIZE / 2);
	sprite->y = i * TILE_SIZE + (TILE_SIZE / 2);
	sprite->id = get_map_value_at(i, j, data);
	sprite->texture = get_sprite_texture(sprite->id);
	sprite->tex_index = sprite->texture - 1;
	sprite->animated = is_sprite_animated(sprite->id);
	sprite->collidable = is_sprite_collidable(sprite->id);
	sprite->action_dist = get_sprite_action_dist(sprite->id);
	sprite->hitted = 0;
	sprite->visited = 0;
	sprite->distance = FLT_MAX;
	sprite->i = i;
	sprite->j = j;
	sprite->frame = 0;
}

void	init_sprites(char **map, t_data *data)
{
	int			i;
	int			j;
	int			n_sprites;
	t_sprite	*sprite;

	n_sprites = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			sprite = &data->sprites[n_sprites];
			if (ftex_is_in_set(map[i][j], VALID_SPRITE))
			{
				fill_sprite_data(i, j, sprite, data);
				sprite->index = n_sprites;
				n_sprites++;
			}
		}
	}
	data->num_sprites = n_sprites;
}
