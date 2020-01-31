/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turn_left.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:38:17 by abarot            #+#    #+#             */
/*   Updated: 2020/01/31 15:07:27 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_turn_left(t_config *config)
{
	if (config->cam_angle == 0)
		config->cam_angle = 360;
	config->cam_angle -= 20;
	mlx_clear_window(config->mlx_ptr, config->win_ptr);
	// ft_display_screen(config);
}