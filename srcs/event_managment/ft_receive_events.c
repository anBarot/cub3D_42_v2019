/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_receive_events.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:14:58 by abarot            #+#    #+#             */
/*   Updated: 2020/04/15 18:07:27 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include "mlx_int.h"

extern int (*(g_mlx_int_param_event[]))();

void	ft_escape_game(t_config *config)
{
	int line;

	line = 0;
	if (config->win_ptr)
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
	exit(EXIT_SUCCESS);
}

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
	if (key == ESCAPEKEY)
		ft_escape_game(cf);
	ft_put_img_to_screen(cf->img_set.screen, cf->img_set.background, 0, 0);
	ft_draw_walls(cf);
	ft_draw_sprites(cf);
	mlx_put_image_to_window(cf->mlx_ptr, cf->win_ptr,
	cf->img_set.screen.img_ptr, 0, 0);
	return (1);
}

int		mlx_loop_2(t_xvar *xvar, t_config *config)
{
	t_loop lp;

	xvar->do_flush = 0;
	lp.win = xvar->win_list;
	XMapWindow(xvar->display, *(Window *)lp.win);
	lp.wm_delete_window = XInternAtom(xvar->display, "WM_DELETE_WINDOW", False);
	XSetWMProtocols(xvar->display, *(Window *)lp.win, &lp.wm_delete_window, 1);
	while (42)
	{
		while (!xvar->loop_hook || XPending(xvar->display))
		{
			XNextEvent(xvar->display, &lp.ev);
			lp.win = xvar->win_list;
			while (lp.win && (lp.win->window != lp.ev.xany.window))
				lp.win = lp.win->next;
			if ((Atom)lp.ev.xclient.data.l[0] == lp.wm_delete_window)
				ft_escape_game(config);
			if (lp.win && lp.ev.type < MLX_MAX_EVENT)
			{
				if (lp.win->hooks[lp.ev.type].hook)
					g_mlx_int_param_event[lp.ev.type](xvar, &lp.ev, lp.win);
			}
		}
		xvar->loop_hook(xvar->loop_param);
	}
}

int		ft_receive_events(t_config *config)
{
	mlx_put_image_to_window(config->mlx_ptr, config->win_ptr,
	config->img_set.screen.img_ptr, 0, 0);
	mlx_key_hook(config->win_ptr, &ft_pressed_key, config);
	mlx_loop_2(config->mlx_ptr, config);
	return (0);
}
