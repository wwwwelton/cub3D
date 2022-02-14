/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/14 18:44:09 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_img(t_data *data, t_img *img, int width, int heigth)
{
	t_mlx	*mlx;

	mlx = &data->mlx;
	img->img_ptr = mlx_new_image(mlx->mlx_ptr, width, heigth);
	img->height = WIN_HEIGHT;
	img->width = WIN_WIDTH;
	img->dump = (int *)
		mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_l, &img->endian);
}

void	init_xpm(t_data *data, t_img *img, char *image_path)
{
	t_mlx	*mlx;

	mlx = &data->mlx;
	img->img_ptr = mlx_xpm_file_to_image
		(mlx->mlx_ptr, image_path, &img->width, &img->height);
	img->dump = (int *)
		mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_l, &img->endian);
}
