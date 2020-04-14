/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cf_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:20:28 by abarot            #+#    #+#             */
/*   Updated: 2020/04/14 12:49:14 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "initialize.h"

void	ft_fill_color(t_color color, char cf, t_parse *parse)
{
	if (cf == 'C')
	{
		parse->col_ceil.r = color.r;
		parse->col_ceil.g = color.g;
		parse->col_ceil.b = color.b;
	}
	else
	{
		parse->col_floor.r = color.r;
		parse->col_floor.g = color.g;
		parse->col_floor.b = color.b;
	}
}

int		ft_get_color(char *line, t_parse *parse)
{
	int		i_line;
	t_color	color;

	i_line = 0;
	while (!ft_isdigit(line[i_line]) && line[i_line])
		i_line++;
	color.r = ft_atoi(line + i_line);
	while (ft_isdigit(line[i_line]))
		i_line++;
	(line[i_line] == ',') ? i_line++ : 0;
	color.g = ft_atoi((const char *)line + i_line);
	while (ft_isdigit(line[i_line]))
		i_line++;
	(line[i_line] == ',') ? i_line++ : 0;
	color.b = ft_atoi((const char *)line + i_line);
	while (ft_isdigit(line[i_line]))
		i_line++;
	while (line[i_line] == ' ' && i_line < 50 && line[i_line])
		i_line++;
	if (color.r < 0 || color.b < 0 || color.g < 0 || color.r > 255 
	|| color.g > 255 || color.b > 255 || line[i_line])
	{	
		if (line[0] == 'C')
			return (C_COLOR_ERROR);
		else if (line[0] == 'F')
			return (F_COLOR_ERROR);
	}
	ft_fill_color(color, line[0], parse);
	return (NO_ERROR);
}
