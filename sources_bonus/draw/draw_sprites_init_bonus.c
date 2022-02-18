/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites_init_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/18 19:57:54 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static float	get_sprite_angle(t_sprite sprite, t_data *data)
{
	float	ret;

	ret = atan2(sprite.y - data->player.y,
			sprite.x - data->player.x) - data->player.rot_angle;
	return (ret);
}

static void	calculate_sprite_pixel_size(t_sprite_data *sprite, t_data *data)
{
	int	texture_width;
	int	texture_height;
	int	text_num;

	text_num = sprite->texture;
	texture_width = data->img[text_num].width;
	texture_height = data->img[text_num].height;
	sprite->pixel_width = texture_width / sprite->width;
	sprite->pixel_height = texture_height / sprite->height;
}

static void	calculate_sprite_x(t_sprite visible_sprite,
	t_sprite_data *sprite, t_data *data)
{
	float	angle;
	float	sprite_screen_x;

	angle = get_sprite_angle(visible_sprite, data);
	sprite_screen_x = tan(angle) * sprite->dist_proj_plane;
	sprite->left_x = (WIN_WIDTH / 2) + sprite_screen_x - (sprite->width / 2);
	sprite->right_x = sprite->left_x + sprite->width;
	if (sprite->right_x < 0)
		sprite->right_x = 0;
	if (sprite->right_x >= NUM_RAYS)
		sprite->right_x = NUM_RAYS;
}

void	init_sprite_data(t_sprite visible_sprite, t_sprite_data *sprite,
	t_data *data)
{
	float	perp_distance;

	sprite->win_height = WIN_HEIGHT + data->player.view_angle;
	sprite->dist_proj_plane = (WIN_WIDTH / 2) / tan(FOV_ANGLE / 2);
	perp_distance = visible_sprite.distance * cos(visible_sprite.angle);
	sprite->height = (TILE_SIZE / perp_distance) * sprite->dist_proj_plane;
	sprite->width = sprite->height;
	sprite->top_y = (sprite->win_height / 2) - (sprite->height / 2);
	if (sprite->top_y < 0)
		sprite->top_y = 0;
	if (sprite->top_y >= WIN_HEIGHT)
		sprite->top_y = WIN_HEIGHT;
	sprite->bottom_y = (sprite->win_height / 2) + (sprite->height / 2);
	if (sprite->bottom_y < 0)
		sprite->bottom_y = 0;
	if (sprite->bottom_y >= WIN_HEIGHT)
		sprite->bottom_y = WIN_HEIGHT;
	calculate_sprite_x(visible_sprite, sprite, data);
	sprite->texture = visible_sprite.texture;
	sprite->distance = visible_sprite.distance;
	calculate_sprite_pixel_size(sprite, data);
}
