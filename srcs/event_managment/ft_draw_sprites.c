/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:45:17 by abarot            #+#    #+#             */
/*   Updated: 2023/03/08 15:19:27 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_adv_angle(int *col, double *angle, double resol_x)
{
	*col = *col + 1;
	*angle = *angle + (FOV / resol_x);
	if (*angle > 360)
		*angle = *angle - 360;
}

void	ft_init_rays(t_coord p_coord, t_raycast *wall_ray,
						t_raycast *sprite_ray)
{
	ft_initialyse_ray(wall_ray);
	ft_initialyse_ray(sprite_ray);
	wall_ray->p_coor.x = (p_coord.x * WALL_SIZE) + (WALL_SIZE / 2);
	wall_ray->p_coor.y = (p_coord.y * WALL_SIZE) + (WALL_SIZE / 2);
	sprite_ray->p_coor.x = (p_coord.x * WALL_SIZE) + (WALL_SIZE / 2);
	sprite_ray->p_coor.y = (p_coord.y * WALL_SIZE) + (WALL_SIZE / 2);
}

void	ft_init_ds2(t_drsprites_2 *ds_2, t_config cf, t_drsprites ds)
{
	ds_2->mem_dist = ds.sprite_ray.dist_obj;
	ds_2->obj_proj = ft_calc_projection(ds.sprite_ray.dist_obj, ds.angle,
	cf.parse.map_elt.cam_angle, cf.parse.resol.x);
	ds_2->tmp_img = ft_scalling(cf.mlx_ptr, cf.img_set.sprite,
	ds_2->obj_proj, ds_2->obj_proj);
	ds_2->col = ds.col;
	if (ds.col == 0)
		while (abs((int)ds.sprite_ray.dist_obj - ds_2->mem_dist) <
		SQUARE_SIZE && ds.sprite_ray.dist_obj < ds.wall_ray.dist_obj
		&& abs(ds_2->col) < (ds_2->obj_proj))
		{
			ds_2->col = ds_2->col - 1;
			ds.angle = ds.angle - ((double)FOV / (double)cf.parse.resol.x);
			if (ds.angle < 0)
				ds.angle = ds.angle + 360;
			ft_raycast(&ds.wall_ray, cf.parse.map_elt.map, ds.angle, '1');
			ft_raycast(&ds.sprite_ray, cf.parse.map_elt.map, ds.angle, '2');
		}
}

void	ft_put_tmp_img(t_config *cf, t_drsprites *ds)
{
	t_drsprites_2 ds_2;

	ft_init_ds2(&ds_2, *cf, *ds);
	while (abs((int)ds->sprite_ray.dist_obj - ds_2.mem_dist) <
	SQUARE_SIZE && ds->sprite_ray.dist_obj < ds->wall_ray.dist_obj &&
	ds->col < cf->parse.resol.x)
	{
		ft_adv_angle(&ds->col, &ds->angle, (double)cf->parse.resol.x);
		ft_raycast(&ds->wall_ray, cf->parse.map_elt.map, ds->angle, '1');
		ft_raycast(&ds->sprite_ray, cf->parse.map_elt.map, ds->angle, '2');
	}
	if (ds_2.col != 0 && ds->col != cf->parse.resol.x &&
	((ds_2.tmp_img.width > (ds->col - ds_2.col)
	&& ds_2.mem_dist > ds->wall_ray.dist_obj)))
		ds_2.tmp_img.width = ds->col - ds_2.col;
	if (ds_2.col <= 0)
		ft_put_sprite_to_screen(cf->img_set.screen, ds_2.tmp_img, ds_2.col +
	((ds->col - ds_2.col) / 2), (cf->parse.resol.y / 2) - (ds_2.obj_proj / 2));
	else
		ft_put_sprite_to_screen(cf->img_set.screen, ds_2.tmp_img, ds_2.col,
		(cf->parse.resol.y / 2) - (ds_2.obj_proj / 2));
	mlx_destroy_image(cf->mlx_ptr, ds_2.tmp_img.img_ptr);
}

void	ft_draw_sprites(t_config *config)
{
	t_drsprites	ds;

	ft_init_rays(config->parse.map_elt.p_coord, &ds.wall_ray,
	&ds.sprite_ray);
	ds.angle = config->parse.map_elt.cam_angle;
	ds.col = 0;
	while (ds.col < config->parse.resol.x)
	{
		ft_raycast(&ds.wall_ray, config->parse.map_elt.map,
		ds.angle, '1');
		ft_raycast(&ds.sprite_ray, config->parse.map_elt.map, ds.angle, '2');
		if (ds.sprite_ray.dist_obj && ds.sprite_ray.dist_obj <
			ds.wall_ray.dist_obj)
			ft_put_tmp_img(config, &ds);
		else
			ft_adv_angle(&ds.col, &ds.angle, (double)config->parse.resol.x);
	}
}
