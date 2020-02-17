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
	config->path_north_texture = 0;
	config->path_west_texture = 0;
	config->path_east_texture = 0;
	config->path_south_texture = 0;
	config->path_sprite = 0;
	if (!(config->map = (char **)ft_calloc(sizeof(char *), 1000000)))
		return (0);
	config->player_coord.x = 0;
	config->player_coord.y = 0;
	config->cam_angle = 0;
	return (1);
}

void	ft_initialyse_ray(t_raycast *ray)
{
	ray->prop_cste = 0;
	ray->p_coor.x = 0;
	ray->p_coor.y = 0;
	ray->dist_cross_hor = 0;
	ray->dist_cross_vert = 0;
	ray->smallest_dist = 0;
	ray->wall_proj = 0;
	ray->nesw_path = 0;
}
