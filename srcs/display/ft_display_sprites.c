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

void	ft_put_sprite_to_screen(t_config *config, t_img sprite, int start_x, int start_y)
{
	t_coord	sprite_coor;
	t_coord	screen_coor;
	int		d_sprite;
	int		d_screen;

	sprite_coor.x = 0;
	sprite_coor.y = 0;
	screen_coor.x = start_x;
	screen_coor.y = start_y;
	while (sprite_coor.y < sprite.height)
	{
		while (sprite_coor.x < sprite.width)
		{
			d_sprite = sprite_coor.x * 4 + sprite_coor.y * sprite.size_line;
			d_screen = screen_coor.x * 4 + screen_coor.y * config->img.screen.size_line;
			if (sprite.mlx[d_sprite] >= 0)
				ft_pixel_filling(config->img.screen.mlx + d_screen, sprite.mlx + d_sprite);
			sprite_coor.x++;
			screen_coor.x++;
		}
		sprite_coor.x = 0;
		screen_coor.x = start_x;
		sprite_coor.y++;
		screen_coor.y++;
	}
}

void	ft_display_sprites(t_config *config)
{
	t_raycast	*ray_wall;
	t_raycast	*ray_sprite;
	int			col;
	double		delta_angle;
	double		tmp_angle;
	t_img		img_tmp;
	double		mem_sprite_dist;

	if (!(ray_wall = (t_raycast *)malloc(sizeof(t_raycast))) || 
	!(ray_sprite = (t_raycast *)malloc(sizeof(t_raycast))))
		return ;
	col = 0;
	delta_angle = (FOV / (double)config->resol.x);
	tmp_angle = config->cam_angle;
	ft_initialyse_ray(ray_wall);
	ft_initialyse_ray(ray_sprite);
	ray_sprite->center_angle = config->cam_angle + 30;
	ray_wall->center_angle = config->cam_angle + 30;
	if (config->cam_angle + 30 > 360)
	{
		ray_sprite->center_angle -= 360;
		ray_wall->center_angle -= 360;
	}
	while (col < config->resol.x)
	{
		ft_raycast(config, ray_sprite, tmp_angle, '2');
		ft_raycast(config, ray_wall, tmp_angle, '1');
		if (ray_sprite->dist_obj && ray_sprite->dist_obj < ray_wall->dist_obj)
		{
			if (ray_sprite->obj_proj > config->resol.y)
				ray_sprite->obj_proj = config->resol.y;
			img_tmp = ft_scalling(config->mlx_ptr, config->img.sprite, ray_sprite->obj_proj, ray_sprite->obj_proj);
			ft_put_sprite_to_screen(config, img_tmp, col, config->resol.y / 2 - ray_sprite->obj_proj / 2);
			// ft_put_img_to_screen(config->img.screen, img_tmp, col, config->resol.y / 2 - ray_sprite->obj_proj / 2);
			mem_sprite_dist = ray_sprite->dist_obj;
			while (fabs(ray_sprite->dist_obj - mem_sprite_dist) < WALL_SIZE && col < config->resol.x)
			{
				col++;
				tmp_angle += delta_angle;
				if (tmp_angle > 360)
					tmp_angle -= 360;
				else if (tmp_angle < 0)
					tmp_angle += 360;
				ft_raycast(config, ray_sprite, tmp_angle, '2');
				ft_raycast(config, ray_wall, tmp_angle, '1');
			}
		}
		else
		{
			col++;
			tmp_angle += delta_angle;
			if (tmp_angle > 360)
				tmp_angle -= 360;
			else if (tmp_angle < 0)
				tmp_angle += 360;
		}
	}
	free(ray_sprite);
	free(ray_wall);
}