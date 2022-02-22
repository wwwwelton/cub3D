/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/22 17:18:36 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	render_sprite(t_sprite_data *sprite, t_data *data)
{
	int	x;
	int	y;
	int	text_num;

	x = sprite->left_x - 1;
	while (++x < sprite->right_x)
	{
		sprite->texture_offset_x = (x - sprite->left_x) * sprite->pixel_width;
		y = sprite->top_y - 1;
		while (++y < sprite->bottom_y)
		{
			sprite->distance_from_top = y + (sprite->height / 2)
				- (sprite->win_height / 2);
			sprite->texture_offset_y = sprite->distance_from_top
				* sprite->pixel_height;
			text_num = sprite->texture;
			sprite->pixel_color = get_sprite_pixel_color(data->img[text_num],
					sprite);
			if (FOG_DIST && sprite->distance > FOG_DIST)
				change_sprite_color_intensity(sprite);
			if (x >= 0 && sprite->distance < data->rays[x].distance
				&& sprite->pixel_color != PINK)
				pixel_put(&data->img[SPRITE], x, y, sprite->pixel_color);
		}
	}
}

void	draw_sprites(t_data *data)
{
	int				i;
	t_sprite_data	sprite;

	i = -1;
	while (++i < data->num_visible_sprites)
	{
		init_sprite_data(data->visible_sprites[i], &sprite, data);
		render_sprite(&sprite, data);
	}
}
