/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 12:43:26 by abarot            #+#    #+#             */
/*   Updated: 2020/04/15 10:20:50 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_STRUCT_H
# define MATH_STRUCT_H
# include <math.h>

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;
typedef struct		s_fcoord
{
	double			x;
	double			y;
}					t_fcoord;
#endif
