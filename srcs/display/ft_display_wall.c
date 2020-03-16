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
	int		y_coor;
	t_img	img_tmp;

	y_coor = (config->resol.y / 2) - (ray->obj_proj / 2);
	if (ray->nesw_path == 'S')
		img_tmp = ft_scalling(config->mlx_ptr, config->img.south, 1, ray->obj_proj);
	else if (ray->nesw_path == 'E')
		img_tmp = ft_scalling(config->mlx_ptr, config->img.east, 1, ray->obj_proj);
	else if (ray->nesw_path == 'N')
		img_tmp = ft_scalling(config->mlx_ptr, config->img.north, 1, ray->obj_proj);
	else if (ray->nesw_path == 'W')
		img_tmp = ft_scalling(config->mlx_ptr, config->img.west, 1, ray->obj_proj);
	mlx_put_image_to_window(config->mlx_ptr, config->win_ptr, img_tmp.img_ptr, col, y_coor);
	config->img.north.mlx = config->img.north.mlx + 4;
	config->img.east.mlx = config->img.east.mlx + 4;
	config->img.south.mlx = config->img.south.mlx + 4;
	config->img.west.mlx = config->img.west.mlx + 4;
	mlx_destroy_image(config->mlx_ptr, img_tmp.img_ptr);
}

void	ft_display_wall(t_config *config)
{
	t_raycast	*ray;
	int			col;
	double		delta_angle;
	double		tmp_angle;

	if (!(ray = (t_raycast *)malloc(sizeof(t_raycast))))
		return ;
	ft_initialyse_ray(ray);
	col = 0;
	delta_angle = (FOV / (double)config->resol.x);
	tmp_angle = config->cam_angle;
	ray->center_angle = config->cam_angle + (FOV / 2);
	if (ray->center_angle > 360)
		ray->center_angle -= 360;
	mlx_put_image_to_window(config->mlx_ptr, config->win_ptr, config->img.ceiling.img_ptr, 0, 0);
	mlx_put_image_to_window(config->mlx_ptr, config->win_ptr, config->img.floor.img_ptr, 0, config->resol.y / 2);
	while (col < config->resol.x)
	{
		ft_raycast(config, ray, tmp_angle, '1');
		ft_draw_column(config, ray, col);
		col++;
		tmp_angle += delta_angle;
		if (tmp_angle > 360)
			tmp_angle -= 360;
	}
	free(ray);
	ft_create_texture(config);
}
