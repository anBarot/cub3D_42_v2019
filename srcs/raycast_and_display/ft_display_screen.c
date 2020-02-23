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

void	ft_draw_column(t_config *config, t_raycast *ray, int col)
{
	int			y_coor;
	t_img_spec	img_tmp;

	y_coor = (config->resol.y / 2) - (ray->wall_proj / 2);
	if (ray->nesw_path == 'S')
		img_tmp = ft_scalling(config->mlx_ptr, config->img.south, 1, ray->wall_proj);
	else if (ray->nesw_path == 'E')
		img_tmp = ft_scalling(config->mlx_ptr, config->img.east, 1, ray->wall_proj);
	else if (ray->nesw_path == 'N')
		img_tmp = ft_scalling(config->mlx_ptr, config->img.north, 1, ray->wall_proj);
	else if (ray->nesw_path == 'W')
		img_tmp = ft_scalling(config->mlx_ptr, config->img.west, 1, ray->wall_proj);
	config->img.north.mlx = config->img.north.mlx + 4;
	config->img.east.mlx = config->img.east.mlx + 4;
	config->img.south.mlx = config->img.south.mlx + 4;
	config->img.west.mlx = config->img.west.mlx + 4;
	mlx_put_image_to_window(config->mlx_ptr, config->win_ptr, img_tmp.img_ptr, col, y_coor);
	mlx_destroy_image(config->mlx_ptr, img_tmp.img_ptr);
}

void	ft_get_wallproj(t_config *config, t_raycast *ray, double angle)
{
	ray->p_coor.x = (config->player_coord.x * WALL_SIZE) + (WALL_SIZE / 2);
	ray->p_coor.y = (config->player_coord.y * WALL_SIZE) + (WALL_SIZE / 2);
	ft_get_dist_to_wall(ray, config->map, angle);
	ray->prop_cste = ((WALL_SIZE / 2) * ((config->resol.x /2) / tan(RAD(FOV / 2))));
	ray->wall_proj = (ray->prop_cste / ray->smallest_dist);
	if (ray->wall_proj > config->resol.y)
		ray->wall_proj = config->resol.y;
}


void	ft_display_sprite(t_config *config, t_raycast *ray, double angle)
{
	int 		col;
	t_img_spec	img_tmp;
	double		d_angle;

	d_angle = FOV / (double)config->resol.x;
	col = 0;
	while (col < config->resol.x)
	{
		ft_get_wallproj(config, ray, angle);
		if (ray->value_bumped == SPRITE)
		{
			printf("\nsprite coor : %d,%f\n", col, angle);
			img_tmp = ft_scalling(config->mlx_ptr, config->img.sprite, ray->wall_proj, ray->wall_proj);
			mlx_put_image_to_window(config->mlx_ptr, config->win_ptr, img_tmp.img_ptr, col, (config->resol.y / 2) - (ray->wall_proj / 2));
			while (ray->value_bumped == SPRITE)
			{	
				col++;
				angle += d_angle;
				if (angle > 360)
					angle -= 360;
				else if (angle < 0)
					angle += 360;
				ft_get_wallproj(config, ray, angle);
			}
		}
		else
		{
			col++;
			angle += d_angle;
			if (angle > 360)
				angle -= 360;
			else if (angle < 0)
				angle += 360;
		}
	}
}

void	ft_display_screen(t_config *config)
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
	mlx_put_image_to_window(config->mlx_ptr, config->win_ptr, config->img.ceiling.img_ptr, 0, 0);
	mlx_put_image_to_window(config->mlx_ptr, config->win_ptr, config->img.floor.img_ptr, 0, config->resol.y / 2);
	while (col < config->resol.x)
	{
		ft_get_wallproj(config, ray, tmp_angle);
		ft_draw_column(config, ray, col);
		col++;
		tmp_angle += delta_angle;
		if (tmp_angle > 360)
			tmp_angle -= 360;
		else if (tmp_angle < 0)
			tmp_angle += 360;
	}
	ft_display_sprite(config, ray, (double)config->cam_angle);
	free(ray);
	ft_create_texture(config);
}
