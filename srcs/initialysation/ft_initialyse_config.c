/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialyse_config.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:51:47 by abarot            #+#    #+#             */
/*   Updated: 2020/01/31 13:42:03 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		ft_initialyse_config(t_config *config)
{
	config->mlx_ptr = 0;
	config->win_ptr = 0;
	config->resol.x = 0;
	config->resol.y = 0;
	config->path_north = 0;
	config->path_west = 0;
	config->path_east = 0;
	config->path_south = 0;
	config->path_sprite = 0;
	if (!(config->map = (char **)ft_calloc(sizeof(char *), 1000000)))
		return (0);
	config->player_coord.x = 0;
	config->player_coord.y = 0;
	config->cam_angle = 0;
	return (1);
}
