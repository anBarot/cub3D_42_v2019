/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_receive_events.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:14:58 by abarot            #+#    #+#             */
/*   Updated: 2020/04/19 09:55:59 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_pressed_key(int key, t_config *cf)
{
	if (UPKEY1 == key || UPKEY2 == key)
		ft_move_backandforth(cf->parse.map_elt.map,
		&cf->parse.map_elt.p_coord, cf->parse.map_elt.cam_angle, +1);
	if (DOWNKEY1 == key || DOWNKEY2 == key)
		ft_move_backandforth(cf->parse.map_elt.map,
		&cf->parse.map_elt.p_coord, cf->parse.map_elt.cam_angle, -1);
	if (LEFTKEY == key)
		ft_turn(&cf->parse.map_elt.cam_angle, -10);
	if (RIGHTKEY == key)
		ft_turn(&cf->parse.map_elt.cam_angle, +10);
	if (RIGHT_LAT_KEY == key)
		ft_move_lateral(cf->parse.map_elt.map,
		&cf->parse.map_elt.p_coord, cf->parse.map_elt.cam_angle, +1);
	if (LEFT_LAT_KEY == key)
		ft_move_lateral(cf->parse.map_elt.map,
		&cf->parse.map_elt.p_coord, cf->parse.map_elt.cam_angle, -1);
	if (key == ESCAPEKEY || cf->escape == 1)
		cf->escape = 1;
	return (0);
}

int		ft_close(t_config *config)
{
	config->escape = 1;
	return (0);
}

int		ft_expose(t_config *cf)
{
	ft_put_img_to_screen(cf->img_set.screen, cf->img_set.background, 0, 0);
	ft_draw_walls(cf);
	ft_draw_sprites(cf);
	mlx_put_image_to_window(cf->mlx_ptr, cf->win_ptr,
		cf->img_set.screen.img_ptr, 0, 0);
	if (cf->escape)
	{
		ft_printf("\n\n\n------A bientôt!------\n\n\n");
		ft_escape_game(cf);
	}
	return (0);
}

int		ft_receive_events(t_config *config)
{
	mlx_do_key_autorepeaton(config->mlx_ptr);
	mlx_put_image_to_window(config->mlx_ptr, config->win_ptr,
	config->img_set.screen.img_ptr, 0, 0);
	mlx_hook(config->win_ptr, 2, KeyPressMask, &ft_pressed_key, config);
	mlx_hook(config->win_ptr, 33, 1L << 17, &ft_close, config);
	mlx_loop_hook(config->mlx_ptr, &ft_expose, config);
	mlx_loop(config->mlx_ptr);
	return (0);
}
