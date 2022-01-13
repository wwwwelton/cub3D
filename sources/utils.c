/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/13 20:07:51 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > IMG_WIDTH || y < 0 || y > IMG_HEIGHT)
		return ;
	dst = (char *)img->dump + (y * img->size_l + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_pixel_color(t_img *img, int x, int y, int width, int height)
{
	char	*dst;

	if (x < 0 || x > width || y < 0 || y > height)
		return (1);
	dst = (char *)img->dump + (y * img->size_l + x * (img->bpp / 8));
	return (*(unsigned int *)dst);
}

void	init_img(t_data *data, t_img *img, int width, int heigth)
{
	t_mlx	*mlx;

	mlx = &data->mlx;
	img->img_ptr = mlx_new_image(mlx->mlx_ptr, width, heigth);
	img->dump = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_l, &img->endian);
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

void	put_image_to_screen(t_img *img_src, t_img *img_dst, int color)
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

void	img_init(t_data *data, t_img *img, char *image_path)
{
	t_mlx	*mlx;

	mlx = &data->mlx;
	img->img_ptr = mlx_xpm_file_to_image
		(mlx->mlx_ptr, image_path, &data->img_width, &data->img_height);
	img->dump = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_l, &img->endian);
}

int	exit_game(t_data *data)
{
	mlx_destroy_image(data->mlx.mlx_ptr, data->img_bg.img_ptr);
	mlx_destroy_image(data->mlx.mlx_ptr, data->img_screen.img_ptr);
	mlx_destroy_image(data->mlx.mlx_ptr, data->img_rays.img_ptr);
	mlx_destroy_image(data->mlx.mlx_ptr, data->img_tex1.img_ptr);
	mlx_destroy_image(data->mlx.mlx_ptr, data->img_tex2.img_ptr);
	mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.win);
	mlx_destroy_display(data->mlx.mlx_ptr);
	free(data->mlx.mlx_ptr);
	exit(0);
	return (0);
}
