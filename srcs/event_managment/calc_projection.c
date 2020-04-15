/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_projection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 13:16:44 by abarot            #+#    #+#             */
/*   Updated: 2020/04/15 17:55:05 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_calc_projection(int d_obj, double agl, int cam_angle, int r_x)
{
	int			p_cst;
	double		ctr_agl;
	int			obj_proj;

	ctr_agl = cam_angle + (FOV / 2);
	if (ctr_agl > 360)
		ctr_agl -= 360;
	p_cst = ((WALL_SIZE / 2) * ((r_x / 2) / tan((M_PI / 180) *
	(FOV / 2)))) * WALL_RATIO;
	obj_proj = (p_cst / (d_obj * cos((M_PI / 180) * (fabs(ctr_agl - agl)))));
	return (obj_proj);
}
