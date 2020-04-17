/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 17:05:10 by abarot            #+#    #+#             */
/*   Updated: 2020/04/17 17:04:20 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	ft_initialyse_ray(t_raycast *ray)
{
	ray->p_coor.x = 0;
	ray->p_coor.y = 0;
	ray->dist_obj = 0;
	ray->nesw_path = 0;
}

int		ft_outside_map(double x, double y, char **map)
{
	if ((int)(x / SQUARE_SIZE) > (ft_count_line(map) - 1)
		|| (int)(y / SQUARE_SIZE) > ((int)ft_strlen(map[0]) - 1)
		|| (int)(y / SQUARE_SIZE) > ((int)ft_strlen(map[0]) + 1)
		|| (int)(x / SQUARE_SIZE) < 0
		|| (int)(y / SQUARE_SIZE) < 0
		|| ft_is_empty(map[(int)(x / SQUARE_SIZE)][(int)(y / SQUARE_SIZE)]))
		return (1);
	return (0);
}

double	ft_get_magnitude(t_fcoord in_coord, t_fcoord end_coord)
{
	double	magnitude;

	magnitude = sqrt((pow(end_coord.x - in_coord.x, 2)) +
	(pow(end_coord.y - in_coord.y, 2)));
	return (magnitude);
}
