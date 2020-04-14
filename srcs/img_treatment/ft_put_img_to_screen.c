#include "mlx_img_treatment.h"


void	ft_init_img_coord(t_coord *img_c, t_coord *screen_c, int s_x, int s_y)
{
	img_c->x = 0;
	img_c->y = 0;
	if (s_x < 0) 
	{
		img_c->x = (-s_x);
		s_x = 0;
	}
	if (s_y < 0)
	{
		img_c->y = (-s_y);
		s_y = 0;
	}
	screen_c->x = s_x;
	screen_c->y = s_y;
}

void	ft_put_img_to_screen(t_img_2 screen, t_img_2 img, int start_x, int start_y)
{
	t_coord img_coor;
	t_coord screen_coor;
	int		i_screen;
	int		i_img;

	ft_init_img_coord(&img_coor, &screen_coor, start_x, start_y);
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
