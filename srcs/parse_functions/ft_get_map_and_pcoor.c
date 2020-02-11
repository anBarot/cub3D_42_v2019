/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:20:28 by abarot            #+#    #+#             */
/*   Updated: 2020/01/31 14:03:06 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double		ft_get_camangle(char dir)
{
	if (dir == 'N')
		return (60);
	else if (dir == 'W')
		return (330);
	else if (dir == 'S')
		return (240);
	else if (dir == 'E')
		return (150);
	return (0);
}

int		ft_get_player_coor(t_config *config)
{
	int		col;
	int 	line;
	int		count_player;

	line = 0;
	col = 0;
	count_player = 0;
	while (config->map[line])
	{
		while (config->map[line][col])
		{
			if (ft_is_char_in_set(config->map[line][col], "WESN"))
			{
				if (count_player == 1)
					return (MULTIPLAYER_ERROR);
				config->player_coord.x = line;
				config->player_coord.y = col;
				config->cam_angle = ft_get_camangle(config->map[line][col]);
				config->map[line][col] = '0';
				count_player++;
			}
			col++;
		}
		col = 0;
		line++;
	}
	if (count_player == 0)
		return (NO_PLAYER_ERROR);
	return (NO_ERROR);
}

int		ft_is_valid_value_mapline(char *map_line)
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

void	ft_get_map(t_config *config, char **line, int fd)
{
	int				map_line;
	unsigned int	line_width;

	map_line = 0;
	config->map[map_line] = ft_strdup(*line);
	line_width = ft_strlen(config->map[map_line]);
	map_line++;
	while (get_next_line(fd, line) == 1)
	{
		config->map[map_line] = ft_remove_in_str(ft_strdup(*line), " ");
		if (!ft_is_valid_value_mapline(config->map[map_line]) || 
			map_line > 1000000 || ft_strlen(config->map[map_line]) != line_width)
		{
			config->map = 0;
			return ;
		}
		map_line++;
	}
	config->map[map_line] = ft_strdup(*line);
	if (map_line > 1000000 || ft_strlen(config->map[map_line]) != line_width)
	{	
		config->map = 0;
		return ;
	}
}
