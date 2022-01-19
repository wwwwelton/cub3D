/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 01:38:56 by jofelipe          #+#    #+#             */
/*   Updated: 2022/01/19 04:31:09 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	remove_outer_characters(char **map)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (map[++i])
	{
		while (map[i][++j] && map[i][j] != OUTER)
			map[i][j] = ' ';
		j = ft_strlen(map[i]);
		while (--j >= 0 && map[i][j] != OUTER)
			map[i][j] = ' ';
		j = -1;
	}
}


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

void	outline_useless_walls(char **map)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (map[++x])
	{
		while (map[x][++y])
			if (map[x][y] == EDGE)
				if (is_char_adjacent(map, x, y, '0') == false
					&& is_char_adjacent(map, x, y, '1') == false)
					map[x][y] = FILLER;
		y = -1;
	}
}

t_bool	is_player_inside(char **map, int i, int j)
{
	while (map[++i])
	{
		while(map[i][++j])
		{
			if (map[i][j] == OUTER)
			{
				while (map[i][j] && map[i][++j] == OUTER)
					continue ;
				if (ft_strchr(&map[i][j], OUTER))
				{
					while (map[i][j] != OUTER)
					{
						if (ftex_is_in_set(map[i][j], "NSWE"))
							return (true);
						j++;
					}
				}
			}
			if (!map[i][j])
				j--;
		}
		j = -1;
	}
	return (false);
}

t_bool	validate_map_characters(char **map)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (map[++i])
	{
		while (map[i][++j])
			if (!ftex_is_in_set(map[i][j], "0123 NSEW"))
				return (false);
		j = -1;
	}
	return (true);
}
