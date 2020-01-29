/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:20:28 by abarot            #+#    #+#             */
/*   Updated: 2020/01/29 16:06:34 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		ft_is_valid_value_mapline(char *map_line);
{
	int i_str;

	i_str = 0;
	if (map_line[0] != '1' || map_line[ft_strlen(map_line) - 1] != '1')
		return (0);
	while (map_line[i_str])
	{
		if (!VALID_MAP_VALUE(map_line[i_str]))
			return (0);
		i_str++;
	}
	return (1);
}

void ft_get_map(t_config *config, char **line, int fd)
{
	int		map_line;
	int		line_width;

	map_line = 0;
	config->map[map_line] = ft_strdup(*line);
	line_width = ft_strlen(config->map[map_line]);
	map_line++;
	while (get_next_line(fd, line) == 1)
	{
		config->map[map_line] = ft_remove_in_str(ft_strdup(*line), ' ');
		if (!ft_is_valid_value_mapline(config->map[map_line]))
			config->error = MAP_VALUE_ERROR;
		if (map_line > 1000000 || ft_strlen(config->map[map_line]) != line_width)
			config->error = MAP_SIZE_ERROR;
		map_line++;
	}
	config->map[map_line] = ft_strdup(*line);
	if (map_line > 1000000 || ft_strlen(config->map[map_line]) != line_width)
		config->error = MAP_SIZE_ERROR;
}
