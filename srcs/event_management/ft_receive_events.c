/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_receive_events.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:14:58 by abarot            #+#    #+#             */
/*   Updated: 2020/01/31 15:27:32 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		ft_receive_events(t_config *config, char *title)
{
	config->mlx_ptr = mlx_init();
	config->win_ptr = mlx_new_window(config->mlx_ptr, config->resol.x, config->resol.y, title);
	mlx_key_hook(config->win_ptr, &ft_pressed_key, config);
	mlx_loop(config->mlx_ptr);
	return (0);
}
