/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cf_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:20:28 by abarot            #+#    #+#             */
/*   Updated: 2020/01/31 13:20:49 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "initialize.h"

void	ft_fill_color(t_color color, char cf, t_parse *parse)
{
	if (cf == 'C')
	{
		parse->col_ceil.R = color.R;
		parse->col_ceil.G = color.G;
		parse->col_ceil.B = color.B;
	}
	else
	{
		parse->col_floor.R = color.R;
		parse->col_floor.G = color.G;
		parse->col_floor.B = color.B;
	}
}

int		ft_get_color(char *line, t_parse *parse)
{
	int		i_line;
	t_color	color;

	i_line = 0;
	while (!ft_isdigit(line[i_line]) && line[i_line])
		i_line++;
	color.R = ft_atoi(line + i_line);
	while (ft_isdigit(line[i_line]))
		i_line++;
	(line[i_line] == ',') ? i_line++ : 0;
	color.G = ft_atoi((const char *)line + i_line);
	while (ft_isdigit(line[i_line]))
		i_line++;
	(line[i_line] == ',') ? i_line++ : 0;
	color.B = ft_atoi((const char *)line + i_line);
	while (ft_isdigit(line[i_line]))
		i_line++;
	while (line[i_line] == ' ' && i_line < 50 && line[i_line])
		i_line++;
	if (color.R < 0 || color.B < 0 || color.G < 0 || color.R > 255 
	|| color.G > 255 || color.B > 255 || line[i_line])
	{	
		if (line[0] == 'C')
			return (C_COLOR_ERROR);
		else if (line[0] == 'F')
			return (F_COLOR_ERROR);
	}
	ft_fill_color(color, line[0], parse);
	return (NO_ERROR);
}