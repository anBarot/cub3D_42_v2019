/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_crosscoor_vertical.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 15:32:44 by abarot            #+#    #+#             */
/*   Updated: 2020/01/30 12:19:42 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_get_crosscoord_vertical(t_config *config, t_raycast *raycast)
{
	raycast->wall_coord_col = (double *)ft_calloc(sizeof(double), 2);
	raycast->wall_coord_col[0] = raycast->cube_player_coord[0];
	raycast->wall_coord_col[1] = raycast->cube_player_coord[1];
	if (config->cam_angle > 270 || config->cam_angle < 90)
	{	
		raycast->wall_coord_col[0] += ((WALL_SIZE / 2) * tan(RAD(360 - config->cam_angle)));
		raycast->wall_coord_col[1] -= (WALL_SIZE / 2);
	}
	else
	{
		raycast->wall_coord_col[0] -= (WALL_SIZE / 2) * tan(RAD(config->cam_angle - 180));
		raycast->wall_coord_col[1] += (WALL_SIZE / 2);
	}
	while (raycast->wall_coord_line[0] > WALL_SIZE && raycast->wall_coord_line[1] > WALL_SIZE && raycast->wall_coord_line[0] < (WALL_SIZE * ft_strlen(config->map[0] + 1))
		&& config->map[(int)raycast->wall_coord_col[0] / WALL_SIZE][(int)raycast->wall_coord_col[1] / WALL_SIZE] == '0')
	{

		if (config->cam_angle > 270 || config->cam_angle < 90)
		{
			raycast->wall_coord_col[0] += (WALL_SIZE * tan(RAD(360 - config->cam_angle)));
			raycast->wall_coord_col[1] -= WALL_SIZE;
		}
		else
		{
			raycast->wall_coord_col[0] += (WALL_SIZE * tan(RAD(config->cam_angle - 180)));
			raycast->wall_coord_col[1] += WALL_SIZE;
		}
	}
}
