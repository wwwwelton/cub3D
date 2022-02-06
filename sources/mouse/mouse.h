/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 06:15:57 by jofelipe          #+#    #+#             */
/*   Updated: 2022/02/05 23:56:47 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_H
# define MOUSE_H

void	check_mouse_visibility(t_data *data);
int		mouse_handler(int x, int y, t_data *data);

#endif
