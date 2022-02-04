/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/04 05:00:49 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	get_minimap_matrix(t_data *data)
// {
// 	t_xy	player;
// 	char	matrix[12][12];
// 	int		x;
// 	int		y;
// 	int		ctrx;
// 	int		ctry;

// 	player = get_coordinates(data->map, 0, 0);
// 	x = player.x - 5;
// 	y = player.y - 5;
// 	ctrx = -1;
// 	ctry = -1;
// 	while (++ctrx < 12)
// 	{
// 		while (++ctry < 12)
// 		{
// 			if (x < 0 || y < 0)
// 				matrix[ctrx][ctry] = 0;
// 			else
// 				matrix[ctrx][ctry] = data->map[player.x][player.y];
// 			y++;
// 			ctry++;
// 		}
// 		y =
// 	}
// }

int	get_height(char **map)
{
	int	i;
	int	ret;

	ret = 0;
	i = -1;
	while (map[++i])
		ret++;
	return (ret);
}

void	draw_map(t_data *data)
{
	int	y;
	int	x;
	char **map = data->map;
	t_xy	player;
	t_fill params;
	int		len;
	int		height;

	height = get_height(data->map);
	len = ft_strlen(data->map[0]);
	x = -1;
	y = -1;
	(void)player;
	player = get_coordinates(map, 0, 0);
	while (++x < 11)
	{
		while (++y < 11)
		{
			// printf("player.x %d player.y %d\n", player.x + x - 5, player.y + y - 5);
			params = fillparams(WIN_HEIGHT - 50 - (22 * x), (22 * y) + 50, 21, 21);
			if (player.x + x - 5 < 0 || player.y + y - 5 < 0)
			{
				printf ("%c", 'V');
				fill(&data->img[SCREEN], params, GRAY);
			}
			else if (player.x + x - 4 > len || player.y + y - 4 > height)
			{
				printf ("%c", 'V');
				fill(&data->img[SCREEN], params, GRAY);
			}
			else if (ftex_is_in_set(map[player.x + x - 5][player.y + y - 5], "@!"))
			{
				printf ("%c", map[player.x + x - 5][player.y + y - 5]);
				fill(&data->img[SCREEN], params, RED);
			}
			else if (ftex_is_in_set(map[player.x + x - 5][player.y + y - 5], "NSEW"))
			{
				printf ("%c", map[player.x + x - 5][player.y + y - 5]);
				fill(&data->img[SCREEN], params, YELLOW);
			}
			else
			{
				// printf ("%c ", map[player.x + x - 5][player.y + y - 5]);
				fill(&data->img[SCREEN], params, GRAY);
			}
		}
		printf("\n");
		y = -1;
	}
	printf("\n");
	printf("\n");
}

// void	draw_map(t_data *data)
// {
// 	int		x;
// 	int		y;
// 	t_img	*img;
// 	t_rect	rect;

// 	rect.width = TILE_SIZE * MINIMAP_SCALE_FACTOR;
// 	rect.height = TILE_SIZE * MINIMAP_SCALE_FACTOR;
// 	img = &data->img[MAP];
// 	y = -1;
// 	while (++y < map_height(data))
// 	{
// 		x = -1;
// 		while (++x < map_width(data))
// 		{
// 			rect.x = x * TILE_SIZE * MINIMAP_SCALE_FACTOR;
// 			rect.y = y * TILE_SIZE * MINIMAP_SCALE_FACTOR;
// 			if (ftex_is_in_set(data->map[y][x], "!@"))
// 				rect.color = WHITE;
// 			else if (ftex_is_in_set(data->map[y][x], "0N"))
// 				rect.color = BLACKB;
// 			else
// 				continue ;
// 			draw_rect(img, rect);
// 		}
// 	}
// }
