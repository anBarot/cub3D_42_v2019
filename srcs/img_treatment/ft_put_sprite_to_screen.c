/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_sprite_to_screen.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 16:09:58 by abarot            #+#    #+#             */
/*   Updated: 2020/04/14 16:12:32 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_img_treatment.h"

void	ft_init_coord_sprite(t_coord *sprite, t_coord *screen, int s_x, int s_y)
{
	sprite->x = 0;
	sprite->y = 0;
	screen->x = s_x;
	screen->y = s_y;
	if (s_x < 0)
	{
		sprite->x = (-s_x);
		s_x = 0;
	}
	if (s_y < 0)
	{
		sprite->y = (-s_y);
		s_y = 0;
	}
	screen->x = s_x;
	screen->y = s_y;
}

void	ft_put_sprite_to_screen(t_img_2 screen, t_img_2 sprite, int start_x,
								int start_y)
{
	t_coord	sprite_coor;
	t_coord	screen_coor;
	int		i_sprite;
	int		i_screen;

	ft_init_coord_sprite(&sprite_coor, &screen_coor, start_x, start_y);
	while (sprite_coor.y < sprite.height)
	{
		while (sprite_coor.x < sprite.width)
		{
			if ((sprite_coor.x + start_x) > screen.width)
				break ;
			i_sprite = sprite_coor.x * 4 + sprite_coor.y * sprite.size_line;
			i_screen = screen_coor.x * 4 + screen_coor.y * screen.size_line;
			if (sprite.mlx[i_sprite] >= 0)
				ft_pixel_filling(screen.mlx + i_screen, sprite.mlx + i_sprite);
			sprite_coor.x++;
			screen_coor.x++;
		}
		sprite_coor.x = 0;
		screen_coor.x = start_x;
		sprite_coor.y++;
		screen_coor.y++;
	}
}
