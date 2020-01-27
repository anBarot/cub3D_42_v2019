/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_screen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:45:17 by abarot            #+#    #+#             */
/*   Updated: 2020/01/27 14:58:15 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_draw_column(t_spec *spec, double wall_proj_size, int col)
{
	int		line;

	line = 0;
	while (line < spec->resol[1])
	{
		if (line <= ((spec->resol[1] / 2) - (wall_proj_size / 2)))
			mlx_pixel_put(spec->mlx_ptr, spec->win_ptr, col, line, spec->col_floor);
		else if (line > ((spec->resol[1] / 2) - (wall_proj_size / 2)) 
			&& line <= ((spec->resol[1] / 2) + (wall_proj_size / 2)))
			mlx_pixel_put(spec->mlx_ptr, spec->win_ptr, col, line, 100150100);
		else if (line > ((spec->resol[1] / 2) + (wall_proj_size / 2)))
			mlx_pixel_put(spec->mlx_ptr, spec->win_ptr, col, line, spec->col_ceil);
		line++;
	}
	line = 0;
}

void	ft_display_screen(t_spec *spec)
{
	int		col;
	double	wall_projection_size;
	double	prop_constant;

	col = 0;
	prop_constant = ((WALL_SIZE / 2) * ((spec->resol[0] /2) / tan(RAD(30))));
	while (col <= spec->resol[0])
	{
		wall_projection_size = (prop_constant / ft_cast_ray(spec));
		// printf("\nwall proj size : %2.f\n",wall_projection_size);
		// printf("\nproj const : %2.f\n", prop_constant);
		// printf("\nray length : %f\nangle : %f\n", ft_cast_ray(spec), spec->cam_angle);
		ft_draw_column(spec, wall_projection_size, col);
		col++;
		spec->cam_angle += (60 / spec->resol[0]) ;
		if (spec->cam_angle >= (double)360)
			spec->cam_angle -= 360;
		else if (spec->cam_angle < (double)0)
			spec->cam_angle += 360;
	}
	spec->cam_angle -= 60; 
	if (spec->cam_angle >= 360)
		spec->cam_angle -= 360;
	else if (spec->cam_angle < 0)
		spec->cam_angle += 360;
}
