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

// to_do
// -	correction wall display : when dist near line [0] or col [0] -> dist too short 

void	ft_pixel_filling(char *mlx_to_fill, char *mlx_to_extract)
{
	mlx_to_fill[0] = mlx_to_extract[0];
	mlx_to_fill[1] = mlx_to_extract[1];
	mlx_to_fill[2] = mlx_to_extract[2];
	mlx_to_fill[3] = 0;
}

t_img_spec	ft_scalling(void *mlx_ptr, t_img_spec img_to_scale, int width, int height)
{
	t_img_spec	img;
	t_coord		prop_cste;
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
	prop_cste.x = img_to_scale.width / width;
	prop_cste.y = img_to_scale.height / height; 
	img.img_ptr = mlx_new_image(mlx_ptr, img.width, img.height);
	img.mlx = mlx_get_data_addr(img.img_ptr, &bpp, &img.size_line, &endian);
	while (y_img < height)
	{
		while (x_img < width)
		{
			delta_fill = x_img * (bpp / 8) + img.size_line * y_img;
			delta_extract = x_img * prop_cste.x * (bpp / 8) + img_to_scale.size_line * prop_cste.y * y_img;
			ft_pixel_filling(img.mlx + delta_fill, img_to_scale.mlx + delta_extract);
			x_img++;
		}
		x_img = 0;
		y_img++;
	}
	return (img);
}

t_img_spec	ft_img_scaling_to_resol(void *mlx_ptr, t_img_spec img_param, t_coord resol)
{
	t_img_spec	img;
	t_coord		img_coor;
	t_coord		img_scalled_coor;
	int bpp;
	int endian;
	int delta_fill;
	int delta_extract;

	img_coor.x = 0;
	img_coor.y = 0;
	img_scalled_coor.x = 0;
	img_scalled_coor.y = 0;
	img.width = resol.x;
	img.height = resol.y;
	img.img_ptr = mlx_new_image(mlx_ptr, img.width, img.height);
	img.mlx = mlx_get_data_addr(img.img_ptr, &bpp, &img.size_line, &endian);
	while (img_coor.y - 1 < resol.y)
	{
		while (img_coor.x < resol.x)
		{
			delta_fill = img_coor.x * (bpp / 8) + img.size_line * img_coor.y;
			delta_extract = img_scalled_coor.x * (bpp / 8) + img_scalled_coor.y * img_param.size_line;
			ft_pixel_filling(img.mlx + delta_fill, img_param.mlx + delta_extract);
			img_coor.x++;
			img_scalled_coor.x++;
			if (img_scalled_coor.x >= img_param.width)
				img_scalled_coor.x = 0;
		}
		img_coor.x = 0;
		img_scalled_coor.x = 0;
		img_coor.y++;
		img_scalled_coor.y++;
		if (img_scalled_coor.y >= img_param.height)
			img_scalled_coor.y = 0;
	}
	mlx_destroy_image(mlx_ptr, img_param.img_ptr);
	return (img);
}

