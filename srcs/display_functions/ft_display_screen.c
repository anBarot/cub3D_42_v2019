/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_screen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:45:17 by abarot            #+#    #+#             */
/*   Updated: 2020/01/31 11:30:59 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_draw_column(t_config *config, double wall_proj_size, int col)
{
	int		line;

	line = (config->resol.y / 2) - (wall_proj_size / 2);
	while (line <= ((config->resol.y / 2) + (wall_proj_size / 2)))
	{
		mlx_pixel_put(config->mlx_ptr, config->win_ptr, col, line, 100150100);
		line++;
	}
}

double	ft_get_wallproj(t_config *config, double angle)
{
	double	prop_constant;
	double	dist_to_wall;
	t_coord	p_coor;

	p_coor.x = (config->player_coord.x * WALL_SIZE) + (WALL_SIZE / 2);
	p_coor.y = (config->player_coord.y * WALL_SIZE) + (WALL_SIZE / 2);
	dist_to_wall = ft_get_dist_to_wall(p_coor, config->map, angle);
	prop_constant = ((WALL_SIZE / 2) * ((config->resol.x /2) / tan(RAD(FOV / 2))));
	return (prop_constant / dist_to_wall);
}

void	ft_display_screen(t_config *config)
{
	double	wall_projection_size;
	int		col;
	double	delta_angle;
	double	tmp_angle;

	col = 0;
	delta_angle = (60 / config->resol.x);
	tmp_angle = config->cam_angle;
	while (col <= config->resol.x)
	{
		wall_projection_size = ft_get_wallproj(config, tmp_angle);
		ft_draw_column(config, wall_projection_size, col);
		col++;
		tmp_angle += delta_angle;
		if (tmp_angle >= (double)360)
			tmp_angle -= 360;
		else if (tmp_angle < (double)0)
			tmp_angle += 360;
	}
}
