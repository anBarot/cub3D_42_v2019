/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_resolution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:20:28 by abarot            #+#    #+#             */
/*   Updated: 2020/01/31 11:19:16 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		ft_is_valid_resolution(char *line)
{
	int 	i_line;
	int		n_repet;

	i_line = 1;
	n_repet = 2;
	while (line[i_line] == ' ')
		i_line++;
	while(n_repet--)
	{
		while (ft_isdigit(line[i_line]))
			i_line++;
		while (line[i_line] == ' ')
		{
			i_line++;
			if (i_line == 30)
				return (0);
		}
	}
	if (line[i_line])
		return (0);
	return (1);
}

double		*ft_get_resolution(char *line)
{
	int 	i_line;
	double	*resol;

	i_line = 0;
	if (!ft_is_valid_resolution(line) || !(resol = (double *)ft_calloc(sizeof(double), 2)))
		return (0);
	while (!ft_isdigit(line[i_line]))
		i_line++;
	resol[0] = (double)ft_atoi(line + i_line);
	while (ft_isdigit(line[i_line]))
		i_line++;
	while (line[i_line] == ' ')
		i_line++;
	resol[1] = (double)ft_atoi(line + i_line);
	if (resol[0] > RESOL_MAX_X)
		resol[0] = RESOL_MAX_X;
	if (resol[1] > RESOL_MAX_Y)
		resol[1] = RESOL_MAX_Y;
	if (resol[0] < 0 || resol[1] < 0)
		return (0);
	return (resol);
}