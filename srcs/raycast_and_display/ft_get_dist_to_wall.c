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

double	ft_get_crosscoor_horizontal(t_raycast *ray, char **map, double angle)
{
	double		delta_x;
	double		delta_y;
	t_fcoord	wall_coor;

	if (angle > 0 && angle < 180)
	{	
		delta_x = -WALL_SIZE  - 0.001;
		delta_y = delta_x / tan(RAD(angle));
	}
	else
	{	
		delta_x = WALL_SIZE + 0.001;
		delta_y = delta_x / tan(RAD(angle - 180));
	}
	wall_coor.x = ray->p_coor.x + (delta_x / 2);
	wall_coor.y = ray->p_coor.y + (delta_y / 2);
	if (ft_outside_map(wall_coor.x, wall_coor.y, map))
		return (0);
	while (map[((int)(wall_coor.x / WALL_SIZE))][((int)(wall_coor.y / WALL_SIZE))] == '0')
	{
		wall_coor.x += delta_x;
		wall_coor.y += delta_y;
		if (ft_outside_map(wall_coor.x, wall_coor.y, map))
			return (0);
	}
	ray->value_bumped = map[((int)wall_coor.x / WALL_SIZE)][((int)wall_coor.y / WALL_SIZE)] - 48;
	return (ft_get_magnitude(ray->p_coor, wall_coor));
}

double	ft_get_crosscoor_vertical(t_raycast *ray, char **map, double angle)
{
	double		delta_x;
	double		delta_y;
	t_fcoord	wall_coor;

	if (angle > 90 && angle < 270)
	{	
		delta_y = WALL_SIZE + 0.001;
		delta_x = delta_y * tan(RAD(angle - 180));
	}
	else
	{	
		delta_y = -WALL_SIZE - 0.001;
		delta_x = delta_y * tan(RAD(angle));
	}
	wall_coor.x = ray->p_coor.x + (delta_x / 2);
	wall_coor.y = ray->p_coor.y + (delta_y / 2);
	if (ft_outside_map(wall_coor.x, wall_coor.y, map))
		return (0);
	while (map[(int)(wall_coor.x / WALL_SIZE)][(int)(wall_coor.y / WALL_SIZE)] == '0')
	{
		wall_coor.x += delta_x;
		wall_coor.y += delta_y;
		if (ft_outside_map(wall_coor.x, wall_coor.y, map))
			return (0);
	}
	ray->value_bumped = map[((int)wall_coor.x / WALL_SIZE)][((int)wall_coor.y / WALL_SIZE)] - 48;
	return (ft_get_magnitude(ray->p_coor, wall_coor));
}

void	ft_get_dist_to_wall(t_raycast *ray, char **map, double angle)
{
	(fabs(angle - 180) > 1 || fabs(angle - 0) > 1 || fabs(angle - 360) > 1) ?
		ray->dist_cross_hor = ft_get_crosscoor_horizontal(ray, map, angle) : 0;
	(fabs(angle - 90) > 1 || fabs(angle - 270) > 1) ?
		ray->dist_cross_vert = ft_get_crosscoor_vertical(ray, map, angle) : 0;
	if (ray->dist_cross_hor && (ray->dist_cross_hor <= ray->dist_cross_vert || !ray->dist_cross_vert))
	{	
		ray->smallest_dist = ray->dist_cross_hor;
		(angle < (double)180) ? ray->nesw_path = 'N' : 0;
		(angle > (double)180) ? ray->nesw_path = 'S' : 0;
	}
	else
	{
		ray->smallest_dist = ray->dist_cross_vert;
		(angle > (double)90 && angle < (double)270) ? ray->nesw_path = 'E' : 0;
		(angle < (double)90 || angle > (double)270) ? ray->nesw_path = 'W' : 0;
	}
}
