/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_wall.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:45:17 by abarot            #+#    #+#             */
/*   Updated: 2020/01/31 11:30:59 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_draw_column(t_config *config, t_raycast *ray, int col)
{
	t_img	img_tmp;

	if (ray->nesw_path == 'S')
	{
		img_tmp = ft_scalling(config->mlx_ptr, config->img.south, 1, ray->obj_proj);
		config->img.south.mlx = config->img.south.mlx + 4;
	}
	else if (ray->nesw_path == 'E')
	{
		img_tmp = ft_scalling(config->mlx_ptr, config->img.east, 1, ray->obj_proj);
		config->img.east.mlx = config->img.east.mlx + 4;
	}
	else if (ray->nesw_path == 'N')
	{	
		img_tmp = ft_scalling(config->mlx_ptr, config->img.north, 1, ray->obj_proj);
		config->img.north.mlx = config->img.north.mlx + 4;
	}
	else if (ray->nesw_path == 'W')
	{	
		img_tmp = ft_scalling(config->mlx_ptr, config->img.west, 1, ray->obj_proj);
		config->img.west.mlx = config->img.west.mlx + 4;
	}
	ft_put_img_to_screen(config->img.screen, img_tmp, col, config->resol.y / 2 - img_tmp.height / 2);
	mlx_destroy_image(config->mlx_ptr, img_tmp.img_ptr);
}

void	ft_display_wall(t_config *config)
{
	t_raycast	*ray;
	int			col;
	double		delta_angle;
	double		tmp_angle;

	ft_initialize_screen(config);
	if (!(ray = (t_raycast *)malloc(sizeof(t_raycast))))
		return ;
	ft_initialyse_ray(ray);
	col = 0;
	delta_angle = (FOV / (double)config->resol.x);
	tmp_angle = config->cam_angle;
	ray->center_angle = config->cam_angle + (FOV / 2);
	if (ray->center_angle > 360)
		ray->center_angle -= 360;
	while (col < config->resol.x)
	{
		ft_raycast(config, ray, tmp_angle, '1');
		ft_draw_column(config, ray, col);
		col++;
		tmp_angle += delta_angle;
		if (tmp_angle > 360)
			tmp_angle -= 360;
	}
	mlx_put_image_to_window(config->mlx_ptr, config->win_ptr, config->img.screen.img_ptr, 0, 0);
	free(ray);
	ft_create_texture(config);
}
