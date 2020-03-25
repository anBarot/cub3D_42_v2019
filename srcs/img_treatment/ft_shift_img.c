#include "mlx_img_treatment.h"

t_img	ft_shift_img(void *mlx_ptr, t_img img, int x, int y)
{
	t_img	n_img;
	t_coord	img_coord;
	t_coord	n_img_coord;
	int		d_img;
	int		d_n_img;

	(x < 0) ? x = 0 : 0;
	(y < 0) ? y = 0 : 0;
	if (x >= img.width || y >= img.height)
	{	
		n_img.height = 0;
		return (n_img);
	}
	n_img.width = img.width - x;
	n_img.height = img.height - y;
	n_img.img_ptr = mlx_new_image(mlx_ptr, n_img.width, n_img.height);
	n_img.mlx = mlx_get_data_addr(n_img.img_ptr, &(n_img.bpp), &(n_img.size_line), &(n_img.endian));
	img_coord.x = x;
	n_img_coord.x = 0;
	img_coord.y = y;
	n_img_coord.y = 0;
	while (n_img_coord.y < n_img.height)
	{
		while (n_img_coord.x < n_img.width)
		{
			d_n_img = 4 * n_img_coord.x + n_img.size_line * n_img_coord.y;
			d_img = 4 * img_coord.x + img.size_line * img_coord.y;
			ft_pixel_filling(n_img.mlx + d_n_img, img.mlx + d_img);
			img_coord.x++;
			n_img_coord.x++;
		}
		img_coord.x = x;
		n_img_coord.x = 0;
		img_coord.y++;
		n_img_coord.y++;
	}
	return (n_img);
}