#include "initialize.h"

void	ft_initialize_screen(t_img_2 *screen, t_color c_color, t_color f_color)
{
	t_coord coor_to_fill;
	t_coord dim;

	coor_to_fill.x = 0;
	coor_to_fill.y = 0;
	dim.x = screen->width;
	dim.y = screen->height / 2;
	ft_fill_img_with_color(screen, c_color, coor_to_fill, dim);
	coor_to_fill.x = 0;
	coor_to_fill.y = screen->height / 2;
	dim.x = screen->width;
	dim.y = screen->height;
	ft_fill_img_with_color(screen, f_color, coor_to_fill, dim);
}

void	ft_create_screen(void *mlx_ptr, t_img_2 *screen, t_coord resol)
{
	screen->width = resol.x;
	screen->height = resol.y;
	screen->img_ptr = mlx_new_image(mlx_ptr, screen->width, screen->height);
	screen->mlx = mlx_get_data_addr(screen->img_ptr, &screen->bpp,
	&screen->size_line, &screen->endian);
}

void	ft_create_one_texture(void *mlx_ptr, t_img_2 *img, char *path)
{
	img->img_ptr = mlx_xpm_file_to_image(mlx_ptr, path, &img->width,
	&img->height);
	img->mlx =  mlx_get_data_addr(img->img_ptr, &(img->bpp), &(img->size_line),
	&(img->endian));
}

void	ft_create_texture(void *mlx_ptr, t_img_set *img_set, t_path_set path_set)
{
	ft_create_one_texture(mlx_ptr, &img_set->east, path_set.east);
	ft_create_one_texture(mlx_ptr, &img_set->north, path_set.north);
	ft_create_one_texture(mlx_ptr, &img_set->west, path_set.west);
	ft_create_one_texture(mlx_ptr, &img_set->south, path_set.south);
	ft_create_one_texture(mlx_ptr, &img_set->sprite, path_set.sprite);
}