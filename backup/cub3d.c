/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/04 22:19:19 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(void)
{
	t_data	data;

	mlx_start(&data);
	draw_screen(&data);
	mlx_hook(data.mlx.win, X_EVENT_KEY_PRESS, 1L << 0, &key_press, &data);
	mlx_hook(data.mlx.win, X_EVENT_DESTROY_NOTIFY, 0, &exit_game, &data);
	mlx_loop(data.mlx.mlx_ptr);
	return (0);
}
