/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_screen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:45:17 by abarot            #+#    #+#             */
/*   Updated: 2020/01/30 13:12:45 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_draw_column(t_config *config, double wall_proj_size, int col)
{
	int		line;

	line = (config->resol[1] / 2) - (wall_proj_size / 2);
	while (line < ((config->resol[1] / 2) + (wall_proj_size / 2)))
	{
		if (line > ((config->resol[1] / 2) - (wall_proj_size / 2)) 
			&& line <= ((config->resol[1] / 2) + (wall_proj_size / 2)))
			mlx_pixel_put(config->mlx_ptr, config->win_ptr, col, line, 100150100);
		line++;
	}
	line = 0;
}

void	ft_display_screen(t_config *config)
{
	double	wall_projection_size;
	double	prop_constant;
	void	*background_img;

	col = 0;
	mlx_clear
	prop_constant = ((WALL_SIZE / 2) * ((config->resol[0] /2) / tan(RAD(30))));
	background_img = mlx_new_image(config->mlx_ptr, config->res[0], config->res[1]);
	mlx_put_image_to_window(config->mlx_ptr, config->win_ptr, background_img, 0, 0);
	while (col <= config->resol[0])
	{
		wall_projection_size = (prop_constant / ft_cast_ray(config));
		ft_draw_column(config, wall_projection_size, col);
		col++;
		config->cam_angle += (60 / config->resol[0]);
		if (config->cam_angle >= (double)360)
			config->cam_angle -= 360;
		else if (config->cam_angle < (double)0)
			config->cam_angle += 360;
	}
	config->cam_angle -= 60; 
	if (config->cam_angle >= 360)
		config->cam_angle -= 360;
	else if (config->cam_angle < 0)
		config->cam_angle += 360;
}
