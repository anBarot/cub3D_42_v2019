/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   //ft_display_screen.c                              :+:      :+:    :+:   */
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
    void	*wall_texture;
	int 	width = 1;

    
	printf("\n---draw column---\n");
	y_coor = (config->resol.y / 2) - (ray->wall_proj / 2);
	printf("\nfile : %s\n", config->path_west_texture);
	if (ray->nesw_path == 'S')
    	wall_texture = mlx_xpm_file_to_image(config->mlx_ptr, config->path_south_texture, &width, &(ray->wall_proj));
	else if (ray->nesw_path == 'E')
    	wall_texture = mlx_xpm_file_to_image(config->mlx_ptr, config->path_east_texture, &width, &(ray->wall_proj));
	else if (ray->nesw_path == 'N')
    	wall_texture = mlx_xpm_file_to_image(config->mlx_ptr, config->path_north_texture, &width, &(ray->wall_proj));
	else if (ray->nesw_path == 'W')
    	wall_texture = mlx_xpm_file_to_image(config->mlx_ptr, config->path_west_texture, &width, &(ray->wall_proj));
	printf("\n---get wall texture---\n\ny coor : %d\ncol : %d\nwall texture : %p\n", y_coor, col, wall_texture);
	mlx_put_image_to_window(config->mlx_ptr, config->win_ptr, wall_texture, col, y_coor);
	mlx_destroy_image (config->mlx_ptr, wall_texture);
}

void	ft_initialyse_ray(t_raycast *ray)
{
	ray->prop_cste = 0;
	ray->p_coor.x = 0;
	ray->p_coor.y = 0;
	ray->dist_cross_hor = 0;
	ray->dist_cross_vert = 0;
	ray->smallest_dist = 0;
	ray->wall_proj = 0;
	ray->nesw_path = 0;
}

void	ft_get_wallproj(t_config *config, t_raycast *ray, double angle)
{
	ray->p_coor.x = ((double)config->player_coord.x * WALL_SIZE) + (WALL_SIZE / 2);
	ray->p_coor.y = ((double)config->player_coord.y * WALL_SIZE) + (WALL_SIZE / 2);
	ft_get_dist_to_wall(ray, config->map, angle);
	ray->prop_cste = ((WALL_SIZE / 2) * ((config->resol.x /2) / tan(RAD(FOV / 2))));
	ray->wall_proj = ray->prop_cste / ray->smallest_dist;
	printf("\ndist : %f\nwall proj : %d\npath : %c\n", ray->smallest_dist, ray->wall_proj, ray->nesw_path);
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
	while (col <= config->resol.x)
	{
		ft_initialyse_ray(ray);
		ft_get_wallproj(config, ray, tmp_angle);
		ft_draw_column(config, ray, col);
		col++;
		tmp_angle += delta_angle;
		if (tmp_angle > (double)360)
			tmp_angle -= 360;
		else if (tmp_angle < (double)0)
			tmp_angle += 360;
	}
}
