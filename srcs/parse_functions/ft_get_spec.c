/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:20:28 by abarot            #+#    #+#             */
/*   Updated: 2020/01/27 19:05:38 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		ft_get_config(t_config *config, int fd)
{
	char *line;
	
	while (get_next_line(fd, &line) == 1)
	{
		(line[0] == 'R' && line[1] == ' ') ? config->resol = ft_get_res(line) : 0;
		(line[0] == 'N' && line[1] == 'O' && line[2] == ' ') ?
				config->path_north = ft_strdup(line + 3) : 0;
		(line[0] == 'S' && line[1] == 'O' && line[2] == ' ') ?
				config->path_south = ft_strdup(line + 3) : 0;
		(line[0] == 'W' && line[1] == 'E' && line[2] == ' ') ?
				config->path_west = ft_strdup(line + 3) : 0;
		(line[0] == 'E' && line[1] == 'A' && line[2] == ' ') ?
				config->path_east = ft_strdup(line + 3) : 0;
		(line[0] == 'S' && line[1] == ' ') ? config->path_sprite = ft_strdup(line + 2) : 0;
		(line[0] == 'F' && line[1] == ' ') ? ft_get_col(line, config) : 0;
		(line[0] == 'C' && line[1] == ' ') ? ft_get_col(line, config) : 0;
		(line[0] == '1') ? ft_get_map(config, &line, fd) : 0;
	}

	/*	test du parse :
	
	// printf("\ncol ceil : %d\ncol floor : %d\nresol : %fx%f\npaths : %s,%s,%s,%s,%s\n", config->col_ceil, config->col_floor, config->resol[0],
	// 	config->resol[1], config->path_east, config->path_north, config->path_west, config->path_south, config->path_sprite);
	// printf("\ncoor : %d,%d,%c\ncam angle : %f\n", config->map_player_coord[0], config->map_player_coord[1], config->dir, config->cam_angle);
	// int i = 0;
	// while (config->map[i])
	// {	
	// 	printf("map [%d]: %s\n", i, config->map[i]);
	// 	i++;
	// }
	*/
	return (1);
}
