/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_screen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:45:17 by abarot            #+#    #+#             */
/*   Updated: 2020/01/29 18:00:51 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_draw_column(t_config *config, double wall_proj_size, int col)
{
	int		line;

<<<<<<< HEAD
	line = 0;
	while (line < config->resol[1])
	{
		if (line <= ((config->resol[1] / 2) - (wall_proj_size / 2)))
			mlx_pixel_put(config->mlx_ptr, config->win_ptr, col, line, config->col_floor);
		else if (line > ((config->resol[1] / 2) - (wall_proj_size / 2)) 
			&& line <= ((config->resol[1] / 2) + (wall_proj_size / 2)))
			mlx_pixel_put(config->mlx_ptr, config->win_ptr, col, line, 100150100);
		else if (line > ((config->resol[1] / 2) + (wall_proj_size / 2)))
			mlx_pixel_put(config->mlx_ptr, config->win_ptr, col, line, config->col_ceil);
=======
	line = (config->resol[1] / 2) - (wall_proj_size / 2);
	while (line < ((config->resol[1] / 2) + (wall_proj_size / 2)))
	{
		if (line > ((config->resol[1] / 2) - (wall_proj_size / 2)) 
			&& line <= ((config->resol[1] / 2) + (wall_proj_size / 2)))
			mlx_pixel_put(config->mlx_ptr, config->win_ptr, col, line, 100150100);
>>>>>>> origin/cub3D_v2020_01_29
		line++;
	}
	line = 0;
}

void	ft_display_screen(t_config *config)
{
	int		col;
	double	wall_projection_size;
	double	prop_constant;

	col = 0;
	prop_constant = ((WALL_SIZE / 2) * ((config->resol[0] /2) / tan(RAD(30))));
	while (col <= config->resol[0])
	{
		wall_projection_size = (prop_constant / ft_cast_ray(config));
<<<<<<< HEAD
		// printf("\nwall proj size : %2.f\n",wall_projection_size);
		// printf("\nproj const : %2.f\n", prop_constant);
		// printf("\nray length : %f\nangle : %f\n", ft_cast_ray(config),s config->cam_angle);
		ft_draw_column(config, wall_projection_size, col);
		col++;
		config->cam_angle += (60 / config->resol[0]) ;
=======
		ft_draw_column(config, wall_projection_size, col);
		col++;
		config->cam_angle += (60 / config->resol[0]);
>>>>>>> origin/cub3D_v2020_01_29
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
