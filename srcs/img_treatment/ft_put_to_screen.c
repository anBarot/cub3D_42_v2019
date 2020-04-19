/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_to_screen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 14:27:46 by abarot            #+#    #+#             */
/*   Updated: 2020/04/19 10:19:18 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_img_treatment.h"

void	ft_init_img_coord(t_coord *img_c, t_coord *screen_c, int s_x, int s_y)
{
	img_c->x = 0;
	img_c->y = 0;
	screen_c->x = s_x;
	screen_c->y = s_y;
	if (s_x < 0)
	{
		img_c->x = -(s_x);
		screen_c->x = 0;
	}
	if (s_y < 0)
	{
		img_c->y = -(s_y);
		screen_c->y = 0;
	}
}

void	ft_reset_coor_putscreen(t_coord *img_coor, t_coord *scr_c, int start_x)
{
	if (start_x < 0)
	{
		img_coor->x = -start_x;
		scr_c->x = 0;
	}
	else
	{
		img_coor->x = 0;
		scr_c->x = start_x;
	}
	img_coor->y = img_coor->y + 1;
	scr_c->y = scr_c->y + 1;
}

void	ft_put_sprite_to_screen(t_img screen, t_img sprite, int start_x,
								int start_y)
{
	t_coord	sprite_coor;
	t_coord	screen_coor;
	int		i_sprite;
	int		i_screen;

	ft_init_img_coord(&sprite_coor, &screen_coor, start_x, start_y);
	while (sprite_coor.y < sprite.height && screen_coor.y < screen.height)
	{
		while (sprite_coor.x < sprite.width && screen_coor.x < screen.width)
		{
			if ((sprite_coor.x + start_x) > screen.width)
				break ;
			i_sprite = sprite_coor.x * 4 + sprite_coor.y * sprite.size_line;
			i_screen = screen_coor.x * 4 + screen_coor.y * screen.size_line;
			if (sprite.mlx[i_sprite] != sprite.mlx[0])
				ft_pixel_filling(screen.mlx + i_screen, sprite.mlx + i_sprite);
			sprite_coor.x++;
			screen_coor.x++;
		}
		ft_reset_coor_putscreen(&sprite_coor, &screen_coor, start_x);
	}
}

void	ft_put_img_to_screen(t_img screen, t_img img, int start_x,
							int start_y)
{
	t_coord img_coor;
	t_coord screen_coor;
	int		i_screen;
	int		i_img;

	ft_init_img_coord(&img_coor, &screen_coor, start_x, start_y);
	while (img_coor.y < img.height && screen_coor.y < screen.height)
	{
		while (img_coor.x < img.width && screen_coor.x < screen.width)
		{
			i_screen = screen_coor.x * 4 + screen_coor.y * screen.size_line;
			i_img = img_coor.x * 4 + img_coor.y * img.size_line;
			ft_pixel_filling(screen.mlx + i_screen, img.mlx + i_img);
			img_coor.x++;
			screen_coor.x++;
		}
		ft_reset_coor_putscreen(&img_coor, &screen_coor, start_x);
		if (img_coor.y > img.height)
			img_coor.y = 0;
	}
}
