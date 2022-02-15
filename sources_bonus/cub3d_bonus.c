/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/05 22:28:20 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (validation(&data, argc, argv) == false)
		exit (EXIT_FAILURE);
	data.state = MENU;
	init_data(&data);
	mlx_hook(data.mlx.win, 6, 1L << 6, mouse_handler, &data);
	mlx_hook(data.mlx.win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.mlx.win, 3, 1L << 1, key_release, &data);
	mlx_hook(data.mlx.win, X_EVENT_DESTROY_NOTIFY, 0, &exit_game, &data);
	mlx_loop_hook(data.mlx.mlx_ptr, &game_loop, &data);
	mlx_loop(data.mlx.mlx_ptr);
	return (0);
}
