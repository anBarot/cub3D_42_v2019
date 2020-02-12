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
	if (round(x / WALL_SIZE) > (ft_count_line(map) - 1) 
		|| round(y / WALL_SIZE) > (ft_strlen(map[0]) - 1)
		|| round(x / WALL_SIZE) < 0 
		|| round(y / WALL_SIZE) < 0)
		return (1);
	return (0);
}

double	ft_get_magnitude(t_fcoord in_coord, t_fcoord end_coord)
{
	double	magnitude;
	
	magnitude = sqrt((pow(end_coord.x - in_coord.x, 2)) + (pow(end_coord.y - in_coord.y, 2)));
	return (magnitude);
}

double	ft_get_crosscoor_horizontal(t_fcoord p_coor, char **map, double angle)
{
	double		delta_x;
	double		delta_y;
	t_fcoord	wall_coor;

	printf("\n----cross coor horizontal----\n");
	if (angle > 0 && angle < 180)
	{	
		delta_x = -WALL_SIZE;
		delta_y = delta_x / tan(RAD(angle));
	}
	else
	{
		delta_x = WALL_SIZE;
		delta_y = delta_x / tan(RAD(angle - 180));
	}
	printf("\nangle : %f\n",angle);
	printf("\ndeltas : %f, %f\n", delta_x, delta_y);
	wall_coor.x = p_coor.x + (delta_x / 2);
	wall_coor.y = p_coor.y + (delta_y / 2);
	if (ft_outside_map(wall_coor.x, wall_coor.y, map))
		return (0);
	while (!IS_WALL_SPRITE(map[(int)round(wall_coor.x / WALL_SIZE)][(int)round(wall_coor.y / WALL_SIZE)]))
	{
		wall_coor.x += delta_x;
		wall_coor.y += delta_y;
		if (ft_outside_map(wall_coor.x, wall_coor.y, map))
			return (0);
	}
	return (ft_get_magnitude(p_coor, wall_coor));
}

double	ft_get_crosscoor_vertical(t_fcoord p_coor, char **map, double angle)
{
	double		delta_x;
	double		delta_y;
	t_fcoord	wall_coor;

	printf("\n----cross coor vertical----\n");
	if (angle > 90 && angle < 270)
	{	
		delta_y = WALL_SIZE;
		delta_x = delta_y * tan(RAD(angle));
	}
	else
	{	
		delta_y = -WALL_SIZE;
		delta_x = delta_y * tan(RAD(angle - 180));
	}
	printf("\nangle : %f\n",angle);
	printf("\ndeltas : %f, %f\n", delta_x, delta_y);
	wall_coor.x = p_coor.x + (delta_x / 2);
	wall_coor.y = p_coor.y + (delta_y / 2);
	if (ft_outside_map(wall_coor.x, wall_coor.y, map))
		return (0);
	while (!IS_WALL_SPRITE(map[(int)round(wall_coor.x / WALL_SIZE)][(int)round(wall_coor.y / WALL_SIZE)]))
	{
		printf("\nwall coor : %f, %f\n",wall_coor.x, wall_coor.y);
		wall_coor.x += delta_x;
		wall_coor.y += delta_y;
		if (ft_outside_map(wall_coor.x, wall_coor.y, map))
			return (0);
	}
	return (ft_get_magnitude(p_coor, wall_coor));
}

double	ft_get_crosscoor_specangle(t_fcoord p_coor, char **map, double angle)
{
	t_fcoord	wall_coor;

	printf("\n----spec angle----\n");
	if (angle == 0 || angle == 360)
	{
		wall_coor.y = p_coor.y - (WALL_SIZE / 2);
		wall_coor.x = p_coor.x;
		while (!IS_WALL_SPRITE(map[(int)(wall_coor.x / WALL_SIZE)][(int)(wall_coor.y / WALL_SIZE)]) && 
		(wall_coor.x / WALL_SIZE) > 0 && (wall_coor.y / WALL_SIZE) > 0)
			wall_coor.y -= 1;
	}
	else if (angle == 90)
	{
		wall_coor.y = p_coor.y;
		wall_coor.x = p_coor.x - (WALL_SIZE / 2);
		while (!IS_WALL_SPRITE(map[(int)(wall_coor.x / WALL_SIZE)][(int)(wall_coor.y / WALL_SIZE)]) && 
		(wall_coor.x / WALL_SIZE) > 0 && (wall_coor.y / WALL_SIZE) > 0)
			wall_coor.x -= 1;
	}
	else if (angle == 180)
	{
		wall_coor.y = p_coor.y + (WALL_SIZE / 2);
		wall_coor.x = p_coor.x;
		while (!IS_WALL_SPRITE(map[(int)round(wall_coor.x / WALL_SIZE)][(int)round(wall_coor.y / WALL_SIZE)]) &&
		(wall_coor.x / WALL_SIZE) > 0 && (wall_coor.y / WALL_SIZE) > 0)
			wall_coor.y += 1;
	}
	else if (angle == (double)270)
	{
		wall_coor.y = p_coor.y;
		wall_coor.x = p_coor.x + (WALL_SIZE / 2);
		while (!IS_WALL_SPRITE(map[(int)round(wall_coor.x / WALL_SIZE)][(int)round(wall_coor.y / WALL_SIZE)]) &&
		(wall_coor.x / WALL_SIZE) > 0 && (wall_coor.y / WALL_SIZE) > 0)
			wall_coor.x += 1;
	}
	return (ft_get_magnitude(p_coor, wall_coor));
}

double	ft_get_dist_to_wall(t_fcoord p_coor, char **map, double angle)
{
	double dist_cross_hor;
	double dist_cross_vert;

	printf("\nangle int : %d\nangle double : %f\nvalue fabs : %f\n", (int)angle, angle, fabs(angle - (double)0));
	// if (fabs(angle - (double)0) < 2 || fabs(angle - (double)360) < 2 || 
	// fabs(angle - (double)90) < 2  || fabs(angle - (double)180) < 2 || fabs(angle - (double)270) < 2)
	// 	return (ft_get_crosscoor_specangle(p_coor, map, angle));
	dist_cross_hor = ft_get_crosscoor_horizontal(p_coor, map, angle);
	dist_cross_vert = ft_get_crosscoor_vertical(p_coor, map, angle);
	printf("\nangle : %f\ndist hor : %f\ndist vert : %f\n", angle,dist_cross_hor, dist_cross_vert);
	if (dist_cross_hor && (dist_cross_hor <= dist_cross_vert || !dist_cross_vert))
		return (dist_cross_hor);
	else
		return (dist_cross_vert);
}
