/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 17:36:54 by abarot            #+#    #+#             */
/*   Updated: 2020/04/19 11:48:10 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialize.h"

int		ft_check_adj(char **map, t_coord map_c, int dir)
{
	if (dir == UP || dir == DOWN)
		if (ft_is_empty(map[map_c.x][map_c.y + 1]) ||
			ft_is_empty(map[map_c.x][map_c.y - 1]))
			return (0);
	if (dir == LEFT || dir == RIGHT)
		if (ft_is_empty(map[map_c.x + 1][map_c.y]) ||
			ft_is_empty(map[map_c.x - 1][map_c.y]))
			return (0);
	return (1);
}

int		ft_advance_to_wall(char **map, t_coord map_c, int dir)
{
	if (dir == UP)
		while (map[map_c.x][map_c.y] && map[map_c.x][map_c.y] != '1'
		&& map[map_c.x][map_c.y] != ' ')
			map_c.x--;
	else if (dir == DOWN)
		while (map[map_c.x][map_c.y] && map[map_c.x][map_c.y] != '1'
		&& map[map_c.x][map_c.y])
			map_c.x++;
	else if (dir == LEFT)
		while (map[map_c.x][map_c.y] && map[map_c.x][map_c.y] != '1'
		&& map[map_c.x][map_c.y])
			map_c.y--;
	else if (dir == RIGHT)
		while (map[map_c.x][map_c.y] && map[map_c.x][map_c.y] != '1'
		&& map[map_c.x][map_c.y])
			map_c.y++;
	if (!(map[map_c.x][map_c.y]) || map[map_c.x][map_c.y] != '1' ||
		!(ft_check_adj(map, map_c, dir)))
		return (0);
	return (1);
}

int		ft_is_bordered(char **map, t_coord map_coor)
{
	if ((!(ft_advance_to_wall(map, map_coor, UP))) ||
	(!(ft_advance_to_wall(map, map_coor, DOWN))) ||
	(!(ft_advance_to_wall(map, map_coor, LEFT))) ||
	(!(ft_advance_to_wall(map, map_coor, RIGHT))))
		return (0);
	return (1);
}

int		ft_ckeck_map_border(char **map)
{
	t_coord	map_c;

	map_c.x = 0;
	map_c.y = 0;
	while (map[map_c.x])
	{
		while (map[map_c.x][map_c.y])
		{
			if (map[map_c.x][map_c.y] == '0' || map[map_c.x][map_c.y] == 'W'
			|| map[map_c.x][map_c.y] == 'E' || map[map_c.x][map_c.y] == 'S'
			|| map[map_c.x][map_c.y] == 'N' || map[map_c.x][map_c.y] == '2')
				if ((map_c.x != 0 &&
				map_c.y > (int)ft_strlen(map[map_c.x - 1]) - 2)
				|| (map_c.y > (int)ft_strlen(map[map_c.x + 1]))
				|| !(ft_is_bordered(map, map_c)))
					return (MAP_BORDER_ERROR);
			map_c.y++;
		}
		map_c.y = 0;
		map_c.x++;
	}
	return (NO_ERROR);
}

int		ft_check_map_value(char **map)
{
	int		line;
	char	*tmp_str;

	line = 1;
	tmp_str = ft_remove_in_str(map[0], " \t1");
	if (tmp_str && ft_strlen(tmp_str) != 0)
		return (MAP_BORDER_ERROR);
	free(tmp_str);
	while (map[line + 1])
	{
		tmp_str = ft_remove_in_str(map[line], " \t012WESN");
		if (ft_strlen(tmp_str) > 0)
			return (MAP_VALUE_ERROR);
		free(tmp_str);
		line++;
	}
	tmp_str = ft_remove_in_str(map[0], " 1");
	if (ft_strlen(tmp_str) > 0)
		return (MAP_BORDER_ERROR);
	(tmp_str) ? free(tmp_str) : 0;
	return (NO_ERROR);
}
