/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/28 18:57:31 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_color(int r, int g, int b)
{
	int	rgb;

	rgb = 0;
	rgb += (r & 0xFF) << 16;
	rgb += (g & 0XFF) << 8;
	rgb += (b & 0XFF);
	return (rgb);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = -1;
	if (!matrix)
		return ;
	while (matrix[++i])
		ft_free_ptr((void *)&matrix[i]);
	free(matrix);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > IMG_WIDTH || y < 0 || y > IMG_HEIGHT)
		return ;
	dst = (char *)img->dump + (y * img->size_l + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

t_bool	ftex_is_in_set(char c, char *set)
{
	if (!set)
		return (false);
	while (*set)
	{
		if (c == *set)
			return (true);
		set++;
	}
	return (false);
}

int	get_pixel_color(t_img *img, int x, int y, int width, int height)
{
	char	*dst;

	if (x < 0 || x > width || y < 0 || y > height)
		return (1);
	dst = (char *)img->dump + (y * img->size_l + x * (img->bpp / 8));
	return (*(unsigned int *)dst);
}

void	fill_color(t_img *img, int color)
{
	int		count_w;
	int		count_h;

	count_h = -1;
	while (++count_h < IMG_HEIGHT)
	{
		count_w = -1;
		while (++count_w < IMG_WIDTH)
			img->dump[count_h * IMG_WIDTH + count_w] = color;
	}
}

void	_copy_layer(t_img *from, t_img *to, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++j < from->height)
	{
		while (++i < from->width)
		{
			if (from->dump[i + j * from->size_l / 4] != BLACK)
			to->dump[x + i + ((y + j) * to->size_l / 4)]
				= from->dump[i + j * from->size_l / 4];
		}
		i = -1;
	}
}

void	copy_layer(t_img *img_src, t_img *img_dst, int color)
{
	int		count_w;
	int		count_h;

	count_h = -1;
	while (++count_h < IMG_HEIGHT)
	{
		count_w = -1;
		while (++count_w < IMG_WIDTH)
		{
			if (img_dst->dump[count_h * IMG_WIDTH + count_w] == color)
				img_dst->dump[count_h * IMG_WIDTH + count_w]
					= img_src->dump[count_h * IMG_WIDTH + count_w];
		}
	}
}

void	draw_vert_pixel(t_img *img, int x0, int y0, int thick, int color)
{
	int	i;

	i = -1;
	while (++i < thick)
		my_mlx_pixel_put(img, x0 + i, y0, color);
}

void	draw_rect(t_img *img, t_rect rect)
{
	int		x;
	int		y;

	rect.height += rect.y;
	rect.width += rect.x;
	y = rect.y - 1;
	while (++y < rect.height)
	{
		x = rect.x - 1;
		while (++x < rect.width)
		{
			if (y < 0 || y >= WIN_HEIGHT || x < 0 || x >= WIN_WIDTH)
				return ;
			img->dump[y * IMG_WIDTH + x] = rect.color;
		}
	}
}

void	normalizeAngle(float *angle)
{
	*angle = remainder(*angle, TWO_PI);
	if (*angle < 0)
		*angle = TWO_PI + *angle;
}

int	loop_hook(t_data *data)
{
	if (data->state == MENU)
		draw_menu(data);
	if (data->state == GAME)
	{
		update_player(data);
		draw_screen(data);
	}
	if (data->state == OPTIONS)
		draw_options(data);
	return (0);
}

void	draw_line(t_img *img, t_line line)
{
	line.dx =  abs(line.x1 - line.x0);
	line.sx = line.x0 < line.x1 ? 1 : -1;
	line.dy = -abs(line.y1 - line.y0);
	line.sy = line.y0 < line.y1 ? 1 : -1;
	line.err = line.dx + line.dy;
	while (1)
	{
		if (line.x0 == line.x1 && line.y0 == line.y1)
			break ;
		if (line.x0 < 0 || line.x0 >= WIN_WIDTH
			|| line.y0 < 0 || line.y0 >= WIN_HEIGHT)
			break ;
		my_mlx_pixel_put(img, line.x0, line.y0, line.color);
		line.e2 = 2 * line.err;
		if (line.e2 >= line.dy)
		{
			line.err += line.dy;
			line.x0 += line.sx;
		}
		if (line.e2 <= line.dx)
		{
			line.err += line.dx;
			line.y0 += line.sy;
		}
	}
}

int	exit_game(t_data *data)
{
	int	i;

	i = -1;
	while (++i < TEX_NB)
		mlx_destroy_image(data->mlx.mlx_ptr, data->img[i].img_ptr);
	free(data->params.north);
	free(data->params.south);
	free(data->params.west);
	free(data->params.east);
	free_matrix(data->map);
	free_matrix(data->devmap);
	mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.win);
	mlx_destroy_display(data->mlx.mlx_ptr);
	free(data->mlx.mlx_ptr);
	exit(0);
	return (0);
}
