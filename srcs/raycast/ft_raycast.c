/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 15:32:44 by abarot            #+#    #+#             */
/*   Updated: 2020/04/19 14:24:13 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

t_fcoord	ft_get_delta_hor(t_fcoord delta, double angle)
{
	if (angle > 0 && angle < 180)
	{
		delta.x = -SQUARE_SIZE - 0.000001;
		delta.y = delta.x / tan((M_PI / 180) * (angle));
	}
	else
	{
		delta.x = SQUARE_SIZE + 0.000001;
		delta.y = delta.x / tan((M_PI / 180) * (angle - 180));
	}
	return (delta);
}

t_fcoord	ft_get_delta_vert(t_fcoord delta, double angle)
{
	if (angle > 90 && angle < 270)
	{
		delta.y = SQUARE_SIZE + 0.000001;
		delta.x = delta.y * tan((M_PI / 180) * (angle - 180));
	}
	else
	{
		delta.y = -SQUARE_SIZE - 0.000001;
		delta.x = delta.y * tan((M_PI / 180) * (angle));
	}
	return (delta);
}

double		ft_get_crosscoor(t_raycast *ray, t_fcoord delta, char **map,
							char elt)
{
	t_fcoord	wall_coor;

	wall_coor.x = ray->p_coor.x + (delta.x / 2);
	wall_coor.y = ray->p_coor.y + (delta.y / 2);
	if (ft_outside_map(wall_coor.x, wall_coor.y, map))
		return (ft_get_magnitude(ray->p_coor, wall_coor));
	while (map[(int)(wall_coor.x / SQUARE_SIZE)][(int)(wall_coor.y /
		SQUARE_SIZE)] != elt)
	{
		wall_coor.x += delta.x;
		wall_coor.y += delta.y;
		if (ft_outside_map(wall_coor.x, wall_coor.y, map))
			return (ft_get_magnitude(ray->p_coor, wall_coor));
	}
	return (ft_get_magnitude(ray->p_coor, wall_coor));
}

void		ft_get_smallest_dist(t_raycast *ray, t_fcoord dist_obj,
								double angle)
{
	if (dist_obj.x && (dist_obj.x <= dist_obj.y || !dist_obj.y))
	{
		ray->dist_obj = dist_obj.x;
		(angle < (double)180) ? ray->nesw_path = 'N' : 0;
		(angle > (double)180) ? ray->nesw_path = 'S' : 0;
	}
	else
	{
		ray->dist_obj = dist_obj.y;
		(angle > (double)90 && angle < (double)270) ? ray->nesw_path = 'E' : 0;
		(angle < (double)90 || angle > (double)270) ? ray->nesw_path = 'W' : 0;
	}
}

void		ft_raycast(t_raycast *ray, char **map, double angle, char obj)
{
	t_fcoord	delta;
	t_fcoord	dist_obj;

	delta = ft_get_delta_hor(delta, angle);
	dist_obj.x = ft_get_crosscoor(ray, delta, map, obj);
	delta = ft_get_delta_vert(delta, angle);
	dist_obj.y = ft_get_crosscoor(ray, delta, map, obj);
	ft_get_smallest_dist(ray, dist_obj, angle);
}
