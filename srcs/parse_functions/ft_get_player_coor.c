/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_player_coor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:20:28 by abarot            #+#    #+#             */
/*   Updated: 2020/01/30 13:04:45 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double		ft_get_camangle(char dir)
{
	if (dir == 'N')
		config->cam_angle = 60;
	else if (dir == 'W')
		config->cam_angle = 330;
	else if (dir == 'S')
		config->cam_angle = 240;
	else if (dir == 'E')
		config->cam_angle = 150;
	return (1);
}

void		ft_get_player_coor(t_config *config)
{
	int		col;
	int 	line;
	int		count_player;

	line = 0;
	col = 0;
	count_player = 0;
	while (config->map[line])
	{
		while (config->map[line][col])
		{
			if (ft_check_in_set_char(config->map[line][col], "WESN"))
			{
				if (count_player == 1)
					return ;
				config->map_player_coord[0] = line;
				config->map_player_coord[1] = col;
				config->cam_angle = ft_get_camangle(config->map[line][col]);
				config->map[line][col] = '0';
				count_player++;
			}
			col++;
		}
		col = 0;
		line++;
	}
}
