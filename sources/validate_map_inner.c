/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_inner.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 04:59:34 by jofelipe          #+#    #+#             */
/*   Updated: 2022/01/18 05:31:30 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
			if (crawl_polygon(map, i, inner_wall - map[i], '@') == false)
				return (false);
			i--;
		}
	}
	return (true);
}
