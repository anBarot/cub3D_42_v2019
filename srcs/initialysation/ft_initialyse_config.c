/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialyse_config.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:51:47 by abarot            #+#    #+#             */
/*   Updated: 2020/04/19 13:26:57 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialize.h"

int		ft_initialyse_config(t_config *config)
{
	config->mlx_ptr = 0;
	config->win_ptr = 0;
	config->parse.resol.x = 0;
	config->parse.resol.y = 0;
	config->parse.col_ceil.r = -1;
	config->parse.col_ceil.b = 0;
	config->parse.col_ceil.g = 0;
	config->parse.col_floor.r = -1;
	config->parse.col_floor.b = 0;
	config->parse.col_floor.g = 0;
	config->parse.path_set.north = 0;
	config->parse.path_set.west = 0;
	config->parse.path_set.east = 0;
	config->parse.path_set.south = 0;
	config->parse.path_set.sprite = 0;
	if (!(config->parse.map_elt.map =
		(char **)ft_calloc(sizeof(char *), 1000000)))
		return (0);
	config->parse.map_elt.p_coord.x = 0;
	config->parse.map_elt.p_coord.y = 0;
	config->parse.map_elt.cam_angle = 0;
	config->escape = 0;
	config->move = 0;
	return (1);
}
