/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:45:17 by abarot            #+#    #+#             */
/*   Updated: 2020/04/15 16:24:42 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_advance_angle(int *col, double *angle, double resol_x)
{
	*col = *col + 1;
	*angle = *angle + (FOV / resol_x);
	if (*angle > 360)
		*angle = *angle - 360;
}

void	ft_init_rays(t_coord p_coord, t_raycast *wall_ray, t_raycast *sprite_ray)
{
	ft_initialyse_ray(wall_ray);
	ft_initialyse_ray(sprite_ray);
	wall_ray->p_coor.x = (p_coord.x * WALL_SIZE) + (WALL_SIZE / 2);
	wall_ray->p_coor.y = (p_coord.y * WALL_SIZE) + (WALL_SIZE / 2);
	sprite_ray->p_coor.x = (p_coord.x * WALL_SIZE) + (WALL_SIZE / 2);
	sprite_ray->p_coor.y = (p_coord.y * WALL_SIZE) + (WALL_SIZE / 2);
}

void	ft_put_tmp_img(t_config *config, t_raycast *sprite_ray, t_raycast *wall_ray, double *angle, int *col)
{
	int			col2;
	int			mem_dist;
	int			obj_proj;
	t_img_2		tmp_img;

	col2 = *col;
	mem_dist = sprite_ray->dist_obj;
	obj_proj = ft_calc_projection(sprite_ray->dist_obj, *angle, config->parse.map_elt.cam_angle, config->parse.resol.x);
	tmp_img = ft_scalling(config->mlx_ptr, config->img_set.sprite, obj_proj, obj_proj);
	while (abs(sprite_ray->dist_obj - mem_dist) < SQUARE_SIZE &&
	sprite_ray->dist_obj < wall_ray->dist_obj && *col < config->parse.resol.x)
	{
		ft_advance_angle(col, angle, (double)config->parse.resol.x);
		ft_raycast(wall_ray, config->parse.map_elt.map, *angle, '1');
		ft_raycast(sprite_ray, config->parse.map_elt.map, *angle, '2');
	}
	if (col2 == 0)
	{
		while (tmp_img.width > (*col - col2))
		{
			tmp_img.mlx += 4;
			tmp_img.width--;
		}
	}
	ft_put_sprite_to_screen(config->img_set.screen, tmp_img, *col - ((*col - col2)), (config->parse.resol.y / 2) - (obj_proj / 2));
	mlx_destroy_image(config->mlx_ptr, tmp_img.img_ptr);
}

void	ft_draw_sprites(t_config *config)
{
	t_raycast	wall_ray;
	t_raycast	sprite_ray;
	int			col;
	double		angle;

	ft_init_rays(config->parse.map_elt.p_coord, &wall_ray, &sprite_ray);
	angle = config->parse.map_elt.cam_angle;
	col = 0;
	while (col < config->parse.resol.x)
	{
		ft_raycast(&wall_ray, config->parse.map_elt.map, angle, '1');
		ft_raycast(&sprite_ray, config->parse.map_elt.map, angle, '2');
		if (sprite_ray.dist_obj && sprite_ray.dist_obj < wall_ray.dist_obj)
			ft_put_tmp_img(config, &sprite_ray, &wall_ray, &angle, &col);
		else
			ft_advance_angle(&col, &angle, (double)config->parse.resol.x);
	}
}
