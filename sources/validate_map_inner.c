/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_inner.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 04:59:34 by jofelipe          #+#    #+#             */
/*   Updated: 2022/01/21 08:09:27 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initial_map_cleanup(char **map)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (map[++i])
	{
		while (map[i][++j])
		{
			printf("%s\n", map[i]);
			if (map[i][j] == '1' && !is_not_adjacent(map, i, j, '0'))
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
