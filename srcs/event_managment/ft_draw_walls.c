/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:45:17 by abarot            #+#    #+#             */
/*   Updated: 2020/04/17 16:52:44 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_texture(t_img_set *ist, int col, char path, char c)
{
	if (c == '+')
	{
		if (path == 'S')
			ist->south.mlx = ist->south.mlx + ((col % ist->south.width) * 4);
		if (path == 'N')
			ist->north.mlx = ist->north.mlx + ((col % ist->north.width) * 4);
		if (path == 'W')
			ist->west.mlx = ist->west.mlx + ((col % ist->west.width) * 4);
		if (path == 'E')
			ist->east.mlx = ist->east.mlx + ((col % ist->east.width) * 4);
	}
	if (c == '-')
	{
		if (path == 'S')
			ist->south.mlx = ist->south.mlx - ((col % ist->south.width) * 4);
		if (path == 'N')
			ist->north.mlx = ist->north.mlx - ((col % ist->north.width) * 4);
		if (path == 'W')
			ist->west.mlx = ist->west.mlx - ((col % ist->west.width) * 4);
		if (path == 'E')
			ist->east.mlx = ist->east.mlx - ((col % ist->east.width) * 4);
	}
}

t_img_2	ft_set_wall_img(char path, void *mlx_ptr, t_img_set *img_set,
							int height)
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
	t_img_2	img;

	ft_set_texture(&config->img_set, col, path, '+');
	img = ft_set_wall_img(path, config->mlx_ptr, &config->img_set, col_height);
	ft_put_img_to_screen(config->img_set.screen, img, col,
	config->parse.resol.y / 2 - img.height / 2);
	mlx_destroy_image(config->mlx_ptr, img.img_ptr);
	ft_set_texture(&config->img_set, col, path, '-');
}

void	ft_draw_walls(t_config *cf)
{
	t_raycast	ray;
	int			col;
	double		angle;
	int			obj_proj;

	ft_initialyse_ray(&ray);
	col = 0;
	angle = cf->parse.map_elt.cam_angle;
	ray.p_coor.x = (cf->parse.map_elt.p_coord.x * WALL_SIZE) + (WALL_SIZE / 2);
	ray.p_coor.y = (cf->parse.map_elt.p_coord.y * WALL_SIZE) + (WALL_SIZE / 2);
	while (col < cf->parse.resol.x)
	{
		ft_raycast(&ray, cf->parse.map_elt.map, angle, '1');
		obj_proj = ft_calc_projection(ray.dist_obj, angle,
		cf->parse.map_elt.cam_angle, cf->parse.resol.x);
		ft_draw_column(cf, ray.nesw_path, obj_proj, col);
		col++;
		angle += (FOV / (double)cf->parse.resol.x);
		if (angle > 360)
			angle -= 360;
	}
}
