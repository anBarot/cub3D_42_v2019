/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialyse_config.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:51:47 by abarot            #+#    #+#             */
/*   Updated: 2020/01/30 12:46:08 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		ft_initialyse_config(t_config *config)
{
	config->mlx_ptr = 0;
	config->win_ptr = 0;
	if (!(config->resol = (double *)ft_calloc(sizeof(double), 2)))
		return (0);
	config->col_ceil = 0;
	config->col_floor = 0;
	config->path_north = 0;
	config->path_west = 0;
	config->path_east = 0;
	config->path_south = 0;
	config->path_sprite = 0;
	if (!(config->map = (char **)ft_calloc(sizeof(char *), 1000000)))
		return (0);
	if (!(config->player_coord = (char **)ft_calloc(sizeof(int), 2)))
		return (0);
	config->cam_angle = 0;
	return (1);
}
