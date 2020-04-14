/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 16:40:46 by abarot            #+#    #+#             */
/*   Updated: 2020/04/14 16:43:57 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_img_treatment.h"

void	ft_draw_square(t_img_2 *img, t_color color, t_coord start, t_coord dim)
{
	int		d_img;
	char	*color_str;

	if (!(color_str = ft_calloc(4, 1)))
		return ;
	color_str[0] = color.b;
	color_str[1] = color.g;
	color_str[2] = color.r;
	while (start.y < dim.y)
	{
		while (start.x < dim.x)
		{
			d_img = start.x * 4 + img->size_line * start.y;
			ft_pixel_filling(img->mlx + d_img, color_str);
			start.x++;
		}
		start.x = 0;
		start.y++;
	}
	free(color_str);
}
