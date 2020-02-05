/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_dist_to_wall.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 15:32:44 by abarot            #+#    #+#             */
/*   Updated: 2020/01/30 13:01:25 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	ft_calc_magnitude(double *in_coord, double *end_coord)
{
	double	magnitude;
	
	magnitude = sqrt((pow(end_coord[0] - in_coord[0], 2)) + (pow(end_coord[1] - in_coord[1], 2)));
	return (magnitude);
}

double	ft_get_distance_to_wall(t_config *config)
{






}

