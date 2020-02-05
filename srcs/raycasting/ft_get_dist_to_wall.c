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

double	ft_get_magnitude(t_coord in_coord, t_coord end_coord)
{
	double	magnitude;
	
	magnitude = sqrt((pow(end_coord.x - in_coord.x, 2)) + (pow(end_coord.y - in_coord.y, 2)));
	return (magnitude);
}

double	ft_get_crosscoor_horizontal(t_coord p_coor, char **map, double angle)
{
	double	delta_x;
	double	delta_y;
	t_coord	wall_coor;

	if (angle > 0 && angle < 180)
		delta_y = -WALL_SIZE;
	else
		delta_y = WALL_SIZE;
	delta_x = delta_y * tan(RAD(180 - angle));
	wall_coor.x = p_coor.x + (delta_x / 2);
	wall_coor.y = p_coor.y + (delta_y / 2);
	while (!IS_WALL_SPRITE(map[wall_coor.x / WALL_SIZE][wall_coor.y / WALL_SIZE]))
	{
		wall_coor.x += delta_x;
		wall_coor.y += delta_y;
	}
	return (ft_get_magnitude(p_coor, wall_coor));
}

double	ft_get_crosscoor_vertical(t_coord p_coor, char **map, double angle)
{
	double	delta_x;
	double	delta_y;
	t_coord	wall_coor;

	if (angle > 90 && angle < 270)
		delta_x = WALL_SIZE;
	else
		delta_x = -WALL_SIZE;
	delta_y = -delta_x / tan(RAD(180 - angle));
	wall_coor.x = p_coor.x + (delta_x / 2);
	wall_coor.y = p_coor.y + (delta_y / 2);
	while (!IS_WALL_SPRITE(map[wall_coor.x / WALL_SIZE][wall_coor.y / WALL_SIZE]))
	{
		wall_coor.x += delta_x;
		wall_coor.y += delta_y;
	}
	return (ft_get_magnitude(p_coor, wall_coor));
}

double	ft_get_crosscoor_specangle(t_coord p_coor, char **map, double angle)
{
	t_coord	wall_coor;

	if (angle == 0)
	{
		wall_coor.y = p_coor.y;
		wall_coor.x = p_coor.x - (WALL_SIZE / 2);
		while (!IS_WALL_SPRITE(map[wall_coor.x / WALL_SIZE][wall_coor.y / WALL_SIZE]))
			wall_coor.x -= WALL_SIZE;
	}
	else if (angle == 90)
	{
		wall_coor.y = p_coor.y - (WALL_SIZE / 2);
		wall_coor.x = p_coor.x;
		while (!IS_WALL_SPRITE(map[wall_coor.x / WALL_SIZE][wall_coor.y / WALL_SIZE]))
			wall_coor.y -= WALL_SIZE;
	}
	else if (angle == 180)
	{
		wall_coor.y = p_coor.y;
		wall_coor.x = p_coor.x + (WALL_SIZE / 2);
		while (!IS_WALL_SPRITE(map[wall_coor.x / WALL_SIZE][wall_coor.y / WALL_SIZE]))
			wall_coor.x += WALL_SIZE;
	}
	else if (angle == 270)
	{
		wall_coor.y = p_coor.y + (WALL_SIZE / 2);
		wall_coor.x = p_coor.x;
		while (!IS_WALL_SPRITE(map[wall_coor.x / WALL_SIZE][wall_coor.y / WALL_SIZE]))
			wall_coor.y += WALL_SIZE;
	}
	return (ft_get_magnitude(p_coor, wall_coor));
}

double	ft_get_dist_to_wall(t_coord p_coor, char **map, double angle)
{
	double dist_cross_hor;
	double dist_cross_vert;

	if (SPEC_ANGLE(angle))
		return (ft_get_crosscoor_specangle(p_coor, map, angle));
	dist_cross_hor = ft_get_crosscoor_horizontal(p_coor, map, angle);
	dist_cross_vert = ft_get_crosscoor_vertical(p_coor, map, angle);
	if (dist_cross_hor <= dist_cross_vert)
		return (dist_cross_hor);
	else
		return (dist_cross_vert);
}
