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

void	ft_create_texture(t_config *config)
{
	int width; 
	int heigh; 
	
	width = 300; 
	heigh = 300;
	config->img.east = mlx_xpm_file_to_image(config->mlx_ptr, config->path_east_texture, &width, &heigh);
	config->img.east_mlx =  mlx_get_data_addr(config->img.east, &(config->img.bpp), &(config->img.size_line), &(config->img.endian));
	config->img.west = mlx_xpm_file_to_image(config->mlx_ptr, config->path_west_texture, &width, &heigh);
	config->img.west_mlx =  mlx_get_data_addr(config->img.west, &(config->img.bpp), &(config->img.size_line), &(config->img.endian));
	config->img.south = mlx_xpm_file_to_image(config->mlx_ptr, config->path_south_texture, &width, &heigh);
	config->img.south_mlx =  mlx_get_data_addr(config->img.south, &(config->img.bpp), &(config->img.size_line), &(config->img.endian));
	config->img.north = mlx_xpm_file_to_image(config->mlx_ptr, config->path_north_texture, &width, &heigh);
	config->img.north_mlx =  mlx_get_data_addr(config->img.north, &(config->img.bpp), &(config->img.size_line), &(config->img.endian));
	// mlx_put_image_to_window(config->mlx_ptr, config->win_ptr, config->img.east, 50, 50);
	// mlx_put_image_to_window(config->mlx_ptr, config->win_ptr, config->img.north, 300, 300);
	// mlx_put_image_to_window(config->mlx_ptr, config->win_ptr, config->img.south, 50, 300);
	// mlx_put_image_to_window(config->mlx_ptr, config->win_ptr, config->img.west, 300, 50);
	// while(1);
}

void	ft_create_background(t_config *config)
{
	int     bpp;
	int     size_line;
	int     endian;
	t_coord	bites_coor;


	unsigned char r;
  	unsigned char g;
  	unsigned char b;

	r = (mlx_get_color_value(config->mlx_ptr, config->col_ceil.R));
  	g = (mlx_get_color_value(config->mlx_ptr, config->col_ceil.G));
  	b = (mlx_get_color_value(config->mlx_ptr, config->col_ceil.B));

	bites_coor.x = 0;
	bites_coor.y = 0;
	config->img.background = mlx_new_image(config->mlx_ptr, config->resol.x, config->resol.y);
	config->img.background_mlx = mlx_get_data_addr(config->img.background, &bpp, &size_line, &endian);
	while (bites_coor.y < config->resol.y)
	{
		while (bites_coor.y < config->resol.y / 2)
		{
			while (bites_coor.x < config->resol.x)
			{
				config->img.background_mlx[bites_coor.x * (bpp / 8) + size_line * bites_coor.y] = b;
				config->img.background_mlx[bites_coor.x * (bpp / 8) + size_line * bites_coor.y + 1] = g;
				config->img.background_mlx[bites_coor.x * (bpp / 8) + size_line * bites_coor.y + 2] = r;
				bites_coor.x++;
			}
			bites_coor.x = 0;
			bites_coor.y++;
		}
  		r = (mlx_get_color_value(config->mlx_ptr, config->col_floor.R));
  		g = (mlx_get_color_value(config->mlx_ptr, config->col_floor.G));
  		b = (mlx_get_color_value(config->mlx_ptr, config->col_floor.B));
		while (bites_coor.y < config->resol.y)
		{
			while (bites_coor.x < config->resol.x)
			{
				config->img.background_mlx[bites_coor.x * (bpp / 8) + size_line * bites_coor.y] = b;
				config->img.background_mlx[bites_coor.x * (bpp / 8) + size_line * bites_coor.y + 1] = g;
				config->img.background_mlx[bites_coor.x * (bpp / 8) + size_line * bites_coor.y + 2] = r;
				bites_coor.x++;
			}
			bites_coor.x = 0;
			bites_coor.y++;
		}
	}
	mlx_put_image_to_window(config->mlx_ptr, config->win_ptr, config->img.background, 0, 0);
}

void	ft_initialyse_img(t_config *config)
{
	ft_create_background(config);
	ft_create_texture(config);
}