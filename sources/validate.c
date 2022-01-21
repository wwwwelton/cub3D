/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:33:46 by jofelipe          #+#    #+#             */
/*   Updated: 2022/01/21 08:14:03 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	map_validation(char **map)
{
	if (DEBUG)
		print_map(map);
	if (!validate_map_characters(map))
		return (print_error(E_MAPINVAL3));
	outline_polygon(map);
	outline_useless_walls(map);
	if (!is_player_polygon_closed(map))
		return (print_error(E_MAPOPEN));
	remove_outer_characters(map);
	if (!are_inner_polygons_closed(map))
		return (print_error(E_MAPOPEN2));
	tr_matrix(map, "1", "@");
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
		return(validation_failed(&data->params, NULL));
	data->map = fetch_map_array(argv);
	initial_map_cleanup(data->map);
	if (!map_validation(data->map))
		return(validation_failed(&data->params, data->map));
	if (!files_validation(&data->params, argv[1]))
		return(validation_failed(&data->params, data->map));
	print_colored_map(data->map);
	return (true);
}
