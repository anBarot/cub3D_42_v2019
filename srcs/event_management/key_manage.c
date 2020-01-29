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

int	ft_key_pressed(int keycode, t_config *config)
{
	printf("\nkeycode : %d\n",keycode);
	if (UPKEY(keycode))
		ft_move_forward(config);
	else if (DOWNKEY(keycode))
		ft_move_backward(config);
	else if (LEFTKEY(keycode))
		ft_turn_left(config);
	else if (RIGHTKEY(keycode))
		ft_turn_right(config);
	else if (RIGHT_LAT_KEY(keycode))
		ft_move_lateral_rigth(config);
	else if (LEFT_LAT_KEY(keycode))
		ft_move_lateral_left(config);
	else if (ESCAPEKEY(keycode))
	{	
		mlx_destroy_window(config->mlx_ptr, config->win_ptr);
		return (0);
	}
	printf("\ncoor playeur : \nline : %d\ncol : %d\ndir : %c\nangle : %.2f\n", 
	config->map_player_coord[0], config->map_player_coord[1], config->dir, config->cam_angle);
	return (1);
}

void	ft_move_forward(t_config *config)
{
	if (config->dir == 'N' && config->map[config->map_player_coord[0] - 1][config->map_player_coord[1]] != '1')
		config->map_player_coord[0] -= 1;
	else if (config->dir == 'W' && config->map[config->map_player_coord[0]][config->map_player_coord[1] - 1] != '1')
		config->map_player_coord[1] -= 1;
	else if (config->dir == 'S' && config->map[config->map_player_coord[0] + 1][config->map_player_coord[1]] != '1')
		config->map_player_coord[0] += 1;
	else if	(config->dir == 'E' && config->map[config->map_player_coord[0]][config->map_player_coord[1] + 1] != '1')
		config->map_player_coord[1] += 1;
	ft_display_screen(config);
}

void	ft_move_backward(t_config *config)
{
	if (config->dir == 'N' && config->map[config->map_player_coord[0] + 1][config->map_player_coord[1]] != '1')
		config->map_player_coord[0] += 1;
	else if (config->dir == 'W' && config->map[config->map_player_coord[0]][config->map_player_coord[1] + 1] != '1')
		config->map_player_coord[1] += 1;
	else if (config->dir == 'S' && config->map[config->map_player_coord[0] - 1][config->map_player_coord[1]] != '1')
		config->map_player_coord[0] -= 1;
	else if	(config->dir == 'E' && config->map[config->map_player_coord[0]][config->map_player_coord[1] - 1] != '1')
		config->map_player_coord[1] -= 1;
	ft_display_screen(config);
}

void	ft_turn_left(t_config *config)
{
	if (config->cam_angle == 0)
		config->cam_angle = 360;
	config->cam_angle -= 20;
	if (config->cam_angle == 0)
		config->cam_angle = 360;
	config->cam_angle -= 10;
	if (config->cam_angle >= 135 && config->cam_angle < 225)
		config->dir = 'E';
	if (config->cam_angle >= 45 && config->cam_angle < 135)
		config->dir = 'N';
	if ((config->cam_angle >= 315 && config->cam_angle <= 360)
		|| (config->cam_angle >= 0 && config->cam_angle < 45))
		config->dir = 'W';
	if (config->cam_angle >= 225 && config->cam_angle < 315)
		config->dir = 'S';
	ft_display_screen(config);
}

void	ft_turn_right(t_config *config)
{
	if (config->cam_angle == 360)
		config->cam_angle = 0;
	config->cam_angle += 20;
	if (config->cam_angle >= 135 && config->cam_angle < 225)
		config->dir = 'E';
	if (config->cam_angle >= 45 && config->cam_angle < 135)
		config->dir = 'N';
	if ((config->cam_angle >= 315 && config->cam_angle <= 360)
		|| (config->cam_angle >= 0 && config->cam_angle < 45))
		config->dir = 'W';
	if (config->cam_angle >= 225 && config->cam_angle < 315)
		config->dir = 'S';
	ft_display_screen(config);
}
