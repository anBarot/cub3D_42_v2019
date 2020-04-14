/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 17:36:54 by abarot            #+#    #+#             */
/*   Updated: 2020/04/14 17:58:44 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialize.h"

int		ft_ckeck_map_border(char **map)
{
	int		line;
	char	*tmp_str;

	line = 0;
	while (map[line])
	{
		tmp_str = ft_strtrim((const char *)map[line], " ");
		if (tmp_str[0] != '1' || tmp_str[ft_strlen(tmp_str) - 1] != '1')
			return (MAP_BORDER_ERROR);
		line++;
		free(tmp_str);
	}
	return (NO_ERROR);
}

int		ft_check_map_value(char **map)
{
	int		line;
	char	*tmp_str;

	line = 0;
	tmp_str = ft_remove_in_str(map[0], " 1");
	if (ft_strlen(tmp_str) > 0)
		return (MAP_BORDER_ERROR);
	free(tmp_str);
	line++;
	while (map[line + 1])
	{
		tmp_str = ft_remove_in_str(map[line], " 012WESN");
		if (ft_strlen(tmp_str) > 0)
			return (MAP_VALUE_ERROR);
		free(tmp_str);
		line++;
	}
	tmp_str = ft_remove_in_str(map[0], " 1");
	if (ft_strlen(tmp_str) > 0)
		return (MAP_BORDER_ERROR);
	free(tmp_str);
	return (NO_ERROR);
}
