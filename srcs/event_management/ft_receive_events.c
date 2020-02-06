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

void	ft_escape_game(t_config *config)
{
	int line;

	line = 0;
	mlx_destroy_window(config->mlx_ptr, config->win_ptr);
	free(config->path_north_texture);
	free(config->path_east_texture);
	free(config->path_south_texture);
	free(config->path_west_texture);
	free(config->path_sprite);
	while (config->map && config->map[line])
	{
		free(config->map[line]);
		line++;
	}
	free(config->map);
	free(config);
}

int	ft_pressed_key(int keycode, t_config *config)
{
	printf("\nkeycode : %d\nkey pressed : %s\n", keycode, (UPKEY(keycode)) ? "UPKEY" : (DOWNKEY(keycode)) ? "DOWNKEY"
	 : (LEFT_LAT_KEY(keycode)) ? "LAT LEFT" : (RIGHT_LAT_KEY(keycode)) ? "LAT RIGHT" : 
	 (LEFTKEY(keycode)) ? "LEFKEY" : (RIGHTKEY(keycode)) ? "RIGHTKEY" : 0);
	(UPKEY(keycode)) ? ft_move_backandforth(config, +1) : 0;
	(DOWNKEY(keycode)) ? ft_move_backandforth(config, -1) : 0;
	(LEFTKEY(keycode)) ? ft_turn(config, -15) : 0;
	(RIGHTKEY(keycode)) ? ft_turn(config, +15) : 0;
	(RIGHT_LAT_KEY(keycode)) ? ft_move_lateral(config, +1) : 0;
	(LEFT_LAT_KEY(keycode)) ? ft_move_lateral(config, -1) : 0;
	if (ESCAPEKEY(keycode))
	{
		ft_escape_game(config);
		exit(EXIT_SUCCESS);
	}
	return (1);
}

int		ft_receive_events(t_config *config, char *title)
{
	config->mlx_ptr = mlx_init();
	config->win_ptr = mlx_new_window(config->mlx_ptr, config->resol.x, config->resol.y, title);
	// //ft_display_screen(config);
	mlx_key_hook(config->win_ptr, &ft_pressed_key, config);
	mlx_loop(config->mlx_ptr);
	return (0);
}
