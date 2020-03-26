/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_walls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:45:17 by abarot            #+#    #+#             */
/*   Updated: 2020/01/31 11:30:59 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_draw_sprites(t_config *config)
{
	t_raycast	wall_ray;
	t_raycast	sprite_ray;
	int			col;
	int			col_2;
	double		tmp_angle;
	int			obj_proj;
	t_img		tmp_img;

	ft_initialyse_ray(&wall_ray);
	ft_initialyse_ray(&sprite_ray);
	col = 0;
	tmp_angle = config->parse.map_elt.cam_angle;
	wall_ray.p_coor.x = (config->parse.map_elt.p_coord.x * WALL_SIZE) + (WALL_SIZE / 2);
	wall_ray.p_coor.y = (config->parse.map_elt.p_coord.y * WALL_SIZE) + (WALL_SIZE / 2);
	sprite_ray.p_coor.x = (config->parse.map_elt.p_coord.x * WALL_SIZE) + (WALL_SIZE / 2);
	sprite_ray.p_coor.y = (config->parse.map_elt.p_coord.y * WALL_SIZE) + (WALL_SIZE / 2);
	while (col < config->parse.resol.x)
	{
		ft_raycast(&wall_ray, config->parse.map_elt.map, tmp_angle, '1');
		ft_raycast(&sprite_ray, config->parse.map_elt.map, tmp_angle, '2');
		if (sprite_ray.dist_obj && sprite_ray.dist_obj < wall_ray.dist_obj)
		{
			col_2 = col;
			obj_proj = ft_calc_projection(sprite_ray.dist_obj, tmp_angle, config->parse.map_elt.cam_angle, config->parse.resol.x);
			while (sprite_ray.dist_obj && sprite_ray.dist_obj < wall_ray.dist_obj && col < config->parse.resol.x)
			{
				col++;
				tmp_angle +=  (FOV / (double)config->parse.resol.x);
				if (tmp_angle > 360)
					tmp_angle -= 360;
				ft_raycast(&wall_ray, config->parse.map_elt.map, tmp_angle, '1');
				ft_raycast(&sprite_ray, config->parse.map_elt.map, tmp_angle, '2');
			}
			tmp_img = ft_scalling(config->mlx_ptr, config->img_set.sprite, obj_proj, obj_proj);
			if ((col - col_2) < tmp_img.width && col != config->parse.resol.x)
			{
				tmp_img = ft_shift_img(config->mlx_ptr, tmp_img, tmp_img.width - (col - col_2), 0);
				ft_put_sprite_to_screen(config->img_set.screen, tmp_img, 0, (config->parse.resol.y / 2) - (obj_proj / 2));
			}
			else
				ft_put_sprite_to_screen(config->img_set.screen, tmp_img, col_2, (config->parse.resol.y / 2) - (obj_proj / 2));
		}
		else
		{
			col++;
			tmp_angle +=  (FOV / (double)config->parse.resol.x);
			if (tmp_angle > 360)
				tmp_angle -= 360;
		}
	}
}