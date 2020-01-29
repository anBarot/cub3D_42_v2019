/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turn_rigth.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:38:40 by abarot            #+#    #+#             */
/*   Updated: 2020/01/29 17:38:54 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_turn_right(t_config *config)
{
	if (config->cam_angle == 360)
		config->cam_angle = 0;
	config->cam_angle += 20;
	if (config->cam_angle >= 135 && config->cam_angle < 225)
		config->dir = 'E';
	if (config->cam_angle >= 45 && config->cam_angle < 135)
		config->dir = 'N';
	if ((config->cam_angle >= 315 && config->cam_angle <= 360)
		|| (config->cam_angle >= 0 && config->cam_angle < 45))
		config->dir = 'W';
	if (config->cam_angle >= 225 && config->cam_angle < 315)
		config->dir = 'S';
	ft_display_screen(config);
}
