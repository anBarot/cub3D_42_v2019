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

#include "cub3D.h"

void	ft_fill_color(t_color color, char *line, char cf, t_config *config)
{
	char	*n_str;

	n_str = ft_remove_in_str(line, "CF, ");
	if (cf == 'C')
	{
		config->col_ceil.R = color.R;
		config->col_ceil.G = color.G;
		config->col_ceil.B = color.B;
		config->col_ceil.pix_put_col = ft_atoi((const char *)n_str);
	}
	else
	{
		config->col_floor.R = color.R;
		config->col_floor.G = color.G;
		config->col_floor.B = color.B;
		config->col_floor.pix_put_col = ft_atoi((const char *)n_str);
	}
	free(n_str);
}

void		ft_get_color(char *line, t_config *config)
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
		return ;
	ft_fill_color(color, line, line[0], config);
}
