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

int		ft_get_camangle(t_spec *spec)
{
	if (spec->dir == 'N')
		spec->cam_angle = 60;
	else if (spec->dir == 'W')
		spec->cam_angle = 330;
	else if (spec->dir == 'S')
		spec->cam_angle = 240;
	else if (spec->dir == 'E')
		spec->cam_angle = 150;
	else
		return (0);
	return (1);
}

int		ft_get_player_coor(t_spec *spec)
{
	int	col;
	int line;

	if (!(spec->map_player_coord = (int *)ft_calloc(2, sizeof(int))))
		return (0);
	line = 0;
	col = 0;
	while (spec->map[line])
	{
		while (spec->map[line][col])
		{
			if (ft_check_in_set_char(spec->map[line][col], "WESN"))
			{
				spec->map_player_coord[0] = line;
				spec->map_player_coord[1] = col;
				spec->dir = spec->map[line][col];
				spec->map[line][col] = '0';
				return (1);
			}
			col++;
		}
		col = 0;
		line++;
	}
	return (0);
}
