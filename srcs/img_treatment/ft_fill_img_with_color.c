#include "mlx_img_treatment.h"

void	ft_fill_img_with_color(t_img_2 *img, t_color color, t_coord starting_point, t_coord dim)
{
	int		delta_img;
	char	*color_str;

	if (!(color_str = ft_calloc(4, 1)))
		return ;
	color_str[0] = color.b;
	color_str[1] = color.g;
	color_str[2] = color.r;
	while (starting_point.y < dim.y)
	{
		while (starting_point.x < dim.x)
		{
			delta_img = starting_point.x * 4 + img->size_line * starting_point.y;
			ft_pixel_filling(img->mlx + delta_img, color_str);
			starting_point.x++;
		}
		starting_point.x = 0;
		starting_point.y++;
	}
	free(color_str);
}
