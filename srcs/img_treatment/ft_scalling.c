/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scalling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:17:50 by abarot            #+#    #+#             */
/*   Updated: 2020/04/15 10:46:28 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_img_treatment.h"

void	ft_fill_image(t_img_2 img, t_img_2 img_scale, t_fcoord p_cste)
{
	t_coord		img_coord;
	int			d_fill;
	int			d_ext;

	img_coord.x = 0;
	img_coord.y = 0;
	while (img_coord.y < img.height)
	{
		while (img_coord.x < img.width)
		{
			d_fill = img_coord.x * 4 + img.size_line * img_coord.y;
			d_ext = ((int)((float)img_coord.x * p_cste.x) * 4) +
			(img_scale.size_line * (int)(p_cste.y * (float)img_coord.y));
			ft_pixel_filling(img.mlx + d_fill, img_scale.mlx + d_ext);
			img_coord.x++;
		}
		img_coord.x = 0;
		img_coord.y++;
	}
}

t_img_2	ft_scalling(void *mlx_ptr, t_img_2 img_to_scale, int width, int height)
{
	t_img_2		img;
	t_fcoord	prop_cste;

	img.width = width;
	img.height = height;
	prop_cste.x = (float)img_to_scale.width / (float)width;
	if (prop_cste.x < 0.000001)
		prop_cste.x = 0.000001;
	prop_cste.y = (float)img_to_scale.height / (float)height;
	if (prop_cste.y < 0.000001)
		prop_cste.y = 0.000001;
	img.img_ptr = mlx_new_image(mlx_ptr, img.width, img.height);
	img.mlx = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_line,
								&img.endian);
	ft_fill_image(img, img_to_scale, prop_cste);
	return (img);
}
