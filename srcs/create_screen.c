#include <cub3D.h>

void	ft_put_img_to_screen(t_img screen, t_img img, int start_x, int start_y)
{
	t_coord img_coor;
	t_coord screen_coor;
	int		i_screen;
	int		i_img;

	img_coor.x = 0;
	img_coor.y = 0;
	screen_coor.x = start_x;
	screen_coor.y = start_y;
	while (img_coor.y < img.height)
	{
		while (img_coor.x < img.width)
		{
			i_screen = screen_coor.x * 4 + screen_coor.y * screen.size_line;
			i_img = img_coor.x * 4 + img_coor.y * img.size_line;
			ft_pixel_filling(screen.mlx + i_screen, img.mlx + i_img);
			img_coor.x++;
			screen_coor.x++;
		}
		img_coor.x = 0;
		screen_coor.x = start_x;
		img_coor.y++;
		screen_coor.y++;
	}
}

void	ft_fill_screen_background(t_img img, t_color color, t_coord starting_point, t_coord dim)
{
	int		delta_img;
	char	*color_str;

	if (!(color_str = ft_calloc(4, 1)))
		return ;
	color_str[0] = color.B;
	color_str[1] = color.G;
	color_str[2] = color.R;
	while (starting_point.y < dim.y)
	{
		while (starting_point.x < dim.x)
		{
			delta_img = starting_point.x * 4 + img.size_line * starting_point.y;
			ft_pixel_filling(img.mlx + delta_img, color_str);
			starting_point.x++;
		}
		starting_point.x = 0;
		starting_point.y++;
	}
	free(color_str);
}

void	ft_initialize_screen(t_config *config)
{
	t_coord coor_to_fill;
	t_coord dim;

	coor_to_fill.x = 0;
	coor_to_fill.y = 0;
	dim.x = config->img.screen.width;
	dim.y = config->img.screen.height / 2;
	ft_fill_screen_background(config->img.screen, config->col_ceil, coor_to_fill, dim);
	coor_to_fill.x = 0;
	coor_to_fill.y = config->img.screen.height / 2;
	dim.x = config->img.screen.width;
	dim.y = config->img.screen.height;
	ft_fill_screen_background(config->img.screen, config->col_floor, coor_to_fill, dim);
}

void	ft_create_screen(t_config *config)
{
	config->img.screen.width = config->resol.x;
	config->img.screen.height = config->resol.y;
	config->img.screen.img_ptr = mlx_new_image(config->mlx_ptr, config->img.screen.width, config->img.screen.height);
	config->img.screen.mlx = mlx_get_data_addr(config->img.screen.img_ptr, &config->img.bpp, &config->img.screen.size_line, &config->img.endian);
	ft_initialize_screen(config);
}