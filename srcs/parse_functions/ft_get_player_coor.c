/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_player_coor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:20:28 by abarot            #+#    #+#             */
/*   Updated: 2020/01/31 13:41:03 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double		ft_get_camangle(char dir)
{
	if (dir == 'N')
		return (60);
	else if (dir == 'W')
		return (330);
	else if (dir == 'S')
		return (240);
	else if (dir == 'E')
		return (150);
	return (0);
}

int		ft_get_player_coor(t_config *config)
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
			if (ft_is_char_in_set(config->map[line][col], "WESN"))
			{
				if (count_player == 1)
					return (MULTIPLAYER_ERROR);
				config->player_coord.x = line;
				config->player_coord.y = col;
				config->cam_angle = ft_get_camangle(config->map[line][col]);
				config->map[line][col] = '0';
				count_player++;
			}
			col++;
		}
		col = 0;
		line++;
	}
	if (count_player == 0)
		return (NO_PLAYER_ERROR);
	return (NO_ERROR);
}
