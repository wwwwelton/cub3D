/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/18 20:10:34 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	get_sprite_pixel_color(t_img texture, t_sprite_data *sprite)
{
	int	offset_x;
	int	offset_y;
	int	pixel_color;

	offset_x = sprite->texture_offset_x;
	offset_y = sprite->texture_offset_y;
	if (offset_x < 0 || offset_x > texture.width
		|| offset_y < 0 || offset_y > texture.height)
	{
		return (BLACK);
	}
	pixel_color = texture.dump[(offset_y * texture.width) + offset_x];
	return (pixel_color);
}

void	change_sprite_color_intensity(t_sprite_data *sprite)
{
	float	color_factor;

	if (sprite->pixel_color == PINK)
		return ;
	color_factor = FOG_DIST / sprite->distance;
	change_color_intensity(&sprite->pixel_color, color_factor);
}
