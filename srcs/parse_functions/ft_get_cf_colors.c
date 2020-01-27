/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cf_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:20:28 by abarot            #+#    #+#             */
/*   Updated: 2020/01/27 19:16:00 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		ft_get_col(t_spec * spec, char *line)
{
	int		i_line;
	char	*color;
	int		i_color;
	int		col;

	line = ft_remove_in_str(line, " CF");
	col = ft_atoi(line);
	/* gerer erreurs col : >255 pour chaque  RGB*/
	if (ft_atoi(color) < 0 || ft_atoi(color) > 255255255)
		return (0);
	col = ft_atoi(color);
	free(color);
	return (col);
}
