/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:36:18 by wleite            #+#    #+#             */
/*   Updated: 2022/01/28 19:42:22 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
