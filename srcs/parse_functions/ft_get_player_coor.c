/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_player_coor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:20:28 by abarot            #+#    #+#             */
/*   Updated: 2020/01/27 14:59:51 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		ft_get_camangle(t_config *config)
{
	if (config->dir == 'N')
		config->cam_angle = 60;
	else if (config->dir == 'W')
		config->cam_angle = 330;
	else if (config->dir == 'S')
		config->cam_angle = 240;
	else if (config->dir == 'E')
		config->cam_angle = 150;
	else
		return (0);
	return (1);
}

int		ft_get_player_coor(t_config *config)
{
	int	col;
	int line;

	if (!(config->map_player_coord = (int *)ft_calloc(2, sizeof(int))))
		return (0);
	line = 0;
	col = 0;
	while (config->map[line])
	{
		while (config->map[line][col])
		{
			if (ft_check_in_set_char(config->map[line][col], "WESN"))
			{
				config->map_player_coord[0] = line;
				config->map_player_coord[1] = col;
				config->dir = config->map[line][col];
				config->map[line][col] = '0';
				return (1);
			}
			col++;
		}
		col = 0;
		line++;
	}
	return (0);
}
