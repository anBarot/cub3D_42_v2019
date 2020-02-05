/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_crosscoor_horizontal.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 15:32:44 by abarot            #+#    #+#             */
/*   Updated: 2020/01/30 12:19:14 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_get_crosscoord_horizontal(t_config *config, t_raycast *raycast)
{
	raycast->wall_coord_line = (double *)ft_calloc(sizeof(double), 2);
	raycast->wall_coord_line[0] = raycast->cube_player_coord.x;
	raycast->wall_coord_line[1] = raycast->cube_player_coord.y;
	if (config->cam_angle > 0 && config->cam_angle < 180)
	{	
		raycast->wall_coord_line[0] -= (WALL_SIZE / 2);
		raycast->wall_coord_line[1] += (WALL_SIZE / 2) / tan(RAD(180 - config->cam_angle));
	}
	else
	{
		raycast->wall_coord_line[0] += (WALL_SIZE / 2);
		raycast->wall_coord_line[1] += (WALL_SIZE / 2) / tan(RAD(config->cam_angle - 180));
	}
	while (config->map[(int)round(raycast->wall_coord_line[0] / WALL_SIZE)][(int)round(raycast->wall_coord_line[1] / WALL_SIZE)] == '0')
	{
		while (config->cam_angle > 0 && config->cam_angle < 180 && config->map[(int)round(raycast->wall_coord_line[0] / WALL_SIZE)][(int)round(raycast->wall_coord_line[1] / WALL_SIZE)] == '0')
		{	
			raycast->wall_coord_line[0] -= WALL_SIZE;
			raycast->wall_coord_line[1] += WALL_SIZE / tan(RAD(180 - config->cam_angle));
		}
		while (config->map[(int)round(raycast->wall_coord_line[0] / WALL_SIZE)][(int)round(raycast->wall_coord_line[1] / WALL_SIZE)] == '0')
		{
			raycast->wall_coord_line[0] += WALL_SIZE;
			raycast->wall_coord_line[1] += WALL_SIZE / tan(RAD(config->cam_angle - 180));
		}
	}
}
