/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:33:46 by jofelipe          #+#    #+#             */
/*   Updated: 2022/01/19 01:43:03 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	map_validation(char **map)
{
	if (DEBUG)
		print_map(map);
	if (!validate_map_characters(map))
	{
		free_matrix(map);
		return (print_error(E_MAPINVAL3));
	}
	outline_polygon(map);
	outline_useless_walls(map);
	if (!is_player_polygon_closed(map))
	{
		free_matrix(map);
		return (print_error(E_MAPOPEN));
	}
	remove_outer_characters(map);
	if (!are_inner_polygons_closed(map))
	{
		free_matrix(map);
		return (print_error(E_MAPOPEN2));
	}
	print_colored_map(map);
	free_matrix(map);
	return (true);
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
	if (!map_validation(fetch_map_array(argv)))
		return (validation_cleanup(&data->params));
	if (!files_validation(&data->params, argv[1]))
		return (false);
	return (true);
}
