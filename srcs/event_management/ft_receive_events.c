/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_receive_events.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:14:58 by abarot            #+#    #+#             */
/*   Updated: 2020/01/30 13:09:01 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		ft_receive_events(t_config *config, char *title)
{
	mlx_init(config->mlx_ptr);
	mlx_new_window(config->mlx_ptr, config->resol[0], config->resol[1], title);
	mlx_loop(config->mlx_ptr)
	mlx_mouse_hook(config->win_ptr, int (*ft_pressed_key)(), config)
	ft_display_screen(config);
	return (0);
}