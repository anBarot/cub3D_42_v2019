/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_receive_events.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:14:58 by abarot            #+#    #+#             */
/*   Updated: 2020/04/14 15:44:26 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include "mlx_int.h"

extern int	(*(mlx_int_param_event[]))();

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

int		ft_pressed_key(int keycode, t_config *config)
{
	if (UPKEY1 == keycode || UPKEY2 == keycode) 
		ft_move_backandforth(config->parse.map_elt.map, 
		&config->parse.map_elt.p_coord, config->parse.map_elt.cam_angle, +1);
	if (DOWNKEY1 == keycode || DOWNKEY2 == keycode)
		ft_move_backandforth(config->parse.map_elt.map,
		&config->parse.map_elt.p_coord, config->parse.map_elt.cam_angle, -1);
	if (LEFTKEY == keycode)
		ft_turn(&config->parse.map_elt.cam_angle, -10);
	if (RIGHTKEY == keycode)
		ft_turn(&config->parse.map_elt.cam_angle, +10);
	if (RIGHT_LAT_KEY == keycode)
		ft_move_lateral(config->parse.map_elt.map,
		&config->parse.map_elt.p_coord, config->parse.map_elt.cam_angle, +1);
	if (LEFT_LAT_KEY == keycode)
		ft_move_lateral(config->parse.map_elt.map,
		&config->parse.map_elt.p_coord, config->parse.map_elt.cam_angle, -1);
	if (keycode == ESCAPEKEY)
		ft_escape_game(config);
	ft_initialize_screen(&config->img_set.screen, config->parse.col_ceil, config->parse.col_floor);
	ft_draw_walls(config);
	ft_draw_sprites(config);
	mlx_put_image_to_window(config->mlx_ptr, config->win_ptr, config->img_set.screen.img_ptr, 0, 0);
	return (1);
}

int		mlx_loop_2(t_xvar *xvar, t_config *config)
{
	XEvent		ev;
	t_win_list	*win;
	Atom		wm_delete_window;

	xvar->do_flush = 0;
	win = xvar->win_list;
	XMapWindow(xvar->display, *(Window *)win);
	wm_delete_window = XInternAtom(xvar->display, "WM_DELETE_WINDOW", False);
	XSetWMProtocols(xvar->display, *(Window *)win, &wm_delete_window, 1);
 	while (42)
    {
    	while (!xvar->loop_hook || XPending(xvar->display))
		{
	  		XNextEvent(xvar->display,&ev);
	  		win = xvar->win_list;
	  		while (win && (win->window!=ev.xany.window))
	  			win = win->next;
			if ((Atom)ev.xclient.data.l[0] == wm_delete_window)
			 	ft_escape_game(config);
			if (win && ev.type < MLX_MAX_EVENT)
	    	{
				if (win->hooks[ev.type].hook)
	    			mlx_int_param_event[ev.type](xvar, &ev, win);
			}
		}
    	xvar->loop_hook(xvar->loop_param);
    }
}

int		ft_receive_events(t_config *config)
{
	mlx_put_image_to_window(config->mlx_ptr, config->win_ptr, config->img_set.screen.img_ptr, 0, 0);
	mlx_key_hook(config->win_ptr, &ft_pressed_key, config);
	mlx_loop_2(config->mlx_ptr, config);
	return (0);
}
