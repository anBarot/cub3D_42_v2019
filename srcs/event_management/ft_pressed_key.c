/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pressed_key.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:05:01 by abarot            #+#    #+#             */
/*   Updated: 2020/01/31 15:11:28 by abarot           ###   ########.fr       */
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
	if (UPKEY(keycode))
		ft_move_backandforth(config, -1);
	else if (DOWNKEY(keycode))
		ft_move_backandforth(config, +1);
	else if (LEFTKEY(keycode))
		ft_turn(config, -20);
	else if (RIGHTKEY(keycode))
		ft_turn(config, +20);
	else if (LEFT_LAT_KEY(keycode))
		ft_move_lateral(config, -1);
	else if (RIGHT_LAT_KEY(keycode))
		ft_move_lateral(config, +1);
	else if (ESCAPEKEY(keycode))
	{
		ft_escape_game(config);
		exit(EXIT_SUCCESS);
	}
	return (1);
}
