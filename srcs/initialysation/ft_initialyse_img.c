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

t_img_spec	ft_wall_slice(void *mlx_ptr, t_img_spec img_to_slice, int col, int size)
{
	t_img_spec	img;
	int bpp;
	int endian;
	int	y_img;
	int x_img;

	y_img = 0;
	x_img = 0;
	img.width = 1;
	img.height = size;
	img.img_to_put = mlx_new_image(mlx_ptr, img.width, img.height);
	img.mlx = mlx_get_data_addr(img.img_to_put, &bpp, &img.size_line, &endian);
	while (y_img < size)
	{
		img.mlx[(x_img * (bpp / 8) + img.size_line * y_img)] = 
		img_to_slice.mlx[(col * (bpp / 8) + img_to_slice.size_line * y_img)];
		img.mlx[(x_img * (bpp / 8) + img.size_line * y_img) + 1] = 
		img_to_slice.mlx[(col * (bpp / 8) + img_to_slice.size_line * y_img) + 1];
		img.mlx[(x_img * (bpp / 8) + img.size_line * y_img) + 2] = 
		img_to_slice.mlx[(col * (bpp / 8) + img_to_slice.size_line * y_img) + 2];
		img.mlx[(x_img * (bpp / 8) + img.size_line * y_img) + 3] = 
		img_to_slice.mlx[(col * (bpp / 8) + img_to_slice.size_line * y_img) + 3];
		y_img++;
		x_img++;
	}
	return (img);
}

t_img_spec	ft_img_scaling_to_resol(void *mlx_ptr, t_img_spec img_to_cut, t_coord resol)
{
	t_img_spec	img;
	t_coord		img_coor;
	t_coord		img_scalled_coor;
	int bpp;
	int endian;

	img_coor.x = 0;
	img_coor.y = 0;
	img_scalled_coor.x = 0;
	img_scalled_coor.y = 0;
	img.width = resol.x;
	img.height = resol.y;
	img.img_to_put = mlx_new_image(mlx_ptr, img.width, img.height);
	img.mlx = mlx_get_data_addr(img.img_to_put, &bpp, &img.size_line, &endian);
	while (img_coor.y - 1 < resol.y)
	{
		while (img_coor.x < resol.x)
		{
			img.mlx[img_coor.x * (bpp / 8) + img.size_line * img_coor.y] = 
			img_to_cut.mlx[(img_scalled_coor.x * (bpp / 8) + (img_scalled_coor.y * img_to_cut.size_line))];
			img.mlx[img_coor.x * (bpp / 8) + img.size_line * img_coor.y + 1] = 
			img_to_cut.mlx[(img_scalled_coor.x * (bpp / 8) + (img_scalled_coor.y * img_to_cut.size_line)) + 1];
			img.mlx[img_coor.x * (bpp / 8) + img.size_line  * img_coor.y + 2] = 
			img_to_cut.mlx[(img_scalled_coor.x * (bpp / 8) + (img_scalled_coor.y *  img_to_cut.size_line)) + 2];
			img.mlx[img_coor.x * (bpp / 8) + img.size_line  * img_coor.y + 3] = 
			img_to_cut.mlx[(img_scalled_coor.x * (bpp / 8) + (img_scalled_coor.y *  img_to_cut.size_line)) + 3];
			img_coor.x++;
			img_scalled_coor.x++;
			if (img_scalled_coor.x >= img_to_cut.width)
				img_scalled_coor.x = 0;
		}
		img_coor.x = 0;
		img_scalled_coor.x = 0;
		img_coor.y++;
		img_scalled_coor.y++;
		if (img_scalled_coor.y >= img_to_cut.height)
			img_scalled_coor.y = 0;
	}
	return (img);
}

