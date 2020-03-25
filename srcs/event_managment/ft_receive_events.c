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
	mlx_destroy_image(config->mlx_ptr, config->img_set.west.img_ptr);
	mlx_destroy_image(config->mlx_ptr, config->img_set.east.img_ptr);
	mlx_destroy_image(config->mlx_ptr, config->img_set.north.img_ptr);
	mlx_destroy_image(config->mlx_ptr, config->img_set.south.img_ptr);
	mlx_destroy_image(config->mlx_ptr, config->img_set.sprite.img_ptr);
	mlx_destroy_image(config->mlx_ptr, config->img_set.screen.img_ptr);
	free(config->parse.path_set.north);
	free(config->parse.path_set.east);
	free(config->parse.path_set.south);
	free(config->parse.path_set.west);
	free(config->parse.path_set.sprite);
	while (config->parse.map_elt.map[line])
	{
		free(config->parse.map_elt.map[line]);
		line++;
	}
	free(config->win_ptr);
	free(config->mlx_ptr);
	free(config);
}

int	ft_pressed_key(int keycode, t_config *config)
{
	(UPKEY(keycode)) ? ft_move_backandforth(config->parse.map_elt.map, &config->parse.map_elt.p_coord, config->parse.map_elt.cam_angle, +1) : 0;
	(DOWNKEY(keycode)) ? ft_move_backandforth(config->parse.map_elt.map, &config->parse.map_elt.p_coord, config->parse.map_elt.cam_angle, -1) : 0;
	(LEFTKEY(keycode)) ? ft_turn(&config->parse.map_elt.cam_angle, -10) : 0;
	(RIGHTKEY(keycode)) ? ft_turn(&config->parse.map_elt.cam_angle, +10) : 0;
	(RIGHT_LAT_KEY(keycode)) ? ft_move_lateral(config->parse.map_elt.map, &config->parse.map_elt.p_coord, config->parse.map_elt.cam_angle, +1) : 0;
	(LEFT_LAT_KEY(keycode)) ? ft_move_lateral(config->parse.map_elt.map, &config->parse.map_elt.p_coord, config->parse.map_elt.cam_angle, -1) : 0;
	if (ESCAPEKEY(keycode))
	{
		ft_escape_game(config);
		exit(EXIT_SUCCESS);
	}
	ft_initialize_screen(&config->img_set.screen, config->parse.col_ceil, config->parse.col_floor);
	ft_draw_walls(config);
	ft_draw_sprites(config);
	mlx_put_image_to_window(config->mlx_ptr, config->win_ptr, config->img_set.screen.img_ptr, 0, 0);
	return (1);
}

int		ft_receive_events(t_config *config)
{
	mlx_put_image_to_window(config->mlx_ptr, config->win_ptr, config->img_set.screen.img_ptr, 0, 0);
	mlx_key_hook(config->win_ptr, &ft_pressed_key, config);
	mlx_loop(config->mlx_ptr);
	return (0);
}
