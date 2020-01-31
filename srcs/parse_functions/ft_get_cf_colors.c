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

int		ft_check_color(char *str)
{
	int i_str;
	int	i_repetition;
	int tmp_col;

	i_repetition = 2;
	i_str = 0;
	tmp_col = ft_atoi(str);
	if (tmp_col < 0 || tmp_col > 255)
		return (0);
	while (i_repetition-- && str[i_str])
	{
		while (str[i_str] != ',')
			i_str++;
		tmp_col = ft_atoi(str + i_str++ + 1);
		if (tmp_col < 0 || tmp_col > 255)
			return (0);
	}
	while (ft_isdigit(str[i_str]))
		i_str++;
	if (str[i_str])
		return (0);
	return (1);
}

int		ft_get_color(char *line)
{
	int		col;
	char	*n_line;

	if (!ft_check_color(line + 2))
		return (0);
	n_line = ft_remove_in_str(line, " CF,");
	col = ft_atoi(n_line);
	return (col);
}
