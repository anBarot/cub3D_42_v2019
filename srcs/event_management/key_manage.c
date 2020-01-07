/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:05:01 by abarot            #+#    #+#             */
/*   Updated: 2020/01/07 17:03:30 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_key_pressed(int keycode, t_spec *spec)
{
	if (UPKEY(keycode))
	{
		printf("\nmove forward\n");
		ft_move_forward(spec);
	}
	else if (DOWNKEY(keycode))
	{
		printf("\nmove backward\n");
		ft_move_backward(spec);
	}
	else if (LEFTKEY(keycode))
	{	
		printf("\nturn left\n");
		ft_turn_left(spec);
	}
	else if (RIGHTKEY(keycode))
	{	
		printf("\nturn rigth\n");
		ft_turn_right(spec);
	}
	else if (ESCAPEKEY(keycode))
	{	
		printf("\nescape programm\n");
		mlx_destroy_window(spec->mlx_ptr, spec->win_ptr);
		return (0);
	}
	printf("\ncoor playeur : \nline : %d\ncol : %d\ndir : %c\nangle : %.2f\n", spec->map_player_coord[0], spec->map_player_coord[1], spec->dir, spec->cam_angle);
	return (1);
}

void	ft_move_forward(t_spec *spec)
{
	if (spec->dir == 'N' && spec->map[spec->map_player_coord[0] - 1][spec->map_player_coord[1]] != '1')
		spec->map_player_coord[0] -= 1;
	else if (spec->dir == 'W' && spec->map[spec->map_player_coord[0]][spec->map_player_coord[1] - 1] != '1')
		spec->map_player_coord[1] -= 1;
	else if (spec->dir == 'S' && spec->map[spec->map_player_coord[0] + 1][spec->map_player_coord[1]] != '1')
		spec->map_player_coord[0] += 1;
	else if	(spec->dir == 'E' && spec->map[spec->map_player_coord[0]][spec->map_player_coord[1] + 1] != '1')
		spec->map_player_coord[1] += 1;
	ft_display_screen(spec);
}

void	ft_move_backward(t_spec *spec)
{
	if (spec->dir == 'N' && spec->map[spec->map_player_coord[0] + 1][spec->map_player_coord[1]] != '1')
		spec->map_player_coord[0] += 1;
	else if (spec->dir == 'W' && spec->map[spec->map_player_coord[0]][spec->map_player_coord[1] + 1] != '1')
		spec->map_player_coord[1] += 1;
	else if (spec->dir == 'S' && spec->map[spec->map_player_coord[0] - 1][spec->map_player_coord[1]] != '1')
		spec->map_player_coord[0] -= 1;
	else if	(spec->dir == 'E' && spec->map[spec->map_player_coord[0]][spec->map_player_coord[1] - 1] != '1')
		spec->map_player_coord[1] -= 1;
	ft_display_screen(spec);
}

void	ft_turn_left(t_spec *spec)
{
	if (spec->cam_angle == 0)
		spec->cam_angle = 360;
	spec->cam_angle -= 20;
	if (spec->cam_angle == 0)
		spec->cam_angle = 360;
	spec->cam_angle -= 10;
	if (spec->cam_angle >= 135 && spec->cam_angle < 225)
		spec->dir = 'E';
	if (spec->cam_angle >= 45 && spec->cam_angle < 135)
		spec->dir = 'N';
	if ((spec->cam_angle >= 315 && spec->cam_angle <= 360)
		|| (spec->cam_angle >= 0 && spec->cam_angle < 45))
		spec->dir = 'W';
	if (spec->cam_angle >= 225 && spec->cam_angle < 315)
		spec->dir = 'S';
	ft_display_screen(spec);
}

void	ft_turn_right(t_spec *spec)
{
	if (spec->cam_angle == 360)
		spec->cam_angle = 0;
	spec->cam_angle += 20;
	if (spec->cam_angle >= 135 && spec->cam_angle < 225)
		spec->dir = 'E';
	if (spec->cam_angle >= 45 && spec->cam_angle < 135)
		spec->dir = 'N';
	if ((spec->cam_angle >= 315 && spec->cam_angle <= 360)
		|| (spec->cam_angle >= 0 && spec->cam_angle < 45))
		spec->dir = 'W';
	if (spec->cam_angle >= 225 && spec->cam_angle < 315)
		spec->dir = 'S';
	ft_display_screen(spec);
}

void	ft_display_screen(t_spec *spec)
{
	int		col;
	int		line;
	double	wall_projection_size;
	double	prop_constant;

	col = 0;
	line = 0;
	prop_constant = ((WALL_SIZE / 2) * ((spec->resol[0] /2) / tan(RAD(30)))) / 2;
	while (col <= spec->resol[0])
	{
		wall_projection_size = (prop_constant / ft_cast_ray(spec));
		// printf("\nwall proj size : %2.f\n",wall_projection_size);
		// printf("\nproj const : %2.f\n", prop_constant);
		// printf("\nray length : %f\nangle : %f\n", ft_cast_ray(spec), spec->cam_angle);
		break;
		while (line < spec->resol[1])
		{
			if (line <= ((spec->resol[1] / 2) - (wall_projection_size / 2)))
				mlx_pixel_put(spec->mlx_ptr, spec->win_ptr, col, line, spec->col_floor);
			else if (line > ((spec->resol[1] / 2) - (wall_projection_size / 2)) && line <= ((spec->resol[1] / 2) + (wall_projection_size / 2)))
				mlx_pixel_put(spec->mlx_ptr, spec->win_ptr, col, line, 100150100);
			else if (line > ((spec->resol[1] / 2) + (wall_projection_size / 2)))
				mlx_pixel_put(spec->mlx_ptr, spec->win_ptr, col, line, spec->col_ceil);
			line++;
		}
		line = 0;
		col++;
		spec->cam_angle += (60 / spec->resol[0]) ;
		if (spec->cam_angle >= 360)
			spec->cam_angle -= 360;
		else if (spec->cam_angle < 0)
			spec->cam_angle += 360;
	}
	spec->cam_angle -= 60; 
	if (spec->cam_angle >= 360)
		spec->cam_angle -= 360;
	else if (spec->cam_angle < 0)
		spec->cam_angle += 360;
}
