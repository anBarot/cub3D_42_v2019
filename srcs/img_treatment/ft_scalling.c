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

#include "mlx_img_treatment.h"

t_img	ft_scalling(void *mlx_ptr, t_img img_to_scale, int width, int height)
{
	t_img		img;
	t_fcoord	prop_cste;
	t_coord		img_coord;
	int delta_fill;
	int delta_extract;

	img_coord.x = 0;
	img_coord.y = 0;
	img.width = width;
	img.height = height;
	prop_cste.x = (float)img_to_scale.width / (float)width;
	if (prop_cste.x < 0.000001)
		prop_cste.x = 0.000001;
	prop_cste.y = (float)img_to_scale.height / (float)height; 
	if (prop_cste.y < 0.000001)
		prop_cste.y = 0.000001;
	img.img_ptr = mlx_new_image(mlx_ptr, img.width, img.height);
	img.mlx = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_line, &img.endian);
	while (img_coord.y < height)
	{
		while (img_coord.x < width)
		{
			delta_fill = img_coord.x * (img.bpp / 8) + img.size_line * img_coord.y;
			delta_extract = ((int)((float)img_coord.x * prop_cste.x) * (img.bpp / 8)) + (img_to_scale.size_line *(int)(prop_cste.y * (float)img_coord.y));
			ft_pixel_filling(img.mlx + delta_fill, img_to_scale.mlx + delta_extract);
			img_coord.x++;
		}
		img_coord.x = 0;
		img_coord.y++;
	}
	return (img);
}
