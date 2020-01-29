/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 15:32:44 by abarot            #+#    #+#             */
/*   Updated: 2020/01/27 13:33:14 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	ft_cast_ray(t_config *config)
{
	t_raycast	*raycast;
	double		corrected_dist;
	double		distortion_correction;

	if ((raycast = (t_raycast *)ft_calloc(sizeof(t_raycast), 1)) == 0 || 
		(raycast->cube_player_coord = (double *)ft_calloc(sizeof(double), 2)) == 0)
		return (0);
	raycast->cube_player_coord[0] = (config->map_player_coord[0] * WALL_SIZE) + (WALL_SIZE / 2);
	raycast->cube_player_coord[1] = (config->map_player_coord[1] * WALL_SIZE) + (WALL_SIZE / 2);
	if (config->cam_angle != 0 || config->cam_angle != 90 || config->cam_angle != 180 || config->cam_angle != 270)
	{
		ft_get_crosscoord_line(config, raycast);
		ft_get_crosscoord_col(config, raycast);
		// printf("\n angle : %f\ncoor line : %f,%f\ncoor col : %f,%f\n", config->cam_angle,raycast->wall_coord_line[0], raycast->wall_coord_line[1], raycast->wall_coord_col[0], raycast->wall_coord_col[1]);
		if (ft_magnitude(raycast->cube_player_coord, raycast->wall_coord_col) 
			< ft_magnitude(raycast->cube_player_coord, raycast->wall_coord_line))
			corrected_dist = ft_magnitude(raycast->cube_player_coord, raycast->wall_coord_col);
		else
			corrected_dist = ft_magnitude(raycast->cube_player_coord, raycast->wall_coord_line);
	}
	else 
	{	
		ft_get_configialangle_coord(config, raycast);
		corrected_dist = ft_magnitude(raycast->cube_player_coord, raycast->wall_coord_col);
	}
	distortion_correction = ft_get_distortion_correction(config->cam_angle);
	free(raycast->wall_coord_col);
	free(raycast->wall_coord_line);
	free(raycast);
	return (corrected_dist );//* cos(RAD(distortion_correction)));
}

double	ft_get_distortion_correction(double angle)
{
	if (angle >= 0 && angle <= 90)
		return (90 - angle);
	else if (angle > 90 && angle < 180)
		return (angle - 90);
	else if (angle > 180 && angle <= 270)
		return (angle - 180);
	else if (angle > 270 && angle < 360)
		return (360 - angle);
	return (0);
}

void	ft_get_crosscoord_line(t_config *config, t_raycast *raycast)
{
	raycast->wall_coord_line = (double *)ft_calloc(sizeof(double), 2);
	raycast->wall_coord_line[0] = raycast->cube_player_coord[0];
	raycast->wall_coord_line[1] = raycast->cube_player_coord[1];
	if (config->cam_angle > 0 && config->cam_angle < 180)
	{	
		raycast->wall_coord_line[0] -= (WALL_SIZE / 2);
		raycast->wall_coord_line[1] += (WALL_SIZE / 2) / tan(RAD(180 - config->cam_angle));
	}
	else
	{
		raycast->wall_coord_line[0] += (WALL_SIZE / 2);
		raycast->wall_coord_line[1] += (WALL_SIZE / 2) / tan(RAD(config->cam_angle - 180));
	}
	while (config->map[(int)round(raycast->wall_coord_line[0] / WALL_SIZE)][(int)round(raycast->wall_coord_line[1] / WALL_SIZE)] == '0')
	{
		while (config->cam_angle > 0 && config->cam_angle < 180 && config->map[(int)round(raycast->wall_coord_line[0] / WALL_SIZE)][(int)round(raycast->wall_coord_line[1] / WALL_SIZE)] == '0')
		{	
			raycast->wall_coord_line[0] -= WALL_SIZE;
			raycast->wall_coord_line[1] += WALL_SIZE / tan(RAD(180 - config->cam_angle));
		}
		while (config->map[(int)round(raycast->wall_coord_line[0] / WALL_SIZE)][(int)round(raycast->wall_coord_line[1] / WALL_SIZE)] == '0')
		{
			raycast->wall_coord_line[0] += WALL_SIZE;
			raycast->wall_coord_line[1] += WALL_SIZE / tan(RAD(config->cam_angle - 180));
		}
	}
}

void	ft_get_crosscoord_col(t_config *config, t_raycast *raycast)
{
	raycast->wall_coord_col = (double *)ft_calloc(sizeof(double), 2);
	raycast->wall_coord_col[0] = raycast->cube_player_coord[0];
	raycast->wall_coord_col[1] = raycast->cube_player_coord[1];
	if (config->cam_angle > 270 || config->cam_angle < 90)
	{	
		raycast->wall_coord_col[0] += ((WALL_SIZE / 2) * tan(RAD(360 - config->cam_angle)));
		raycast->wall_coord_col[1] -= (WALL_SIZE / 2);
	}
	else
	{
		raycast->wall_coord_col[0] -= (WALL_SIZE / 2) * tan(RAD(config->cam_angle - 180));
		raycast->wall_coord_col[1] += (WALL_SIZE / 2);
	}
	while (raycast->wall_coord_line[0] > WALL_SIZE && raycast->wall_coord_line[1] > WALL_SIZE && raycast->wall_coord_line[0] < (WALL_SIZE * ft_strlen(config->map[0] + 1))
		&& config->map[(int)raycast->wall_coord_col[0] / WALL_SIZE][(int)raycast->wall_coord_col[1] / WALL_SIZE] == '0')
	{

		if (config->cam_angle > 270 || config->cam_angle < 90)
		{
			raycast->wall_coord_col[0] += (WALL_SIZE * tan(RAD(360 - config->cam_angle)));
			raycast->wall_coord_col[1] -= WALL_SIZE;
		}
		else
		{
			raycast->wall_coord_col[0] += (WALL_SIZE * tan(RAD(config->cam_angle - 180)));
			raycast->wall_coord_col[1] += WALL_SIZE;
		}
	}
}

void	ft_get_configialangle_coord(t_config *config, t_raycast *raycast)
{
	raycast->wall_coord_col = (double *)ft_calloc(sizeof(double), 2);
	raycast->wall_coord_col[0] = raycast->cube_player_coord[0];
	raycast->wall_coord_col[1] = raycast->cube_player_coord[1];
	if (config->cam_angle == 0)
	{
		raycast->wall_coord_col[1] -= (WALL_SIZE / 2);
		while (raycast->wall_coord_line[1] > WALL_SIZE && 
		config->map[(int)round(raycast->wall_coord_col[0] / WALL_SIZE)][(int)round(raycast->wall_coord_col[1] / WALL_SIZE)] == '0')
			raycast->wall_coord_col[1] -= WALL_SIZE;
	}
	else if (config->cam_angle == 180)
	{
		raycast->wall_coord_col[1] += (WALL_SIZE / 2);
		while (raycast->wall_coord_line[1] < (WALL_SIZE * (ft_strlen(config->map[0]) + 1)) && 
		config->map[(int)round(raycast->wall_coord_col[0] / WALL_SIZE)][(int)round(raycast->wall_coord_col[1] / WALL_SIZE)] == '0')
			raycast->wall_coord_col[1] += WALL_SIZE;
	}
	else if (config->cam_angle == 90)
	{
		raycast->wall_coord_col[0] -= (WALL_SIZE / 2);
		while (raycast->wall_coord_line[0] > WALL_SIZE &&
		config->map[(int)round(raycast->wall_coord_col[0] / WALL_SIZE)][(int)round(raycast->wall_coord_col[1] / WALL_SIZE)] == '0')
			raycast->wall_coord_col[0] -= WALL_SIZE;
	}
	else if (config->cam_angle == 180)
	{
		raycast->wall_coord_col[0] += (WALL_SIZE / 2);
		while (raycast->wall_coord_line[0] < (WALL_SIZE * (ft_strlen(config->map[0]) + 1)) &&
		config->map[(int)round(raycast->wall_coord_col[0] / WALL_SIZE)][(int)round(raycast->wall_coord_col[1] / WALL_SIZE)] == '0')
			raycast->wall_coord_col[0] += WALL_SIZE;
	}
}

double	ft_magnitude(double *in_coord, double *fin_coord)
{
	double	magnitude;
	
	magnitude = sqrt((pow(fin_coord[0] - in_coord[0], 2)) + (pow(fin_coord[1] - in_coord[1], 2)));
	return (magnitude);
}
