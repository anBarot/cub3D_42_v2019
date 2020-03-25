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

#include "parse.h"
#include "initialize.h"

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

int		ft_get_player_coor(t_parse *parse)
{
	int		col;
	int 	line;
	int		count_player;

	line = 0;
	col = 0;
	count_player = 0;
	while (parse->map_elt.map[line])
	{
		while (parse->map_elt.map[line][col])
		{
			if (ft_is_char_in_set(parse->map_elt.map[line][col], "WESN"))
			{
				if (count_player)
					return (MULTIPLAYER_ERROR);
				parse->map_elt.p_coord.x = line;
				parse->map_elt.p_coord.y = col;
				parse->map_elt.cam_angle = ft_get_camangle(parse->map_elt.map[line][col]);
				parse->map_elt.map[line][col] = '0';
				count_player++;
			}
			col++;
		}
		col = 0;
		line++;
	}
	if (!count_player)
		return (NO_PLAYER_ERROR);
	return (NO_ERROR);
}

int	ft_ckeck_map_border(char **map)
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

int	ft_check_map_value(char **map)
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

int	ft_get_map(t_parse *parse, char **line, int fd)
{
	int		map_line;
	int		error_value;

	map_line = 0;
	parse->map_elt.map[map_line] = ft_strdup(*line);
	map_line++;
	error_value = 0;
	while (get_next_line(fd, line) == 1 && (**line == '1' || **line == ' '))
	{
		parse->map_elt.map[map_line] = ft_strdup(*line);
		if (map_line >= 1000000)
			return (MAP_OVERFLOW);
		map_line++;
		free(*line);
	}
	parse->map_elt.map[map_line] = ft_strdup(*line);
	free(*line);
	map_line++;
	parse->map_elt.map[map_line + 1] = '\0';
	if ((error_value = ft_check_map_value(parse->map_elt.map)))
		return (error_value);
	if ((error_value = ft_ckeck_map_border(parse->map_elt.map)))
		return (error_value);
	return (NO_ERROR);
}
