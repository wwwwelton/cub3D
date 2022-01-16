/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 23:22:41 by jofelipe          #+#    #+#             */
/*   Updated: 2022/01/16 00:48:58 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	files_cleanup(char *tmp, char **matrix, int fd)
{
	free_matrix(matrix);
	free(tmp);
	close (fd);
	return (false);
}

t_bool	validate_texture_file(char *file, char **store)
{
	int		fd;
	char	*dot;

	dot = ft_strrchr(file, '.');
	if (!dot || ft_strncmp(dot, ".xpm\n", 5))
	{
		ft_putstr_fd(file, 2);
		ft_putstr_fd("incorrect file type\nexpected: .xpm\n", 2);
		return (false);
	}
	fd = open(file, O_RDONLY | O_CREAT, 0777);
	file[ft_strlen(file) - 1] = '\0';
	if (fd == -1)
	{
		ft_putstr_fd(file, 2);
		ft_putstr_fd("file does not exist or incorrect permissions\n", 2);
		close(fd);
		return (false);
	}
	close(fd);
	*store = ft_strdup(file);
	return (true);
}

t_bool	files_validation(t_params *params, char *file)
{
	int		fd;
	char	*tmp;
	char	**matrix;

	fd = open(file, O_RDONLY);
	tmp = ft_get_next_line(fd);
	if (!tmp || fd == -1)
		return (false);
	while (tmp)
	{
		if (ftex_is_in_set(*tmp, "RNSEWCF\n") == false)
		{
			free(tmp);
			tmp = ft_get_next_line(fd);
			continue ;
		}
		matrix = ft_split(tmp, ' ');
		if (ft_strlen(matrix[0]) > 3)
		{
			printf("%s: Invalid identifier: %s\n", file, matrix[0]);
			return (files_cleanup(tmp, matrix, fd));
		}
		if (!ft_strncmp(matrix[0], "NO", 2))
			if (validate_texture_file(matrix[1], &params->north) == false)
				return (files_cleanup(tmp, matrix, fd));
		free_matrix(matrix);
		free(tmp);
		tmp = ft_get_next_line(fd);
	}
	return (true);
}
