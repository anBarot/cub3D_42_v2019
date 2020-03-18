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

void	ft_pixel_filling(char *mlx_to_fill, char *mlx_to_extract)
{
	mlx_to_fill[0] = (unsigned int)mlx_to_extract[0];
	mlx_to_fill[1] = (unsigned int)mlx_to_extract[1];
	mlx_to_fill[2] = (unsigned int)mlx_to_extract[2];
	mlx_to_fill[3] = (unsigned int)mlx_to_extract[3];
}

t_img	ft_scalling(void *mlx_ptr, t_img img_to_scale, int width, int height)
{
	t_img		img;
	t_fcoord	prop_cste;
	int bpp;
	int endian;
	int	y_img;
	int x_img;
	int delta_fill;
	int delta_extract;

	y_img = 0;
	x_img = 0;
	img.width = width;
	img.height = height;
	prop_cste.x = (float)img_to_scale.width / (float)width;
	if (prop_cste.x < 0.000001)
		prop_cste.x = 0.000001;
	prop_cste.y = (float)img_to_scale.height / (float)height; 
	if (prop_cste.y < 0.000001)
		prop_cste.y = 0.000001;
	img.img_ptr = mlx_new_image(mlx_ptr, img.width, img.height);
	img.mlx = mlx_get_data_addr(img.img_ptr, &bpp, &img.size_line, &endian);
	while (y_img < height)
	{
		while (x_img < width)
		{
			delta_fill = x_img * (bpp / 8) + img.size_line * y_img;
			delta_extract = ((int)((float)x_img * prop_cste.x) * (bpp / 8)) + (img_to_scale.size_line *(int)(prop_cste.y * (float)y_img));
			ft_pixel_filling(img.mlx + delta_fill, img_to_scale.mlx + delta_extract);
			x_img++;
		}
		x_img = 0;
		y_img++;
	}
	return (img);
}

void	ft_create_texture(t_config *config)
{
	config->img.east.img_ptr = mlx_xpm_file_to_image(config->mlx_ptr, 
	config->path_east, &config->img.east.width, &config->img.east.height);
	config->img.east.mlx =  mlx_get_data_addr(config->img.east.img_ptr,
	&(config->img.bpp), &(config->img.east.size_line), &(config->img.endian));
	config->img.west.img_ptr = mlx_xpm_file_to_image(config->mlx_ptr,
	config->path_west, &config->img.west.width, &config->img.west.height);
	config->img.west.mlx =  mlx_get_data_addr(config->img.west.img_ptr,
	&(config->img.bpp), &(config->img.west.size_line), &(config->img.endian));
	config->img.south.img_ptr = mlx_xpm_file_to_image(config->mlx_ptr,
	config->path_south, &config->img.south.width, &config->img.south.height);
	config->img.south.mlx =  mlx_get_data_addr(config->img.south.img_ptr,
	&(config->img.bpp), &(config->img.south.size_line), &(config->img.endian));
	config->img.north.img_ptr = mlx_xpm_file_to_image(config->mlx_ptr,
	config->path_north, &config->img.north.width, &config->img.north.height);
	config->img.north.mlx =  mlx_get_data_addr(config->img.north.img_ptr,
	&(config->img.bpp), &(config->img.north.size_line), &(config->img.endian));
	config->img.sprite.img_ptr = mlx_xpm_file_to_image(config->mlx_ptr,
	config->path_sprite, &config->img.sprite.width, &config->img.sprite.height);
	config->img.sprite.mlx = mlx_get_data_addr(config->img.sprite.img_ptr,
	&(config->img.bpp), &(config->img.sprite.size_line), &(config->img.endian));
}
