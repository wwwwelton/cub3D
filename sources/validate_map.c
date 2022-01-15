/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 01:09:04 by jofelipe          #+#    #+#             */
/*   Updated: 2022/01/15 01:51:05 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	outline_polygon(char **map)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (map[++x])
	{
		while (map[x][++y])
			if (map[x][y] == '1')
				if (is_char_adjacent(map, x, y, ' ') == true)
					map[x][y] = EDGE;
		y = -1;
	}
}

t_bool	forked_polygon(char **map, int x, int y)
{
	int	i;

	i = 0;
	if (map[x][y + 1] == EDGE)
		i++;
	if (y > 0 && map[x][y - 1] == EDGE)
		i++;
	if (map[x + 1] && map[x + 1][y] == EDGE)
		i++;
	if (x > 0 && map[x - 1][y] == EDGE)
		i++;
	if (i < 2)
		return (false);
	return (true);
}

t_bool	recurse_polygon(char **map, int x, int y)
{
	if (map[x][y + 1] == EDGE)
		return (crawl_polygon(map, x, y + 1));
	if (y > 0 && map[x][y - 1] == EDGE)
		return (crawl_polygon(map, x, y - 1));
	if (map[x + 1] && map[x + 1][y] == EDGE)
		return (crawl_polygon(map, x + 1, y));
	if (x > 0 && map[x - 1][y] == EDGE)
		return (crawl_polygon(map, x - 1, y));
	return (false);
}

t_bool	crawl_polygon(char **map, int x, int y)
{
	while (1)
	{
		if (map[x + 1] && map[x + 1][y] == EDGE)
			map[x++][y] = '!';
		else if (y > 0 && map[x][y - 1] == EDGE)
			map[x][y--] = '!';
		else if (x > 0 && map[x - 1][y] == EDGE)
			map[x--][y] = '!';
		else if (map[x][y + 1] == EDGE)
			map[x][y++] = '!';
		else if (check_end(map, x, y))
		{
			printf("success\n");
			return (true);
		}
		else
		{
			printf("failure\n");
			return (false);
		}
		if (forked_polygon(map, x, y))
		{
			if (recurse_polygon(map, x, y))
			{
				printf("success\n");
				return (true);
			}
		}
	}
}

t_bool	is_player_polygon_closed(char **map)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (map[++x])
	{
		printf("%s\n", map[x]);
		while (map[x][++y])
			if (ftex_is_in_set(map[x][y], "NSEW"))
				break ;
		if (ftex_is_in_set(map[x][y], "NSEW"))
			break ;
		y = -1;
	}
	if (x == 0 || map[x][y + 1] == '\0')
		return (false);
	while (map[x][y] && map[x][y] != '9')
		y++;
	if (crawl_polygon(map, x, y))
		return (true);
	return (false);
}
