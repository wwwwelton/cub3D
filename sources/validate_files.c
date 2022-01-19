/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 23:22:41 by jofelipe          #+#    #+#             */
/*   Updated: 2022/01/19 01:15:33 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean_gnl(char *tmp, int fd)
{
	free(tmp);
	tmp = ft_get_next_line(fd);
	while (tmp)
	{
		free(tmp);
		tmp = ft_get_next_line(fd);
	}
	close (fd);
}


t_bool	validation_cleanup(t_params *params)
{
	free(params->north);
	free(params->south);
	free(params->west);
	free(params->east);
	return (false);
}

t_bool	map_cleanup(t_params *params)
{
	free(params->north);
	free(params->south);
	free(params->west);
	free(params->east);
	return (false);
}

t_bool	validate_texture_file(char *file, char **store)
{
	int		fd;
	char	*dot;

	if (*store)
		return (print_error(E_TEXDUP));
	if (!file)
		return (false);
	dot = ft_strrchr(file, '.');
	if (!dot || ft_strncmp(dot, ".xpm\n", 5))
	{
		printf("%s%s", E_TEXEXT, file);
		return (false);
	}
	file[ft_strlen(file) - 1] = '\0';
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("%s%s", E_TEXINVAL, file);
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
	char	*tmp;
	int		i;
	t_bool	boolean;

	boolean = true;
	tmp = ftex_strerase(set, " ");
	rgb = ft_split(tmp, ',');
	i = -1;
	while (rgb[++i])
		if (ft_atoi(rgb[i]) > 255 || ft_atoi(rgb[i]) < 0)
			boolean = print_error(E_RGBRANGE);
	if (i > 3)
		boolean = print_error(E_RGBMUCH);
	if (boolean)
		*store = get_color(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	free(tmp);
	free_matrix(rgb);
	return (boolean);
}

char	*concatenate_color_set(char **matrix)
{
	int		i;
	char	*ret;
	char	*tmp;

	i = -1;
	while (matrix[++i])
		continue ;
	if (i < 2)
		return (matrix[1]);
	i = 1;
	ret = ft_strdup(matrix[1]);
	while (matrix[++i])
	{
		tmp = ret;
		ret = ft_strjoin(ret, matrix[i]);
		free(tmp);
	}
	free(matrix[1]);
	return (ret);
}

t_bool	check_matrix(t_params *params, char **matrix, char *file, char *tmp)
{
	t_bool	boolean;

	boolean = true;
	matrix = ft_split(tmp, ' ');
	matrix[1] = concatenate_color_set(matrix);
	if (ft_strlen(matrix[0]) > 3)
	{
		boolean = false;
		printf(E_IDINVAL, file, matrix[0]);
	}
	if (!ft_strncmp(matrix[0], "NO", 2) && boolean)
		boolean = validate_texture_file(matrix[1], &params->north);
	if (!ft_strncmp(matrix[0], "SO", 2) && boolean)
		boolean = validate_texture_file(matrix[1], &params->south);
	if (!ft_strncmp(matrix[0], "EA", 2) && boolean)
		boolean = validate_texture_file(matrix[1], &params->east);
	if (!ft_strncmp(matrix[0], "WE", 2) && boolean)
		boolean = validate_texture_file(matrix[1], &params->west);
	if (!ft_strncmp(matrix[0], "F", 2) && boolean)
		boolean = validate_color_set(matrix[1], &params->floorcolor);
	if (!ft_strncmp(matrix[0], "C", 2) && boolean)
		boolean = validate_color_set(matrix[1], &params->ceilcolor);
	free_matrix(matrix);
	free(tmp);
	return (boolean);
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

t_bool	all_params_valid(t_params *params)
{
	if (DEBUG)
	{
		printf("\n=====PARAMS=======\n");
		printf("%s\n", params->north);
		printf("%s\n", params->west);
		printf("%s\n", params->east);
		printf("%s\n", params->south);
		printf("%d\n", params->floorcolor);
		printf("%d\n", params->ceilcolor);
	}
	if (params->north == NULL || params->east == NULL
		|| params->south == NULL || params->west == NULL)
		return (print_error(E_NOTEX));
	if (params->ceilcolor == -1 || params->floorcolor == -1)
		return (print_error(E_NORGB));
	return (true);
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
		if (is_first_character_invalid(fd, &tmp))
			break ;
		boolean = check_matrix(params, matrix, file, tmp);
		tmp = ft_get_next_line(fd);
	}
	clean_gnl(tmp, fd);
	boolean = all_params_valid(params);
	if (boolean == false)
		return (validation_cleanup(params));
	return (true);
}
