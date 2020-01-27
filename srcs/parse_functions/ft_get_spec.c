/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_spec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:20:28 by abarot            #+#    #+#             */
/*   Updated: 2020/01/27 19:05:38 by abarot           ###   ########.fr       */
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
	/*	test du parse :
	
	// printf("\ncol ceil : %d\ncol floor : %d\nresol : %fx%f\npaths : %s,%s,%s,%s,%s\n", spec->col_ceil, spec->col_floor, spec->resol[0],
	// 	spec->resol[1], spec->path_east, spec->path_north, spec->path_west, spec->path_south, spec->path_sprite);
	// printf("\ncoor : %d,%d,%c\ncam angle : %f\n", spec->map_player_coord[0], spec->map_player_coord[1], spec->dir, spec->cam_angle);
	// int i = 0;
	// while (spec->map[i])
	// {	
	// 	printf("map [%d]: %s\n", i, spec->map[i]);
	// 	i++;
	// }*/
	if (!spec->col_ceil || !spec->col_floor || !spec->resol
		|| spec->resol[0] > 2560 || spec->resol[1] > 1540 || !spec->path_north || 
		!spec->path_west || !spec->path_east || !spec->path_south || !spec->path_sprite
		|| (ft_check_map_content_and_size(spec->map) + ft_check_map_border(spec->map)) != 2)
		return (0);
	printf("\033[0;32m");
	printf("\n------specs are valid------\n");
	return (1);
}