void	ft_create_texture(t_config *config)
{
	config->img.east.img_ptr = mlx_xpm_file_to_image(config->mlx_ptr, config->path_east_texture, &config->img.east.width, &config->img.east.height);
	config->img.east.mlx =  mlx_get_data_addr(config->img.east.img_ptr, &(config->img.bpp), &(config->img.east.size_line), &(config->img.endian));
	config->img.east = ft_img_scaling_to_resol(config->mlx_ptr, config->img.east, config->resol);
	config->img.west.img_ptr = mlx_xpm_file_to_image(config->mlx_ptr, config->path_west_texture, &config->img.west.width, &config->img.west.height);
	config->img.west.mlx =  mlx_get_data_addr(config->img.west.img_ptr, &(config->img.bpp), &(config->img.west.size_line), &(config->img.endian));
	config->img.west = ft_img_scaling_to_resol(config->mlx_ptr, config->img.west, config->resol);
	config->img.south.img_ptr = mlx_xpm_file_to_image(config->mlx_ptr, config->path_south_texture, &config->img.south.width, &config->img.south.height);
	config->img.south.mlx =  mlx_get_data_addr(config->img.south.img_ptr, &(config->img.bpp), &(config->img.south.size_line), &(config->img.endian));
	config->img.south = ft_img_scaling_to_resol(config->mlx_ptr, config->img.south, config->resol);
	config->img.north.img_ptr = mlx_xpm_file_to_image(config->mlx_ptr, config->path_north_texture, &config->img.north.width, &config->img.north.height);
	config->img.north.mlx =  mlx_get_data_addr(config->img.north.img_ptr, &(config->img.bpp), &(config->img.north.size_line), &(config->img.endian));
	config->img.north = ft_img_scaling_to_resol(config->mlx_ptr, config->img.north, config->resol);
	config->img.sprite.img_ptr = mlx_xpm_file_to_image(config->mlx_ptr, config->path_sprite, &config->img.sprite.width, &config->img.sprite.height);
	config->img.sprite.mlx =  mlx_get_data_addr(config->img.sprite.img_ptr, &(config->img.bpp), &(config->img.sprite.size_line), &(config->img.endian));
}

void	ft_create_background(t_config *config)
{
	t_coord	bites_coor;
	char	*r;
  	char	*g;
  	char	*b;
	char	*color_str;
	int		delta_img;

	r = ft_char_to_str((mlx_get_color_value(config->mlx_ptr, config->col_ceil.R)));
  	g = ft_char_to_str((mlx_get_color_value(config->mlx_ptr, config->col_ceil.G)));
  	b = ft_char_to_str((mlx_get_color_value(config->mlx_ptr, config->col_ceil.B)));
	color_str = ft_strjoin(ft_strjoin(b, g, 3), ft_strjoin(r, ft_char_to_str(0), 3), 3);
	bites_coor.x = 0;
	bites_coor.y = 0;
	config->img.ceiling.img_ptr = mlx_new_image(config->mlx_ptr, config->resol.x + 1, (config->resol.y + 1) / 2);
	config->img.ceiling.mlx = mlx_get_data_addr(config->img.ceiling.img_ptr, &config->img.bpp, &config->img.ceiling.size_line, &config->img.endian);
	config->img.floor.img_ptr = mlx_new_image(config->mlx_ptr, config->resol.x + 1, (config->resol.y + 1) / 2);
	config->img.floor.mlx = mlx_get_data_addr(config->img.floor.img_ptr, &config->img.bpp, &config->img.floor.size_line, &config->img.endian);
	while (bites_coor.y < config->resol.y / 2)
	{
		while (bites_coor.x < config->resol.x)
		{
			delta_img = bites_coor.x * (config->img.bpp / 8) + config->img.ceiling.size_line * bites_coor.y;
			ft_pixel_filling(config->img.ceiling.mlx + delta_img, color_str);
			bites_coor.x++;
		}
		bites_coor.x = 0;
		bites_coor.y++;
	}
	free(color_str);
	r = ft_char_to_str((mlx_get_color_value(config->mlx_ptr, config->col_floor.R)));
  	g = ft_char_to_str((mlx_get_color_value(config->mlx_ptr, config->col_floor.G)));
  	b = ft_char_to_str((mlx_get_color_value(config->mlx_ptr, config->col_floor.B)));
	color_str = ft_strjoin(ft_strjoin(b, g, 3), ft_strjoin(r, ft_char_to_str(0), 3), 3);
	bites_coor.y = 0;
	while (bites_coor.y < config->resol.y / 2)
	{
		while (bites_coor.x < config->resol.x)
		{
			delta_img = bites_coor.x * (config->img.bpp / 8) + config->img.floor.size_line * bites_coor.y;
			ft_pixel_filling(config->img.floor.mlx + delta_img, color_str);
			bites_coor.x++;
		}
		bites_coor.x = 0;
		bites_coor.y++;
	}
	free(color_str);
}

void	ft_initialyse_img(t_config *config)
{
	ft_create_background(config);
	ft_create_texture(config);
}