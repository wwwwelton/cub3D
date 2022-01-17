/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 23:22:41 by jofelipe          #+#    #+#             */
/*   Updated: 2022/01/16 21:09:42 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	files_cleanup(t_params *params, char *tmp, int fd)
{
	free(params->north);
	free(params->south);
	free(params->west);
	free(params->east);
	free(tmp);
	tmp = ft_get_next_line(fd);
	while (tmp)
	{
		free(tmp);
		tmp = ft_get_next_line(fd);
	}
	close (fd);
	return (false);
}

t_bool	validate_texture_file(char *file, char **store)
{
	int		fd;
	char	*dot;

	if (*store)
	{
		ft_putstr_fd(E_TEXDUP, 2);
		return (false);
	}
	dot = ft_strrchr(file, '.');
	if (!dot || ft_strncmp(dot, ".xpm\n", 5))
	{
		ft_putstr_fd(E_TEXEXT, 2);
		ft_putstr_fd(file, 2);
		return (false);
	}
	file[ft_strlen(file) - 1] = '\0';
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(E_TEXINVAL, 2);
		ft_putstr_fd(file, 2);
		close(fd);
		return (false);
	}
	close(fd);
	*store = ft_strdup(file);
	return (true);
}

t_bool	validate_color_set(char *set, int *store)
{
	char	**rgb;
	int		i;
	t_bool	boolean;

	boolean = true;
	set = ftex_strerase(set, " ");
	rgb = ft_split(set, ',');
	i = -1;
	while (rgb[++i])
		if (ft_atoi(rgb[i]) > 255 || ft_atoi(rgb[i]) < 0)
		{
			ft_putstr_fd(E_RGBRANGE, 2);
			boolean = false;
		}
	if (i > 3)
	{
		ft_putstr_fd(E_RGBMUCH, 2);
		boolean = false;
	}
	*store = get_color(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	free_matrix(rgb);
	return (boolean);
}

t_bool	files_validation(t_params *params, char *file)
{
	int		fd;
	char	*tmp;
	char	**matrix;
	t_bool	boolean;

	boolean = true;
	matrix = NULL;
	fd = open(file, O_RDONLY);
	tmp = ft_get_next_line(fd);
	if (!tmp || fd == -1)
		return (false);
	while (tmp && boolean)
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
			boolean = false;
			printf(E_IDINVAL, file, matrix[0]);
			continue ;
		}
		if (!ft_strncmp(matrix[0], "NO", 2))
			boolean = validate_texture_file(matrix[1], &params->north);
		if (!ft_strncmp(matrix[0], "SO", 2))
			boolean = validate_texture_file(matrix[1], &params->south);
		if (!ft_strncmp(matrix[0], "EA", 2))
			boolean = validate_texture_file(matrix[1], &params->east);
		if (!ft_strncmp(matrix[0], "WE", 2))
			boolean = validate_texture_file(matrix[1], &params->west);
		if (!ft_strncmp(matrix[0], "F", 2))
			boolean = validate_color_set(matrix[1], &params->floorcolor);
		if (!ft_strncmp(matrix[0], "C", 2))
			boolean = validate_color_set(matrix[1], &params->ceilcolor);
		free_matrix(matrix);
		free(tmp);
		tmp = ft_get_next_line(fd);
	}
	if (boolean == false)
	{
		files_cleanup(params, tmp, fd);
		return (false);
	}
	return (true);
}
