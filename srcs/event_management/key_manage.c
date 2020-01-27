/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:05:01 by abarot            #+#    #+#             */
/*   Updated: 2020/01/27 19:18:11 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_key_pressed(int keycode, t_spec *spec)
{
	if (UPKEY(keycode))
		ft_move_forward(spec);
	else if (DOWNKEY(keycode))
		ft_move_backward(spec);
	else if (LEFTKEY(keycode))
		ft_turn_left(spec);
	else if (RIGHTKEY(keycode))
		ft_turn_right(spec);
	else if (LEFT_LAT_LKEY(keycode))
		ft_move_lateral(spec);
	else if (LEFT_LAT_KEY(keycode))
		ft_move_lateral(spec);
	else if (ESCAPEKEY(keycode))
	{	
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
