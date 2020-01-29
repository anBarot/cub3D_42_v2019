/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:05:01 by abarot            #+#    #+#             */
/*   Updated: 2020/01/29 17:42:58 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_pressed_key(int keycode, t_config *config)
{
	mlx_clear_window(config->mlx_ptr, config->win_ptr);
	if (UPKEY(keycode))
		ft_move_forward(config);
	else if (DOWNKEY(keycode))
		ft_move_backward(config);
	else if (LEFTKEY(keycode))
		ft_turn_left(config);
	else if (RIGHTKEY(keycode))
		ft_turn_right(config);
	else if (LEFT_LAT_LKEY(keycode))
		ft_move_lat_left(config);
	else if (RIGHT_LAT_KEY(keycode))
		ft_move_lat_right(config);
	else if (ESCAPEKEY(keycode))
	{	
		mlx_destroy_window(config->mlx_ptr, config->win_ptr);
		return (0);
	}
	ft_display_screen(config);
	return (1);
}
