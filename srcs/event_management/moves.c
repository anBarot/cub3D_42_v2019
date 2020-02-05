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

void	ft_move_backandforth(t_config *config, int mv_value)
{
	if (NORTH_DIR(config->cam_angle) &&
		config->map[config->player_coord.x + mv_value][config->player_coord.y] != '1')
		config->player_coord.x += mv_value;
	else if (WEST_DIR(config->cam_angle) &&
		config->map[config->player_coord.x][config->player_coord.y + mv_value] != '1')
		config->player_coord.y += mv_value;
	else if (SOUTH_DIR(config->cam_angle) &&
		config->map[config->player_coord.x - mv_value][config->player_coord.y] != '1')
		config->player_coord.x -= mv_value;
	else if	(EAST_DIR(config->cam_angle) &&
		config->map[config->player_coord.x][config->player_coord.y - mv_value] != '1')
		config->player_coord.y -= mv_value;
	mlx_clear_window(config->mlx_ptr, config->win_ptr);
	// ft_display_screen(config);
}

void	ft_move_lateral(t_config *config, int mv_value)
{
	if (NORTH_DIR(config->cam_angle) &&
		config->map[config->player_coord.x][config->player_coord.y + mv_value] != '1')
		config->player_coord.y += mv_value;
	else if (WEST_DIR(config->cam_angle) &&
		config->map[config->player_coord.x - mv_value][config->player_coord.y] != '1')
		config->player_coord.x -= mv_value;
	else if (SOUTH_DIR(config->cam_angle) &&
		config->map[config->player_coord.x][config->player_coord.y - mv_value] != '1')
		config->player_coord.y -= mv_value;
	else if	(EAST_DIR(config->cam_angle) &&
		config->map[config->player_coord.x + mv_value][config->player_coord.y] != '1')
		config->player_coord.x += mv_value;
	mlx_clear_window(config->mlx_ptr, config->win_ptr);
	// ft_display_screen(config);
}

void	ft_turn(t_config *config, int angle_value)
{
	config->cam_angle += angle_value;
	if (config->cam_angle < 0)
		config->cam_angle += 360;
	if (config->cam_angle > 360)
		config->cam_angle -= 360;
	mlx_clear_window(config->mlx_ptr, config->win_ptr);
	// ft_display_screen(config);
}
