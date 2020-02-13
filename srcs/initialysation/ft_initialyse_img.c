/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:17:50 by abarot            #+#    #+#             */
/*   Updated: 2020/01/31 14:58:41 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"



void	ft_create_background(t_config *config)
{
	int     bpp;
	int     size_line;
	int     endian;
	t_coord	bites_coor;

	bites_coor.x = 0;
	bites_coor.y = 0;
	config->img->background = mlx_new_image(config->mlx_ptr, config->resol.x, config->resol.y);
	config->img->background_mlx = mlx_get_data_addr(config->img->background, &bpp, &size_line, &endian);
	while (bites_coor.y < config->resol.y)
	{
		while (bites_coor.y < config->resol.y / 2)
		{
			while (bites_coor.x < config->resol.x)
			{
				config->img->background_mlx[(bites_coor.x * (bpp / 8) + size_line * bites_coor.y )] = config->col_ceil/1000000;
				config->img->background_mlx[(bites_coor.x * (bpp / 8) + size_line * bites_coor.y + 1 )] = config->col_ceil/1000;
				config->img->background_mlx[(bites_coor.x * (bpp / 8) + size_line * bites_coor.y + 2 )] = config->col_ceil/1;
				config->img->background_mlx[(bites_coor.x * (bpp / 8) + size_line * bites_coor.y + 3 )] = 0;
				bites_coor.x++;
			}
			bites_coor.x = 0;
			bites_coor.y++;
		}
		while (bites_coor.y < config->resol.y)
		{
			while (bites_coor.x < config->resol.x)
			{
				config->img->background_mlx[(bites_coor.x * (bpp / 8) + size_line * bites_coor.y )] = config->col_floor/1000000;
				config->img->background_mlx[(bites_coor.x * (bpp / 8) + size_line * bites_coor.y + 1 )] = config->col_floor/1000;
				config->img->background_mlx[(bites_coor.x * (bpp / 8) + size_line * bites_coor.y + 2 )] = config->col_floor/1;
				config->img->background_mlx[(bites_coor.x * (bpp / 8) + size_line * bites_coor.y + 3 )] = 0;
				bites_coor.x++;
			}
			bites_coor.x = 0;
			bites_coor.y++;
		}
	}
	mlx_put_image_to_window(config->mlx_ptr, config->win_ptr, config->img->background, 0, 0);
}

void	ft_initialyse_img(t_config *config)
{
	ft_create_background(config);
	ft_create_texture(config);
}