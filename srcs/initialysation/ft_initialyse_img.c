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
	prop_cste.x = img_to_scale.width / width;
	prop_cste.y = img_to_scale.height / height; 
	img.img_ptr = mlx_new_image(mlx_ptr, img.width, img.height);
	img.mlx = mlx_get_data_addr(img.img_ptr, &bpp, &img.size_line, &endian);
	while (y_img < height)
	{
		while (x_img < width)
		{
			delta_fill = x_img * (bpp / 8) + img.size_line * y_img;
			delta_extract = (x_img * prop_cste.x * (bpp / 8)) + (img_to_scale.size_line * prop_cste.y * y_img);
			ft_pixel_filling(img.mlx + delta_fill, img_to_scale.mlx + delta_extract);
			x_img++;
		}
		x_img = 0;
		y_img++;
	}
	return (img);
}

t_img	ft_img_enlargement(void *mlx_ptr, t_img img_arg, t_coord dim)
{
	t_img		img;
	t_coord		img_arg_coor;
	t_coord		img_coor;
	int bpp;
	int endian;
	int d_fill;
	int d_extract;

	img_arg_coor.x = 0;
	img_arg_coor.y = 0;
	img_coor.x = 0;
	img_coor.y = 0;
	img.width = dim.x;
	img.height = dim.y;
	img.img_ptr = mlx_new_image(mlx_ptr, img.width, img.height);
	img.mlx = mlx_get_data_addr(img.img_ptr, &bpp, &img.size_line, &endian);
	while (img_arg_coor.y - 1 < dim.y)
	{
		while (img_arg_coor.x < dim.x)
		{
			d_fill = img_arg_coor.x * 4 + img.size_line * img_arg_coor.y;
			d_extract = img_coor.x * 4 + img_coor.y * img_arg.size_line;
			ft_pixel_filling(img.mlx + d_fill, img_arg.mlx + d_extract);
			img_arg_coor.x++;
			img_coor.x++;
			(img_coor.x >= img_arg.width) ? img_coor.x = 0 : 0;
		}
		img_arg_coor.x = 0;
		img_coor.x = 0;
		img_arg_coor.y++;
		img_coor.y++;
		(img_coor.y >= img_arg.height) ? img_coor.y = 0 : 0;
	}
	mlx_destroy_image(mlx_ptr, img_arg.img_ptr);
	return (img);
}

void	ft_create_texture(t_config *config)
{
	config->img.east.img_ptr = mlx_xpm_file_to_image(config->mlx_ptr, 
	config->path_east, &config->img.east.width, &config->img.east.height);
	config->img.east.mlx =  mlx_get_data_addr(config->img.east.img_ptr,
	&(config->img.bpp), &(config->img.east.size_line), &(config->img.endian));
	config->img.east = ft_img_enlargement(config->mlx_ptr, config->img.east, config->resol);
	config->img.west.img_ptr = mlx_xpm_file_to_image(config->mlx_ptr,
	config->path_west, &config->img.west.width, &config->img.west.height);
	config->img.west.mlx =  mlx_get_data_addr(config->img.west.img_ptr,
	&(config->img.bpp), &(config->img.west.size_line), &(config->img.endian));
	config->img.west = ft_img_enlargement(config->mlx_ptr, config->img.west, config->resol);
	config->img.south.img_ptr = mlx_xpm_file_to_image(config->mlx_ptr,
	config->path_south, &config->img.south.width, &config->img.south.height);
	config->img.south.mlx =  mlx_get_data_addr(config->img.south.img_ptr,
	&(config->img.bpp), &(config->img.south.size_line), &(config->img.endian));
	config->img.south = ft_img_enlargement(config->mlx_ptr, config->img.south, config->resol);
	config->img.north.img_ptr = mlx_xpm_file_to_image(config->mlx_ptr,
	config->path_north, &config->img.north.width, &config->img.north.height);
	config->img.north.mlx =  mlx_get_data_addr(config->img.north.img_ptr,
	&(config->img.bpp), &(config->img.north.size_line), &(config->img.endian));
	config->img.north = ft_img_enlargement(config->mlx_ptr, config->img.north, config->resol);
	config->img.sprite.img_ptr = mlx_xpm_file_to_image(config->mlx_ptr,
	config->path_sprite, &config->img.sprite.width, &config->img.sprite.height);
	config->img.sprite.mlx = mlx_get_data_addr(config->img.sprite.img_ptr,
	&(config->img.bpp), &(config->img.sprite.size_line), &(config->img.endian));
}

t_img	ft_fill_background(t_img img, t_color color, int width, int height)
{
	t_coord	bites_coor;
	int		delta_img;
	char	*color_str;

	if (!(color_str = ft_calloc(4, 1)))
		return (img);
	color_str[0] = color.B;
	color_str[1] = color.G;
	color_str[2] = color.R;
	bites_coor.x = 0;
	bites_coor.y = 0;
	while (bites_coor.y < height)
	{
		while (bites_coor.x < width)
		{
			delta_img = bites_coor.x * 4 + img.size_line * bites_coor.y;
			ft_pixel_filling(img.mlx + delta_img, color_str);
			bites_coor.x++;
		}
		bites_coor.x = 0;
		bites_coor.y++;
	}
	free(color_str);
	return (img);
}

void	ft_create_background(t_config *config)
{
	config->img.ceiling.img_ptr = mlx_new_image(config->mlx_ptr,
		config->resol.x + 1, (config->resol.y + 1) / 2);
	config->img.ceiling.mlx = mlx_get_data_addr(config->img.ceiling.img_ptr,
		&config->img.bpp, &config->img.ceiling.size_line, &config->img.endian);
	config->img.floor.img_ptr = mlx_new_image(config->mlx_ptr,
		config->resol.x + 1, (config->resol.y + 1) / 2);
	config->img.floor.mlx = mlx_get_data_addr(config->img.floor.img_ptr,
		&config->img.bpp, &config->img.floor.size_line, &config->img.endian);
	config->img.ceiling = ft_fill_background(config->img.ceiling,
		config->col_ceil, config->resol.x, config->resol.y / 2);
	config->img.floor = ft_fill_background(config->img.floor,
		config->col_floor, config->resol.x, config->resol.y / 2);
}
