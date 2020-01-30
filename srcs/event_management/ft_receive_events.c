/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_receive_events.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:14:58 by abarot            #+#    #+#             */
/*   Updated: 2020/01/29 17:58:04 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		ft_receive_events(t_config *config, char *title)
{
	void	*background_img;

	mlx_init(config->mlx_ptr);
	mlx_new_window(config->mlx_ptr, config->resol[0], config->resol[1], title);
	background_img = mlx_new_image(config->mlx_ptr, config->res[0], config->res[1]);
	mlx_put_image_to_window(config->mlx_ptr, config->win_ptr, background_img, 0, 0);
	mlx_loop(config->mlx_ptr)
	mlx_mouse_hook(config->win_ptr, int (*ft_pressed_key)(), config)
	return (0);
}
