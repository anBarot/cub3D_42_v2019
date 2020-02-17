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
		img_tmp = ft_wall_slice(config->mlx_ptr, config->img.south, col, ray->wall_proj);
	else if (ray->nesw_path == 'E')
		img_tmp = ft_wall_slice(config->mlx_ptr, config->img.east, col, ray->wall_proj);
	else if (ray->nesw_path == 'N')
		img_tmp = ft_wall_slice(config->mlx_ptr, config->img.north, col, ray->wall_proj);
	else if (ray->nesw_path == 'W')
		img_tmp = ft_wall_slice(config->mlx_ptr, config->img.west, col, ray->wall_proj);
	mlx_put_image_to_window(config->mlx_ptr, config->win_ptr, img_tmp.img_to_put, col, y_coor);
	mlx_destroy_image(config->mlx_ptr, img_tmp.img_to_put);
}

void	ft_get_wallproj(t_config *config, t_raycast *ray, double angle)
{
	ray->p_coor.x = ((double)config->player_coord.x * WALL_SIZE) + (WALL_SIZE / 2);
	ray->p_coor.y = ((double)config->player_coord.y * WALL_SIZE) + (WALL_SIZE / 2);
	ft_get_dist_to_wall(ray, config->map, angle);
	ray->prop_cste = ((WALL_SIZE / 2) * ((config->resol.x /2) / tan(RAD(FOV / 2))));
	ray->wall_proj = ray->prop_cste / ray->smallest_dist;
	// printf("\ndist : %f\nwall proj : %d\npath : %c\n", ray->smallest_dist, ray->wall_proj, ray->nesw_path);
}

void	ft_display_screen(t_config *config)
{
	t_raycast	*ray;
	int			col;
	double		delta_angle;
	double		tmp_angle;

	if (!(ray = (t_raycast *)malloc(sizeof(ray))))
		return ;
	col = 0;
	delta_angle = (60 / (double)config->resol.x);
	tmp_angle = config->cam_angle;
	mlx_put_image_to_window(config->mlx_ptr, config->win_ptr, config->img.ceiling.img_to_put, 0, 0);
	mlx_put_image_to_window(config->mlx_ptr, config->win_ptr, config->img.floor.img_to_put, 0, config->resol.y / 2);
	while (col < config->resol.x)
	{
		ft_initialyse_ray(ray);
		ft_get_wallproj(config, ray, tmp_angle);
		ft_draw_column(config, ray, col);
		col++;
		tmp_angle += delta_angle;
		if (tmp_angle > 360)
			tmp_angle -= 360;
		else if (tmp_angle < 0)
			tmp_angle += 360;
	}
	(ray) ? free(ray) : 0;
}
