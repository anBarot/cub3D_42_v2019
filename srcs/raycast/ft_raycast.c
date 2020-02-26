/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_crosscoor_horizontal.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 15:32:44 by abarot            #+#    #+#             */
/*   Updated: 2020/01/30 12:19:14 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_initialyse_ray(t_raycast *ray)
{
	ray->prop_cste = 0;
	ray->p_coor.x = 0;
	ray->p_coor.y = 0;
	ray->dist_obj = 0;
	ray->obj_proj = 0;
	ray->nesw_path = 0;
}

int	ft_count_line(char **map)
{
	int line;

	line = 0;
	while (map[line])
		line++;
	return (line);
}

int	ft_outside_map(double x, double y, char **map)
{
	if ((int)(x / WALL_SIZE) > (ft_count_line(map) - 1) 
		|| (int)(y / WALL_SIZE) > ((int)ft_strlen(map[0]) - 1)
		|| (int)(x / WALL_SIZE) < 0
		|| (int)(y / WALL_SIZE) < 0)
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

t_fcoord	ft_get_delta_hor(t_fcoord delta, double angle)
{
	if (angle > 0 && angle < 180)
	{	
		delta.x = -WALL_SIZE  - 0.0001;
		delta.y = delta.x / tan(RAD(angle));
	}
	else
	{	
		delta.x = WALL_SIZE + 0.0001;
		delta.y = delta.x / tan(RAD(angle - 180));
	}
	return (delta);
}

t_fcoord	ft_get_delta_vert(t_fcoord delta, double angle)
{
	if (angle > 90 && angle < 270)
	{	
		delta.y = WALL_SIZE + 0.0001;
		delta.x = delta.y * tan(RAD(angle - 180));
	}
	else
	{	
		delta.y = -WALL_SIZE - 0.0001;
		delta.x = delta.y * tan(RAD(angle));
	}
	return (delta);
}

double	ft_get_crosscoor(t_raycast *ray, t_fcoord delta, char **map, char c)
{
	t_fcoord	wall_coor;

	wall_coor.x = ray->p_coor.x + (delta.x / 2);
	wall_coor.y = ray->p_coor.y + (delta.y / 2);
	if (ft_outside_map(wall_coor.x, wall_coor.y, map))
		return (0);
	while (map[(int)(wall_coor.x / WALL_SIZE)][(int)(wall_coor.y / WALL_SIZE)] != c)
	{
		wall_coor.x += delta.x;
		wall_coor.y += delta.y;
		if (ft_outside_map(wall_coor.x, wall_coor.y, map))
			return (0);
	}
	return (ft_get_magnitude(ray->p_coor, wall_coor));
}

void	ft_get_smallest_dist(t_raycast * ray, t_fcoord dist_obj, double angle)
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

void	ft_get_dist_to_obj(t_raycast *ray, char **map, double angle, char obj)
{
	t_fcoord	delta;
	t_fcoord	dist_obj;

	if (fabs(angle - 180) > 1 || fabs(angle - 0) > 1 || fabs(angle - 360) > 1) 
	{	
		delta = ft_get_delta_hor(delta, angle);
		dist_obj.x = ft_get_crosscoor(ray, delta, map, obj);
	}
	if (fabs(angle - 90) > 1 || fabs(angle - 270) > 1)
	{
		delta = ft_get_delta_vert(delta, angle);
		dist_obj.y = ft_get_crosscoor(ray, delta, map, obj);
	}
	ft_get_smallest_dist(ray, dist_obj, angle);
}

void	ft_raycast(t_config *config, t_raycast *ray, double angle, char obj)
{
	ray->p_coor.x = (config->player_coord.x * WALL_SIZE) + (WALL_SIZE / 2);
	ray->p_coor.y = (config->player_coord.y * WALL_SIZE) + (WALL_SIZE / 2);
	ft_get_dist_to_obj(ray, config->map, angle, obj);
	ray->prop_cste = ((WALL_SIZE / 2) * ((config->resol.x /2) / tan(RAD(FOV / 2))));
	ray->obj_proj = (ray->prop_cste / ray->dist_obj);
	if (ray->obj_proj > config->resol.y)
		ray->obj_proj = config->resol.y;
}