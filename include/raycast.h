/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:35:04 by abarot            #+#    #+#             */
/*   Updated: 2020/01/31 15:10:11 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H
# include <math.h>
# include "libft.h"
# include "math_struct.h"
# ifndef SQUARE_SIZE
#  define SQUARE_SIZE			64
# endif

typedef struct		s_raycast
{
	t_fcoord		p_coor;
	double			dist_obj;
	char			nesw_path;
}					t_raycast;
void		ft_initialyse_ray(t_raycast *ray);
void		ft_raycast(t_raycast *ray, char **map, double angle, char obj);
#endif