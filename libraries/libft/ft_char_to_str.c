/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 17:34:32 by wleite            #+#    #+#             */
/*   Updated: 2022/01/03 23:18:37 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_char_to_str(char c, size_t len)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	ft_memset(str, c, len);
	str[len] = '\0';
	return (str);
}
