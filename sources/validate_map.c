/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 01:09:04 by jofelipe          #+#    #+#             */
/*   Updated: 2022/01/18 03:02:56 by jofelipe         ###   ########.fr       */
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
	if (map[x + 1] && map[x + 1][y] == EDGE)
		return (crawl_polygon(map, x + 1, y));
	if (y > 0 && map[x][y - 1] == EDGE)
		return (crawl_polygon(map, x, y - 1));
	if (x > 0 && map[x - 1][y] == EDGE)
		return (crawl_polygon(map, x - 1, y));
	if (map[x][y + 1] == EDGE)
		return (crawl_polygon(map, x, y + 1));
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
			map[x][y] = '!';
			printf("failure\n");
			return (false);
		}
		if (forked_polygon(map, x, y))
		{
			if (recurse_polygon(map, x, y))
			{
				map[x][y] = '!';
				printf("success\n");
				return (true);
			}
		}
	}
}

void	tr_matrix(char **matrix, char *del, char *replace)
{
	int	i;

	i = -1;
	while (matrix[++i])
		ftex_tr(matrix[i], del, replace);
}

t_bool	is_player_inside(char **map)
{
	int	i;
	int	j;
	int	inside;

	inside = 0;
	i = -1;
	j = -1;
	while (map[++i])
	{
		while(map[i][++j])
		{
			while (map[i][j] == '!')
				j++;
			if (ft_strchr(&map[i][j], '!'))
				inside = 1;
			while (map[i][++j] != '!' && inside)
				if (ftex_is_in_set(map[i][j], "NSWE"))
					return (true);
			inside = 0;
		}
		j = -1;
	}
	return (false);
}

t_xy	get_coordinates(char **map, int x, int y)
{
	t_xy xy;

	xy.x = x - 1;
	xy.y = y - 1;
	while (map[++xy.x])
	{
		printf("%s\n", map[xy.x]);
		while (map[xy.x][++xy.y])
			if (ftex_is_in_set(map[xy.x][xy.y], "NSEW"))
				break ;
		if (ftex_is_in_set(map[xy.x][xy.y], "NSEW"))
			break ;
		xy.y = -1;
	}
	return (xy);
}

t_bool	is_player_polygon_closed(char **map)
{
	t_xy xy;

	xy = get_coordinates(map, 0, 0);
	if (xy.x == 0 || map[xy.x][xy.y + 1] == '\0')
		return (false);
	while (map[xy.x][xy.y] && map[xy.x][xy.y] != '9')
		xy.y++;
	if (crawl_polygon(map, xy.x, xy.y))
	{
		if (is_player_inside(map))
			tr_matrix(map, "!", "@");
		return (true);
	}
	return (false);
}
