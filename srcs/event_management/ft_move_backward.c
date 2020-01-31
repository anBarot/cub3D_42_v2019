/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_backward.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:37:44 by abarot            #+#    #+#             */
/*   Updated: 2020/01/31 15:07:24 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_move_backward(t_config *config)
{
	if (NORTH_DIR(config->cam_angle) &&
		config->map[config->player_coord[0] + 1][config->player_coord[1]] != '1')
		config->player_coord[0] += 1;
	else if (WEST_DIR(config->cam_angle) &&
		config->map[config->player_coord[0]][config->player_coord[1] + 1] != '1')
		config->player_coord[1] += 1;
	else if (SOUTH_DIR(config->cam_angle) &&
		config->map[config->player_coord[0] - 1][config->player_coord[1]] != '1')
		config->player_coord[0] -= 1;
	else if	(EAST_DIR(config->cam_angle) &&
		config->map[config->player_coord[0]][config->player_coord[1] - 1] != '1')
		config->player_coord[1] -= 1;
	mlx_clear_window(config->mlx_ptr, config->win_ptr);
	// ft_display_screen(config);
}
