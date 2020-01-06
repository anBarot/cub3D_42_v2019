#include "cub3D.h"

double	ft_cast_ray(t_spec *spec)
{
	// printf("\n-----enterring cast_ray-----\n");
	t_raycast	*raycast;
	double		corrected_dist;

	raycast = (t_raycast *)ft_calloc(sizeof(t_raycast), 1);
	raycast->cube_player_coord = (double *)ft_calloc(sizeof(double), 2);
	raycast->cube_player_coord[0] = (spec->map_player_coord[0] * WALL_SIZE) + (WALL_SIZE / 2);
	raycast->cube_player_coord[1] = (spec->map_player_coord[1] * WALL_SIZE) + (WALL_SIZE / 2);
	// printf("\ncoor : %f,%f\n", raycast->cube_player_coord[0], raycast->cube_player_coord[1]);
	if (spec->cam_angle != 0 || spec->cam_angle != 90 || spec->cam_angle != 180 || spec->cam_angle != 270)
	{
		ft_get_crosscoord_line(spec, raycast);
		ft_get_crosscoord_col(spec, raycast);
	// printf("\nline prox : %f,%f\ncol prox : %f,%f\n", raycast->wall_coord_line[0], raycast->wall_coord_line[1], raycast->wall_coord_col[0], raycast->wall_coord_col[1]);
		if (ft_magnitude(raycast->cube_player_coord, raycast->wall_coord_col) 
			< ft_magnitude(raycast->cube_player_coord, raycast->wall_coord_line))
			corrected_dist = ft_magnitude(raycast->cube_player_coord, raycast->wall_coord_col);
		else
			corrected_dist = ft_magnitude(raycast->cube_player_coord, raycast->wall_coord_line);
		return (corrected_dist);
	}
	else 
		ft_get_specialangle_coord(spec, raycast);
	corrected_dist = ft_magnitude(raycast->cube_player_coord, raycast->wall_coord_col);
	free(raycast->wall_coord_col);
	free(raycast->wall_coord_line);
	free(raycast);
	// printf("\n-----quitting cast_ray-----\n");
	return (corrected_dist);
}

void	ft_get_crosscoord_line(t_spec *spec, t_raycast *raycast)
{
	raycast->wall_coord_line = (double *)ft_calloc(sizeof(double), 2);
	raycast->wall_coord_line[0] = raycast->cube_player_coord[0];
	raycast->wall_coord_line[1] = raycast->cube_player_coord[1];
	if (spec->cam_angle > 0 && spec->cam_angle < 180)
	{	
		raycast->wall_coord_line[0] += -(WALL_SIZE / 2);
		raycast->wall_coord_line[1] += ((WALL_SIZE / 2) / tan(180 - spec->cam_angle));
	}
	else
	{
		raycast->wall_coord_line[0] += (WALL_SIZE / 2);
		raycast->wall_coord_line[1] += ((WALL_SIZE / 2) / tan(spec->cam_angle - 180));
	}
	while (spec->map[(int)raycast->wall_coord_line[0] / WALL_SIZE][(int)raycast->wall_coord_line[1] / WALL_SIZE] == '0' &&
			(raycast->wall_coord_line[0] > 0 && raycast->wall_coord_line[1] > 0))
	{
		if (spec->cam_angle >= 0 && spec->cam_angle < 180)
		{	
			raycast->wall_coord_line[0] += -WALL_SIZE;
			raycast->wall_coord_line[1] += WALL_SIZE / tan(180 - spec->cam_angle);
		}
		else
		{
			raycast->wall_coord_line[0] += WALL_SIZE;
			raycast->wall_coord_line[1] += WALL_SIZE / tan(spec->cam_angle - 180);
		}
	}
}

void	ft_get_crosscoord_col(t_spec *spec, t_raycast *raycast)
{
	raycast->wall_coord_col = (double *)ft_calloc(sizeof(double), 2);
	raycast->wall_coord_col[0] = raycast->cube_player_coord[0];
	raycast->wall_coord_col[1] = raycast->cube_player_coord[1];
	if (spec->cam_angle > 90 && spec->cam_angle < 270)
	{	
		raycast->wall_coord_col[0] += (WALL_SIZE / 2) * tan(180 - spec->cam_angle);
		raycast->wall_coord_col[1] += (WALL_SIZE / 2);
	}
	else
	{
		raycast->wall_coord_col[0] += (WALL_SIZE / 2) * tan(spec->cam_angle - 180);
		raycast->wall_coord_col[1] += -(WALL_SIZE / 2);
	}
	while (spec->map[(int)raycast->wall_coord_col[0] / WALL_SIZE][(int)raycast->wall_coord_col[1] / WALL_SIZE] == '0' && 
			(raycast->wall_coord_col[0] > 0 && raycast->wall_coord_col[1] > 0))
	{
		if (spec->cam_angle > 90 && spec->cam_angle < 270)
		{	
			raycast->wall_coord_col[0] += WALL_SIZE * tan(180 - spec->cam_angle);
			raycast->wall_coord_col[1] += WALL_SIZE;
		}
		else 
		{
			raycast->wall_coord_col[0] += WALL_SIZE * tan(spec->cam_angle - 180);
			raycast->wall_coord_col[1] += -WALL_SIZE;
		}
	}
}

void	ft_get_specialangle_coord(t_spec *spec, t_raycast *raycast)
{
	// printf("\n----spec angle----\n");
	raycast->wall_coord_col = (double *)ft_calloc(sizeof(double), 2);
	raycast->wall_coord_col[0] = raycast->cube_player_coord[0];
	raycast->wall_coord_col[1] = raycast->cube_player_coord[1];
	if (spec->cam_angle == 0)
	{
		raycast->wall_coord_col[1] += -(WALL_SIZE / 2);
		while (spec->map[(int)raycast->wall_coord_col[0] / WALL_SIZE][(int)raycast->wall_coord_col[1] / WALL_SIZE] == '0')
			raycast->wall_coord_col[1] += -WALL_SIZE;
	}
	else if (spec->cam_angle == 180)
	{
		raycast->wall_coord_col[1] += (WALL_SIZE / 2);
		while (spec->map[(int)raycast->wall_coord_col[0] / WALL_SIZE][(int)raycast->wall_coord_col[1] / WALL_SIZE] == '0')
			raycast->wall_coord_col[1] += WALL_SIZE;
	}
	else if (spec->cam_angle == 90)
	{
		raycast->wall_coord_col[0] += -(WALL_SIZE / 2);
		while (spec->map[(int)raycast->wall_coord_col[0] / WALL_SIZE][(int)raycast->wall_coord_col[1] / WALL_SIZE] == '0')
			raycast->wall_coord_col[0] += -WALL_SIZE;
	}
	else if (spec->cam_angle == 180)
	{
		raycast->wall_coord_col[0] += (WALL_SIZE / 2);
		while (spec->map[(int)raycast->wall_coord_col[0] / WALL_SIZE][(int)raycast->wall_coord_col[1] / WALL_SIZE] == '0')
			raycast->wall_coord_col[0] += WALL_SIZE;
	}
}

double	ft_magnitude(double *in_coord, double *fin_coord)
{
	double	magnitude;
	
	magnitude = sqrt(pow(in_coord[0] - fin_coord[0], 2) + pow(in_coord[1] - fin_coord[1], 2));
	return (magnitude);
}
