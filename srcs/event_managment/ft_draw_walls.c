/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:45:17 by abarot            #+#    #+#             */
/*   Updated: 2020/04/15 14:37:42 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_texture(t_img_set *img_set, int col, char path, char c)
{
	if (c == '+')
	{
		if (path == 'S') 
			img_set->south.mlx = img_set->south.mlx + ((col % img_set->south.width) * 4);
		if (path == 'N') 
			img_set->north.mlx = img_set->north.mlx + ((col % img_set->north.width) * 4);
		if (path == 'W') 
			img_set->west.mlx = img_set->west.mlx + ((col % img_set->west.width) * 4);
		if (path == 'E') 
			img_set->east.mlx = img_set->east.mlx + ((col % img_set->east.width) * 4);
	}
	if (c == '-')
	{
		if (path == 'S') 
			img_set->south.mlx = img_set->south.mlx - ((col % img_set->south.width) * 4);
		if (path == 'N') 
			img_set->north.mlx = img_set->north.mlx - ((col % img_set->north.width) * 4);
		if (path == 'W') 
			img_set->west.mlx = img_set->west.mlx - ((col % img_set->west.width) * 4);
		if (path == 'E') 
			img_set->east.mlx = img_set->east.mlx - ((col % img_set->east.width) * 4);
	}
}

t_img_2	ft_set_wall_img(char path, void *mlx_ptr, t_img_set *img_set, int height)
{
	t_img_2	img_tmp;

	if (path == 'S')
		img_tmp = ft_scalling(mlx_ptr, img_set->south, 1, height);
	else if (path == 'E')
		img_tmp = ft_scalling(mlx_ptr, img_set->east, 1, height);
	else if (path == 'N')
		img_tmp = ft_scalling(mlx_ptr, img_set->north, 1, height);
	else if (path == 'W')
		img_tmp = ft_scalling(mlx_ptr, img_set->west, 1, height);
	return (img_tmp);
}

void	ft_draw_column(t_config *config, char path, int col_height, int col)
{
	t_img_2	img_tmp;

	ft_set_texture(&config->img_set, col, path, '+');
	img_tmp = ft_set_wall_img(path, config->mlx_ptr, &config->img_set, col_height);
	ft_put_img_to_screen(config->img_set.screen, img_tmp, col, config->parse.resol.y / 2 - img_tmp.height / 2);
	mlx_destroy_image(config->mlx_ptr, img_tmp.img_ptr);
	ft_set_texture(&config->img_set, col, path, '-');
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
}
