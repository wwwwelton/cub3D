/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_files_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 01:48:47 by jofelipe          #+#    #+#             */
/*   Updated: 2022/01/19 14:49:18 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean_gnl(char *tmp, int fd)
{
	if (fd == -1)
		return ;
	free(tmp);
	tmp = ft_get_next_line(fd);
	while (tmp)
	{
		free(tmp);
		tmp = ft_get_next_line(fd);
	}
	close (fd);
}

t_bool	is_first_character_invalid(int fd, char **tmp)
{
	int	i;

	i = 0;
	if (*tmp == NULL)
		return (false);
	while ((*tmp)[i] == ' ' || (*tmp)[i] == '\t')
		++i;
	if (ftex_is_in_set((*tmp)[i], "RNSEWCF\n") == false)
	{
		free(*tmp);
		*tmp = ft_get_next_line(fd);
		return (true);
	}
	return (false);
}

t_bool	validation_failed(t_params *params, char **map)
{
	if (map)
		print_colored_map(map);
	free_matrix(map);
	free(params->north);
	free(params->south);
	free(params->west);
	free(params->east);
	return (false);
}

t_bool	all_params_valid(t_params *params)
{
	if (params->north == NULL || params->east == NULL
		|| params->south == NULL || params->west == NULL)
		return (print_error(E_NOTEX));
	if (params->ceilcolor == -1 || params->floorcolor == -1)
		return (print_error(E_NORGB));
	return (true);
}
