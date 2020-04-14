/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:45:17 by abarot            #+#    #+#             */
/*   Updated: 2020/04/14 13:53:57 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_column(t_config *config, char path, int col_height, int col)
{
	t_img_2	img_tmp;

	if (path == 'S')
	{
		img_tmp = ft_scalling(config->mlx_ptr, config->img_set.south, 1, col_height);
		config->img_set.south.mlx = config->img_set.south.mlx + 4;
	}
	else if (path == 'E')
	{
		img_tmp = ft_scalling(config->mlx_ptr, config->img_set.east, 1, col_height);
		config->img_set.east.mlx = config->img_set.east.mlx + 4;
	}
	else if (path == 'N')
	{	
		img_tmp = ft_scalling(config->mlx_ptr, config->img_set.north, 1, col_height);
		config->img_set.north.mlx = config->img_set.north.mlx + 4;
	}
	else if (path == 'W')
	{	
		img_tmp = ft_scalling(config->mlx_ptr, config->img_set.west, 1, col_height);
		config->img_set.west.mlx = config->img_set.west.mlx + 4;
	}
	ft_put_img_to_screen(config->img_set.screen, img_tmp, col, config->parse.resol.y / 2 - img_tmp.height / 2);
	mlx_destroy_image(config->mlx_ptr, img_tmp.img_ptr);
}

void	ft_draw_walls(t_config *config)
{
	t_raycast	ray;
	int			col;
	double		tmp_angle;
	int			obj_proj;

	ft_initialyse_ray(&ray);
	col = 0;
	tmp_angle = config->parse.map_elt.cam_angle;
	ray.p_coor.x = (config->parse.map_elt.p_coord.x * WALL_SIZE) + (WALL_SIZE / 2);
	ray.p_coor.y = (config->parse.map_elt.p_coord.y * WALL_SIZE) + (WALL_SIZE / 2);
	while (col < config->parse.resol.x)
	{
		ft_raycast(&ray, config->parse.map_elt.map,tmp_angle, '1');
		obj_proj = ft_calc_projection(ray.dist_obj, tmp_angle, config->parse.map_elt.cam_angle, config->parse.resol.x);
		ft_draw_column(config, ray.nesw_path, obj_proj, col);
		col++;
		tmp_angle +=  (FOV / (double)config->parse.resol.x);
		if (tmp_angle > 360)
			tmp_angle -= 360;
	}
	ft_create_texture(config->mlx_ptr, &config->img_set, config->parse.path_set);
}
