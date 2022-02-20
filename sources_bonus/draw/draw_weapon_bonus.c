/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_weapon_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/20 00:56:23 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_weapon(t_data *data)
{
	int		x;
	int		y;
	t_img	*image;

	image = resize_image(&data->img[data->player.weapon], 6, data);
	x = middle_x(*image);
	y = WIN_HEIGHT - image->height;
	copy_layer(image, &data->img[WEAPON], x, y);
	mlx_destroy_image(data->mlx.mlx_ptr, image->img_ptr);
	free(image);
}
