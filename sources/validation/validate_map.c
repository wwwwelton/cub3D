/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 01:09:04 by jofelipe          #+#    #+#             */
/*   Updated: 2022/02/04 04:26:35 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	if (map[x + 1] && map[x + 1][y] == EDGE)
		return (crawl_polygon(map, x + 1, y, OUTER));
	if (y > 0 && map[x][y - 1] == EDGE)
		return (crawl_polygon(map, x, y - 1, OUTER));
	if (x > 0 && map[x - 1][y] == EDGE)
		return (crawl_polygon(map, x - 1, y, OUTER));
	if (map[x][y + 1] == EDGE)
		return (crawl_polygon(map, x, y + 1, OUTER));
	return (false);
}

t_bool	crawl_polygon(char **map, int x, int y, char fill)
{
	while (1)
	{
		if (map[x + 1] && map[x + 1][y] == EDGE)
			map[x++][y] = fill;
		else if (y > 0 && map[x][y - 1] == EDGE)
			map[x][y--] = fill;
		else if (x > 0 && map[x - 1][y] == EDGE)
			map[x--][y] = fill;
		else if (map[x][y + 1] == EDGE)
			map[x][y++] = fill;
		else if (check_end(map, x, y, fill))
		{
			map[x][y] = fill;
			return (true);
		}
		else
			return (false);
		if (forked_polygon(map, x, y))
		{
			if (recurse_polygon(map, x, y))
				return (true);
		}
	}
}

t_xy	get_coordinates(char **map, int x, int y)
{
	t_xy	xy;

	xy.x = x - 1;
	xy.y = y - 1;
	while (map[++xy.x])
	{
		while (map[xy.x][++xy.y])
			if (ftex_is_in_set(map[xy.x][xy.y], "NSEW"))
				break ;
		if (ftex_is_in_set(map[xy.x][xy.y], "NSEW"))
			break ;
		xy.y = -1;
	}
	if (xy.y == -1)
		xy.y++;
	return (xy);
}

t_bool	is_player_polygon_closed(char **map)
{
	t_xy	xy;
	t_bool	boolean;

	boolean = true;
	xy = get_coordinates(map, 0, 0);
	if (xy.x == 0 || map[xy.x][xy.y + 1] == '\0')
		return (false);
	while (map[xy.x][xy.y] && map[xy.x][xy.y] != EDGE)
		xy.y++;
	while (boolean)
	{
		boolean = crawl_polygon(map, xy.x, xy.y, OUTER);
		while (!is_player_inside(map, -1, -1))
		{
			tr_matrix(map, "!", "@");
			xy = get_coordinates(map, 0, 0);
			if (xy.x == 0 || !ft_strchr(&map[xy.x][xy.y], EDGE))
				return (false);
			while (map[xy.x][xy.y] && map[xy.x][xy.y] != EDGE)
				xy.y++;
			boolean = crawl_polygon(map, xy.x, xy.y, OUTER);
		}
		return (boolean);
	}
	return (false);
}
