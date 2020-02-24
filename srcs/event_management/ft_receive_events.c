/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_receive_events.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:14:58 by abarot            #+#    #+#             */
/*   Updated: 2020/01/31 15:27:32 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <X11/Xlib.h>
#include <X11/Xatom.h>

void	ft_escape_game(t_config *config)
{
	int line;

	line = 0;
	mlx_destroy_window(config->mlx_ptr, config->win_ptr);
	free(config->path_north);
	free(config->path_east);
	free(config->path_south);
	free(config->path_west);
	free(config->path_sprite);
	while (config->map[line])
	{
		free(config->map[line]);
		line++;
	}
	free(config->map);
	free(config);
}

int	ft_pressed_key(int keycode, t_config *config)
{
	(UPKEY(keycode)) ? ft_move_backandforth(config, +1) : 0;
	(DOWNKEY(keycode)) ? ft_move_backandforth(config, -1) : 0;
	(LEFTKEY(keycode)) ? ft_turn(config, -10) : 0;
	(RIGHTKEY(keycode)) ? ft_turn(config, +10) : 0;
	(RIGHT_LAT_KEY(keycode)) ? ft_move_lateral(config, +1) : 0;
	(LEFT_LAT_KEY(keycode)) ? ft_move_lateral(config, -1) : 0;
	if (ESCAPEKEY(keycode))
	{
		ft_escape_game(config);
		exit(EXIT_SUCCESS);
	}
	return (1);
}

// int	ft_pressed_button(int button, int x,int y, t_config *config)
// {
// 	return (1);
// }

int		ft_receive_events(t_config *config)
{
	ft_display_screen(config);
	mlx_key_hook(config->win_ptr, &ft_pressed_key, config);
	// mlx_mouse_hook (config->win_ptr, &ft_pressed_button, config);
	if (config->win_ptr == 0)
	{
		ft_escape_game(config);
		exit(EXIT_SUCCESS);
	}
	mlx_loop(config->mlx_ptr);
	return (0);
}
