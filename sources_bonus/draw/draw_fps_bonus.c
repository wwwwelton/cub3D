/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fps_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/16 02:29:32 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	get_fps_img(char c)
{
	return (FPS_0 + (c - '0'));
}

void	draw_fps(t_data *data)
{
	int	x;
	int	y;
	int	image;

	x = WIN_WIDTH - FPSXOFF;
	y = FPSYOFF;
	image = get_fps_img(data->frame.fps[2]);
	copy_layer(&data->img[image], &data->img[FPS], x, y);
	x -= data->img[image].width;
	image = get_fps_img(data->frame.fps[1]);
	copy_layer(&data->img[image], &data->img[FPS], x, y);
	x -= data->img[image].width;
	image = get_fps_img(data->frame.fps[0]);
	if (image != FPS_0)
		copy_layer(&data->img[image], &data->img[FPS], x, y);
}
