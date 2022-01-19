/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 08:14:33 by jofelipe          #+#    #+#             */
/*   Updated: 2022/01/19 01:37:39 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	tr_matrix(char **matrix, char *del, char *replace)
{
	int	i;

	i = -1;
	while (matrix[++i])
		ftex_tr(matrix[i], del, replace);
}

static int	is_in_del(char c, char *del)
{
	int	i;

	i = -1;
	while (del[++i])
	{
		if (c == del[i])
			return (i);
	}
	return (-1);
}

static char	find_new(char *ret, int index)
{
	int	len;

	len = ft_strlen(ret);
	if (index > len - 1)
		return (ret[len - 1]);
	else
		return (ret[index]);
}

/**
 * @brief swaps any ocurrence of del in str with replace in order
 *
 * @param str
 * @param del
 * @param replace
 */
void	ftex_tr(char *str, char *del, char *replace)
{
	int		index;
	int		i;

	if (!str || !del || !replace)
		return ;
	i = -1;
	while (str[++i])
	{
		index = is_in_del(str[i], del);
		if (index == -1)
			continue ;
		str[i] = find_new(replace, index);
	}
}
