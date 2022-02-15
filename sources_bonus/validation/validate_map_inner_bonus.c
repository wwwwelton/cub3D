/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_inner.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 04:59:34 by jofelipe          #+#    #+#             */
/*   Updated: 2022/02/04 23:06:04 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_end(char **map, int x, int y, char c)
{
	return ((y > 0 && map[x][y + 1] == c && map[x][y - 1] == c)
	|| (x > 0 && map[x + 1] && map[x + 1][y] == c && map[x - 1][y] == c)
	|| (x > 0 && map[x - 1][y] == c && map[x][y + 1] == c)
	|| (x > 0 && y > 0 && map[x][y - 1] == c && map[x - 1][y] == c)
	|| (y > 0 && map[x + 1] && map[x + 1][y] == c && map[x][y - 1] == c)
	|| (map[x + 1] && map[x + 1][y] == c && map[x][y + 1] == c));
}

void	initial_map_cleanup(char **map)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (map[++i])
	{
		while (map[i][++j])
		{
			if (map[i][j] == '1' && !is_char_adjacent_to(map, i, j, '0')
			&& (is_char_adjacent_to(map, i, j, 'E') == false
			&& is_char_adjacent_to(map, i, j, 'W') == false
			&& is_char_adjacent_to(map, i, j, 'S') == false
			&& is_char_adjacent_to(map, i, j, 'N') == false))
				map[i][j] = ' ';
		}
		j = -1;
	}
}

t_bool	are_inner_polygons_closed(char **map)
{
	char	*inner_wall;
	int		i;

	i = -1;
	while (map[++i])
	{
		inner_wall = ft_strchr(map[i], EDGE);
		if (inner_wall)
		{
			if (crawl_polygon(map, i, inner_wall - map[i], INNER) == false)
				return (false);
			i--;
		}
	}
	return (true);
}
