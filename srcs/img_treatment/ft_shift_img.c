#include "mlx_img_treatment.h"

t_img_2	ft_shift_img(void *mlx_ptr, t_img_2 img, int x, int y)
{
	t_img_2	n_img;
	t_coord	img_coord;
	t_coord img_coord_start;
	t_coord	n_img_coord;
	int		d_img;
	int		d_n_img;

	if (x >= img.width || y >= img.height)
	{	
		n_img.height = 0;
		return (n_img);
	}
	n_img.width = img.width - abs(x);
	n_img.height = img.height - abs(y);
	n_img.img_ptr = mlx_new_image(mlx_ptr, n_img.width, n_img.height);
	n_img.mlx = mlx_get_data_addr(n_img.img_ptr, &(n_img.bpp), &(n_img.size_line), &(n_img.endian));
	if (x > 0)
		img_coord_start.x = x;
	else
		img_coord_start.x = 0;
	img_coord.x = img_coord_start.x;
	n_img_coord.x = 0;
	if (y > 0)
		img_coord_start.y = y;
	else
		img_coord_start.y = 0;
	n_img_coord.y = 0;
	img_coord.y = img_coord_start.y;
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
		img_coord.x = img_coord_start.x;
		n_img_coord.x = 0;
		img_coord.y++;
		n_img_coord.y++;
	}
	return (n_img);
}