/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cf_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:20:28 by abarot            #+#    #+#             */
/*   Updated: 2020/04/16 15:08:51 by abarot           ###   ########.fr       */
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

int		ft_check_col_value(t_color color, char *line, int i_line)
{
	if (color.r < 0 || color.b < 0 || color.g < 0 || color.r > 255
	|| color.g > 255 || color.b > 255 || line[i_line])
	{
		if (line[0] == 'C')
			return (C_COLOR_ERROR);
		else if (line[0] == 'F')
			return (F_COLOR_ERROR);
	}
	return (NO_ERROR);
}

int		ft_get_color(char *line, t_parse *parse, int error)
{
	int		i_line;
	t_color	color;
	char	*tmp_str;

	tmp_str = ft_remove_in_str(line, " ");
	i_line = 0;
	while (!ft_isdigit(tmp_str[i_line]) && tmp_str[i_line])
		i_line++;
	color.r = ft_atoi(tmp_str + i_line);
	while (ft_isdigit(tmp_str[i_line]))
		i_line++;
	(tmp_str[i_line] == ',') ? i_line++ : 0;
	color.g = ft_atoi((const char *)tmp_str + i_line);
	while (ft_isdigit(tmp_str[i_line]))
		i_line++;
	(tmp_str[i_line] == ',') ? i_line++ : 0;
	color.b = ft_atoi((const char *)tmp_str + i_line);
	while (ft_isdigit(tmp_str[i_line]))
		i_line++;
	if ((error = ft_check_col_value(color, tmp_str, i_line)))
		return (error);
	ft_fill_color(color, line[0], parse);
	free(tmp_str);
	return (error);
}
