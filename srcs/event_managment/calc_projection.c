/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_projection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 13:16:44 by abarot            #+#    #+#             */
/*   Updated: 2020/04/15 12:32:51 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_calc_projection(int d_obj, double tmp_angle, int cam_angle, int resol_x)
{
	int			prop_cste;
	double		center_angle;
	int			obj_proj;

	center_angle = cam_angle + (FOV / 2);
	if (center_angle > 360)
		center_angle -= 360;
	prop_cste = ((WALL_SIZE / 2) * ((resol_x / 2) / tan((M_PI / 180) * (FOV / 2)))) * WALL_RATIO;
	obj_proj = (prop_cste / (d_obj * cos((M_PI / 180) * (fabs(center_angle - tmp_angle)))));
	return (obj_proj);
}
