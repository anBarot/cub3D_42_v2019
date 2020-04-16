/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_and_pcoor.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:20:28 by abarot            #+#    #+#             */
/*   Updated: 2020/04/16 16:21:33 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "initialize.h"

double	ft_get_camangle(char dir)
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

void	ft_fill_player_info(t_map *map_elt, int *count_player, int line,
							int col)
{
	map_elt->p_coord.x = line;
	map_elt->p_coord.y = col;
	map_elt->cam_angle = ft_get_camangle(map_elt->map[line][col]);
	map_elt->map[line][col] = '0';
	*count_player = *count_player + 1;
}

int		ft_get_player_coor(t_map *map_elt)
{
	int		col;
	int		line;
	int		count_player;

	line = 0;
	col = 0;
	count_player = 0;
	while (map_elt->map[line])
	{
		while (map_elt->map[line][col])
		{
			if (ft_is_char_in_set(map_elt->map[line][col], "WESN"))
			{
				if (count_player)
					return (MULTIPLAYER_ERROR);
				ft_fill_player_info(map_elt, &count_player, line, col);
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

int		ft_get_map(t_map *map_elt, char **line, int fd)
{
	int		map_line;
	int		error_value;

	map_line = 0;
	map_elt->map[map_line] = ft_strdup(*line);
	map_line++;
	error_value = 0;
	while (get_next_line(fd, line) == 1)
	{
		map_elt->map[map_line] = ft_strdup(*line);
		if (map_line >= 1000000)
			return (MAP_OVERFLOW);
		map_line++;
		free(*line);
	}
	map_elt->map[map_line] = ft_strdup(*line);
	free(*line);
	map_line++;
	map_elt->map[map_line + 1] = '\0';
	if ((error_value = ft_check_map_value(map_elt->map)))
		return (error_value);
	if ((error_value = ft_ckeck_map_border(map_elt->map)))
		return (error_value);
	return (NO_ERROR);
}
