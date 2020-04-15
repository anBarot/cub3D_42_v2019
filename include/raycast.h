/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:35:04 by abarot            #+#    #+#             */
/*   Updated: 2020/04/15 10:28:37 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H
# include <math.h>
# include "libft.h"
# include "math_struct.h"
# define SQUARE_SIZE		64

typedef struct		s_raycast
{
	t_fcoord		p_coor;
	double			dist_obj;
	char			nesw_path;
}					t_raycast;
void				ft_initialyse_ray(t_raycast *ray);
void				ft_raycast(t_raycast *ray, char **map, double angle,
					char obj);
int					ft_outside_map(double x, double y, char **map);
double				ft_get_magnitude(t_fcoord in_coord, t_fcoord end_coord);
#endif
