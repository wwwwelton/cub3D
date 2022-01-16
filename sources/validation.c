/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:33:46 by jofelipe          #+#    #+#             */
/*   Updated: 2022/01/15 23:31:57 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	map_validation(char **map)
{
	t_bool	boolean;

	outline_polygon(map);
	if (is_player_polygon_closed(map))
		boolean = true;
	else
		boolean = false;
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
	params->ceilcolor = 0;
	params->floorcolor = 0;
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
	if (!map_validation(fetch_map_array(argv)))
		return (false);
	if (!files_validation(&data->params, argv[1]))
		return (false);
	return (true);
}
