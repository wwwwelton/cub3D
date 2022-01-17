/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/17 02:05:25 by jofelipe         ###   ########.fr       */
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

static int	istrimmed(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static int	strsize(char *str, char *set)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (!istrimmed(*str++, set))
			i++;
	}
	return (i);
}


char	*ftex_strerase(char *str, char *set)
{
	size_t	size;
	char	*res;

	if (!str)
		return (NULL);
	size = strsize(str, set);
	res = (char *)malloc(sizeof(char) * size + 1);
	while (*str)
	{
		if (!istrimmed(*str, set))
			*res++ = *str++;
		else
			str++;
	}
	*res = '\0';
	return (res - size);
}


void	free_matrix(char **matrix)
{
	int	i;

	i = -1;
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

int	loop_hook(t_data *data)
{
	draw_screen(data);
	return (0);
}

int	exit_game(t_data *data)
{
	free(data->params.north);
	free(data->params.south);
	free(data->params.west);
	free(data->params.east);
	mlx_destroy_image(data->mlx.mlx_ptr, data->img[BG].img_ptr);
	mlx_destroy_image(data->mlx.mlx_ptr, data->img[SCREEN].img_ptr);
	mlx_destroy_image(data->mlx.mlx_ptr, data->img[RAYS].img_ptr);
	mlx_destroy_image(data->mlx.mlx_ptr, data->img[TEX_NO].img_ptr);
	mlx_destroy_image(data->mlx.mlx_ptr, data->img[TEX_EA].img_ptr);
	mlx_destroy_image(data->mlx.mlx_ptr, data->img[TEX_SO].img_ptr);
	mlx_destroy_image(data->mlx.mlx_ptr, data->img[TEX_WE].img_ptr);
	mlx_destroy_image(data->mlx.mlx_ptr, data->img[TEX_FL].img_ptr);
	mlx_destroy_image(data->mlx.mlx_ptr, data->img[TEX_CE].img_ptr);
	mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.win);
	mlx_destroy_display(data->mlx.mlx_ptr);
	free(data->mlx.mlx_ptr);
	exit(0);
	return (0);
}
