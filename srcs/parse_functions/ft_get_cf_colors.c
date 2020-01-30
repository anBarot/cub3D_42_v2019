/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cf_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:20:28 by abarot            #+#    #+#             */
/*   Updated: 2020/01/29 14:53:55 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

<<<<<<< HEAD
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
	while (!i_repetition--)
	{
		while (str[i_str] != ',')
			i_str++;
		tmp_col = ft_atoi(str + i_str + 1);
		if (tmp_col < 0 || tmp_col > 255)
			return (0);
	}
	while (ft_isdigit(str[i_str]))
		i_str++;
	if (str[i_str])
		return (0);
	return (1);
}

int		ft_get_color(t_config *config, char *line)
=======
int		ft_get_col(t_config * config, char *line)
>>>>>>> origin/cub3D_v2020_01_29
{
	int		col;

	line = ft_remove_in_str(line, " CF");
	if (!ft_check_color(line))
		return (FC_COLOR_ERROR);
	line = ft_remove_in_str(line, ",");
	col = ft_atoi(line);
	return (col);
}
