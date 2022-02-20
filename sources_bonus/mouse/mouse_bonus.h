/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 06:15:57 by jofelipe          #+#    #+#             */
/*   Updated: 2022/02/20 10:29:26 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_BONUS_H
# define MOUSE_BONUS_H

int		mouse_move(int x, int y, t_data *data);
int		mouse_key_press(int button, int x, int y, t_data *data);
int		mouse_key_release(int button, int x, int y, t_data *data);

#endif
