/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_spec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:20:28 by abarot            #+#    #+#             */
/*   Updated: 2019/12/11 18:53:06 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		ft_get_spec(t_spec *spec, int fd)
{
	char *line;
	
	while (get_next_line(fd, &line) == 1)
	{
		(line[0] == 'R' && line[1] == ' ') ? spec->resol = ft_get_res(line) : 0;
		(line[0] == 'N' && line[1] == 'O' && line[2] == ' ') ?
				spec->path_north = ft_strdup(line + 3) : 0;
		(line[0] == 'S' && line[1] == 'O' && line[2] == ' ') ?
				spec->path_south = ft_strdup(line + 3) : 0;
		(line[0] == 'W' && line[1] == 'E' && line[2] == ' ') ?
				spec->path_west = ft_strdup(line + 3) : 0;
		(line[0] == 'E' && line[1] == 'A' && line[2] == ' ') ?
				spec->path_east = ft_strdup(line + 3) : 0;
		(line[0] == 'S' && line[1] == ' ') ? spec->path_sprite = ft_strdup(line + 2) : 0;
		(line[0] == 'F' && line[1] == ' ') ? spec->col_floor = ft_get_col(line) : 0;
		(line[0] == 'C' && line[1] == ' ') ? spec->col_ceil = ft_get_col(line) : 0;
		(line[0] == '1') ? ft_get_map(spec, &line, fd) : 0;
	}
	if (ft_get_coord(spec) == 0)
		return (0);
	printf("\ncol ceil : %d\ncol floor : %d\nresol : %dx%d\npaths : %s,%s,%s,%s,%s\n", *spec->col_ceil, *spec->col_floor, spec->resol[0],
		spec->resol[1], spec->path_east, spec->path_north, spec->path_west, spec->path_south, spec->path_sprite);
	printf("\ncoor : %d,%d,%c\nmap :\n%s\n%s\n%s\n%s\n", spec->coord_player[0], spec->coord_player[1], spec->dir[0], spec->map[0], spec->map[1], spec->map[2], spec->map[3]);
	if (!spec->col_ceil || !spec->col_floor || !spec->resol
		|| spec->resol[0] > 2560 || spec->resol[1] > 1540 || !spec->path_north || 
		!spec->path_west || !spec->path_east || !spec->path_south || !spec->path_sprite
		|| (ft_check_map_content_and_size(spec->map) + ft_check_map_border(spec->map)) != 2)
		return (0);
	printf("\033[0;32m");
	printf("\n------specs are valid------\n");
	return (1);
}

int		ft_get_coord(t_spec *spec)
{
	int	col;
	int line;

	if (!(spec->dir = (char *)ft_calloc(2, sizeof(char))) || 
	!(spec->coord_player = (int *)ft_calloc(2, sizeof(int))))
		return (0);
	line = 0;
	col = 0;
	while (spec->map[line])
	{
		while (spec->map[line][col])
		{
			if (ft_check_in_set_char(spec->map[line][col], "WESN"))
			{
				spec->coord_player[0] = line;
				spec->coord_player[1] = col;
				spec->dir[0] = spec->map[line][col];
				spec->map[line][col] = '0';
				return (1);
			}
			col++;
		}
		col = 0;
		line++;
	}
	return (0);
}

void ft_get_map(t_spec *spec, char **line, int fd)
{
	int		map_line;

	if (!(spec->map = (char **)ft_calloc(1000000, sizeof(char *))))
		return ;
	map_line = 0;
	spec->map[map_line] = ft_strdup(*line);
	map_line++;
	while (get_next_line(fd, line) == 1)
	{
		spec->map[map_line] = ft_strdup(*line);
		map_line++;
	}
	spec->map[map_line] = ft_strdup(*line);
}

int		*ft_get_res(char *line)
{
	int i_line;
	int	*resol;

	if (!(resol = (int *)ft_calloc(2, sizeof(int))))
		return (0);
	i_line = 0;
	while (!ft_isdigit(line[i_line]))
		i_line++;
	resol[0] = ft_atoi(line + i_line);
	while (ft_isdigit(line[i_line]))
		i_line++;
	i_line++;
	resol[1] = ft_atoi(line + i_line);
	return (resol);
}

int		*ft_get_col(char *line)
{
	int 	i_line;
	char	*color;
	int		i_color;
	int		*col;

	if (!(color = (char *)ft_calloc(10, sizeof(char))) || !(col = (int *)ft_calloc(1, sizeof(int))))
		return (0);
	i_color = 0;
	i_line = 2;
	while(line[i_line])
	{
		while (ft_isdigit(line[i_line]) == 0 && line[i_line])
			i_line++;
		while (ft_isdigit(line[i_line]) == 1 && line[i_line])
		{	
			color[i_color++] = line[i_line++];
		}
	}
	if (ft_atoi(color) < 0 || ft_atoi(color) > 255255255)
		return (0);
	*col = ft_atoi(color);
	return (col);
}
