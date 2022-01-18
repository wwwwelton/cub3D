/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:33:46 by jofelipe          #+#    #+#             */
/*   Updated: 2022/01/18 05:20:21 by jofelipe         ###   ########.fr       */
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
		while (map[i][++j] != '!')
			map[i][j] = ' ';
		j = ft_strlen(map[i]);
		while (map[i][--j] != '!')
			map[i][j] = ' ';
		j = -1;
	}
}

t_bool	map_validation(char **map)
{
	t_bool	boolean;

	outline_polygon(map);
	outline_useless_walls(map);
	boolean = is_player_polygon_closed(map);
	if (boolean)
		remove_outer_characters(map);
	boolean = are_inner_polygons_closed(map);
	if (DEBUG)
	{
		printf("outline\n");
		print_colored_map(map);
	}
	free_matrix(map);
	return (boolean);
}

static void	initialize_params(t_params *params)
{
	params->ceilcolor = -1;
	params->floorcolor = -1;
	params->east = NULL;
	params->north = NULL;
	params->south = NULL;
	params->west = NULL;
}

t_bool	validation(t_data *data, int argc, char **argv)
{
	initialize_params(&data->params);
	if (!argument_validation(data, argc, argv))
		return (false);
	if (!files_validation(&data->params, argv[1]))
		return (false);
	if (!map_validation(fetch_map_array(argv)))
		return (false);
	return (true);
}
