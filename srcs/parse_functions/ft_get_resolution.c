/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_resolution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:20:28 by abarot            #+#    #+#             */
/*   Updated: 2020/01/29 16:03:33 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


/* 
---------merge avec version maison-------

double		*ft_get_resolution(char *line)
{
	int 	i_line;
	double	*resol;

	i_line = 0;
	while (!ft_isdigit(line[i_line]))
		i_line++;
	resol[0] = ft_atoi(line + i_line);
	while (ft_isdigit(line[i_line]))
		i_line++;
	while (line[i_line] == ' ')
		i_line++;
	resol[1] = ft_atoi(line + i_line);
	if (resol[0] > RESOL_MAX_X)
		resol[0] = RESOL_MAX_X;
	if (resol[1] > RESOL_MAX_Y)
		resol[1] = RESOL_MAX_Y;
	if (resol[0] < 0 || resol[1] < 0)
		return (0);
	return (resol);
}

*/