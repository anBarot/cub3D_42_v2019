/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_spec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:20:28 by abarot            #+#    #+#             */
/*   Updated: 2019/11/28 15:20:05 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		ft_get_spec(t_spec *spec, int fd)
{
	printf("\n-----entering get spec------\n");
	char	**line;
	int		res;

	if (!(line = (char **)malloc(sizeof(char *))))
		return (0);
	while ((res = get_next_line(fd, line)) == 1)
	{
		printf("\n*line : %s\n", *line);
		(line[0][0] == 'R' && line[0][1] == ' ') ? ft_get_res(spec->resol, *line) : 0;
		(line[0][0] == 'N' && line[0][1] == 'O' && line[0][2] == ' ') ?
				spec->path_north = ft_strdup(line[0] + 3) : 0;
		(line[0][0] == 'S' && line[0][1] == 'O' && line[0][2] == ' ') ?
				spec->path_south = ft_strdup(line[0] + 3) : 0;
		(line[0][0] == 'W' && line[0][1] == 'E' && line[0][2] == ' ') ?
				spec->path_west = ft_strdup(line[0] + 3) : 0;
		(line[0][0] == 'E' && line[0][1] == 'A' && line[0][2] == ' ') ?
				spec->path_east = ft_strdup(line[0] + 3) : 0;
		(line[0][0] == 'S' && line[0][1] == ' ') ? spec->path_sprite = ft_strdup(line[0] + 3) : 0;
		(line[0][0] == 'F' && line[0][1] == ' ') ? ft_get_col(spec->col_floor, *line) : 0;
		(line[0][0] == 'C' && line[0][1] == ' ') ? ft_get_col(spec->col_ceil, *line) : 0;
		(line[0][0] == '1') ? ft_get_map(spec->map, line, fd) : 0;
		free(*line);
	}
	close(fd);
	free(line);
	printf("\n------quitting get spec------\n");
	return (1);
}

void ft_get_map(char **map, char **line, int fd)
{
	printf("\n-----entering get map------\n");
	int		i_line;
	int		i_map;

	i_line = 0;
	i_map = 0;
	while (line[i_line])
	{
		map[i_map] = ft_strdup((const char *)line);
		i_map++;
		if ((get_next_line(fd, line)) == 0)
			break ;
	}
	printf("\n------quitting get map------\n");
}

void	ft_get_res(t_resol *resol, char *line)
{
	printf("\n-----entering get res------\n");
	int i_line;

	i_line = 0;
	while (!ft_isdigit(line[i_line]))
		i_line++;
	resol->x = ft_atoi(line + i_line);
	while (ft_isdigit(line[i_line]))
		i_line++;
	i_line++;
	resol->y = ft_atoi(line + i_line);
	printf("\nvalue of res : x = %d, y = %d\n", resol->x, resol->y);
	printf("\n------quitting get res------\n");
}

void	ft_get_col(t_col *col, char *line)
{
	printf("\n-----entering get col------\n");
	int i_line;

	i_line = 0;
	while (!ft_isdigit(line[i_line]))
		i_line++;
	col->R = ft_atoi(line + i_line);
	while (ft_isdigit(line[i_line]))
		i_line++;
	i_line++;
	col->G = ft_atoi(line + i_line);
	while (ft_isdigit(line[i_line]))
		i_line++;
	i_line++;
	col->B = ft_atoi(line + i_line);
	printf("\nvalue of colors : %d,%d,%d\n", col->R, col->G, col->B);
	printf("\n------quitting get col------\n");
}

int	ft_spec_isvalid(t_spec *spec)
{
	printf("-\n-----entering specis valid------\n");
	if (spec->resol->x == 0 || spec->resol->y == 0 || spec->resol->x > 2560 || spec->resol->y == 1540)
		return (0);
	if ((spec->col_ceil->R == spec->col_floor->R) && (spec->col_ceil->G == spec->col_floor->G)
	&& (spec->col_ceil->B == spec->col_floor->B))
		return (0);
	if ((spec->col_ceil->R > 255) && (spec->col_ceil->G > 255) && (spec->col_ceil->B > 255))
		return (0);
	if ((spec->col_floor->R > 255) && (spec->col_floor->G > 255) && (spec->col_floor->B > 255))
		return (0);
	if ( !spec->path_north || !spec->path_west || !spec->path_east || !spec->path_south || !spec->path_sprite)
		return (0);
	if ((ft_check_map_content_and_size(spec->map) + ft_check_map_border(spec->map)) != 2)
		return (0);
	return (1);
	printf("\n------quitting specis valid------\n");
}
