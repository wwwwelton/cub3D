/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 06:15:57 by jofelipe          #+#    #+#             */
/*   Updated: 2022/02/05 06:19:46 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_DESTROY_NOTIFY 17
# define K_PRESS 0
# define K_RELEASE 1

# define KEY_ESC 65307
# define KEY_Q 113

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ENTER 65293
# define KEY_N_ENTER 65421

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

# define KEY_A_UP 65362
# define KEY_A_LEFT 65361
# define KEY_A_DOWN 65364
# define KEY_A_RIGHT 65363

//controller
int		screen_controller(int key, t_data *data, int event_type);
void	keys_wasd(int key, t_data *data, int event_type);
void	keys_menu_wasd(int key, t_data *data);

//keys
int		key_press(int key, t_data *data);
int		key_release(int key, t_data *data);

#endif