void	ft_create_texture(t_config *config)
{
	config->img.east.img_to_put = mlx_xpm_file_to_image(config->mlx_ptr, config->path_east_texture, &config->img.east.width, &config->img.east.height);
	config->img.east.mlx =  mlx_get_data_addr(config->img.east.img_to_put, &(config->img.bpp), &(config->img.east.size_line), &(config->img.endian));
	config->img.west.img_to_put = mlx_xpm_file_to_image(config->mlx_ptr, config->path_west_texture, &config->img.west.width, &config->img.west.height);
	config->img.west.mlx =  mlx_get_data_addr(config->img.west.img_to_put, &(config->img.bpp), &(config->img.west.size_line), &(config->img.endian));
	config->img.south.img_to_put = mlx_xpm_file_to_image(config->mlx_ptr, config->path_south_texture, &config->img.south.width, &config->img.south.height);
	config->img.south.mlx =  mlx_get_data_addr(config->img.south.img_to_put, &(config->img.bpp), &(config->img.south.size_line), &(config->img.endian));
	config->img.north.img_to_put = mlx_xpm_file_to_image(config->mlx_ptr, config->path_north_texture, &config->img.north.width, &config->img.north.height);
	config->img.north.mlx =  mlx_get_data_addr(config->img.north.img_to_put, &(config->img.bpp), &(config->img.north.size_line), &(config->img.endian));
	config->img.north = ft_img_scaling_to_resol(config->mlx_ptr, config->img.north, config->resol);
	config->img.south = ft_img_scaling_to_resol(config->mlx_ptr, config->img.south, config->resol);
	config->img.east = ft_img_scaling_to_resol(config->mlx_ptr, config->img.east, config->resol);
	config->img.west = ft_img_scaling_to_resol(config->mlx_ptr, config->img.west, config->resol);
	// mlx_put_image_to_window(config->mlx_ptr, config->win_ptr, config->img.east.img_to_put, 0, 0);
	// sleep(1);
	// mlx_put_image_to_window(config->mlx_ptr, config->win_ptr, config->img.north.img_to_put, 0, 0);
	// sleep(1);
	// mlx_put_image_to_window(config->mlx_ptr, config->win_ptr, config->img.south.img_to_put, 0, 0);
	// sleep(1);
	// mlx_put_image_to_window(config->mlx_ptr, config->win_ptr, config->img.west.img_to_put, 0, 0);
	// sleep(1);
	// t_img_spec img;
	// int col = 300;
	// while (col < 600)
	// {
	// 	img = ft_wall_slice(config->mlx_ptr, config->img.north, col, 600);
	// 	mlx_put_image_to_window(config->mlx_ptr, config->win_ptr, img.img_to_put, col, 100);
	// 	mlx_destroy_image(config->mlx_ptr, img.img_to_put);
	// 	col++;
	// }
	// while(1);
}

void	ft_create_background(t_config *config)
{
	t_coord	bites_coor;
	unsigned char r;
  	unsigned char g;
  	unsigned char b;

	r = (mlx_get_color_value(config->mlx_ptr, config->col_ceil.R));
  	g = (mlx_get_color_value(config->mlx_ptr, config->col_ceil.G));
  	b = (mlx_get_color_value(config->mlx_ptr, config->col_ceil.B));
	bites_coor.x = 0;
	bites_coor.y = 0;
	config->img.ceiling.img_to_put = mlx_new_image(config->mlx_ptr, config->resol.x + 1, (config->resol.y + 1) / 2);
	config->img.ceiling.mlx = mlx_get_data_addr(config->img.ceiling.img_to_put, &config->img.bpp, &config->img.ceiling.size_line, &config->img.endian);
	config->img.floor.img_to_put = mlx_new_image(config->mlx_ptr, config->resol.x + 1, (config->resol.y + 1) / 2);
	config->img.floor.mlx = mlx_get_data_addr(config->img.floor.img_to_put, &config->img.bpp, &config->img.floor.size_line, &config->img.endian);
	while (bites_coor.y < config->resol.y / 2)
	{
		while (bites_coor.x < config->resol.x)
		{
			config->img.ceiling.mlx[bites_coor.x * (config->img.bpp / 8) + config->img.ceiling.size_line * bites_coor.y] = b;
			config->img.ceiling.mlx[bites_coor.x * (config->img.bpp / 8) + config->img.ceiling.size_line * bites_coor.y + 1] = g;
			config->img.ceiling.mlx[bites_coor.x * (config->img.bpp / 8) + config->img.ceiling.size_line * bites_coor.y + 2] = r;
			bites_coor.x++;
		}
		bites_coor.x = 0;
		bites_coor.y++;
	}
  	r = (mlx_get_color_value(config->mlx_ptr, config->col_floor.R));
  	g = (mlx_get_color_value(config->mlx_ptr, config->col_floor.G));
  	b = (mlx_get_color_value(config->mlx_ptr, config->col_floor.B));
	bites_coor.y = 0;
	while (bites_coor.y < config->resol.y / 2)
	{
		while (bites_coor.x < config->resol.x)
		{
			config->img.floor.mlx[bites_coor.x * (config->img.bpp / 8) + config->img.floor.size_line * bites_coor.y] = b;
			config->img.floor.mlx[bites_coor.x * (config->img.bpp / 8) + config->img.floor.size_line * bites_coor.y + 1] = g;
			config->img.floor.mlx[bites_coor.x * (config->img.bpp / 8) + config->img.floor.size_line * bites_coor.y + 2] = r;
			bites_coor.x++;
		}
		bites_coor.x = 0;
		bites_coor.y++;
	}
	// mlx_put_image_to_window(config->mlx_ptr, config->win_ptr, config->img.ceiling.img_to_put,0,0);
	// mlx_put_image_to_window(config->mlx_ptr, config->win_ptr, config->img.floor.img_to_put,0,config->resol.y / 2);
	// while(1);
}

void	ft_initialyse_img(t_config *config)
{
	ft_create_background(config);
	ft_create_texture(config);
}