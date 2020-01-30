/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:43:39 by abarot            #+#    #+#             */
/*   Updated: 2020/01/29 17:17:52 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		ft_parse_file(t_config *config, char *cub_file)
{
	char	*line;
	int		fd;
	
	if ((fd = open(cub_file, O_RDONLY)) == -1)
		return (OPEN_FILE_ERROR);
	while (get_next_line(fd, &line) == 1)
	{
		(line[0] == 'R' && line[1] == ' ') ?
				config->resol = ft_get_resolution(line) : 0;
		(line[0] == 'N' && line[1] == 'O' && line[2] == ' ') ?
				config->path_north = ft_get_texture_path(line + 3) : 0;
		(line[0] == 'S' && line[1] == 'O' && line[2] == ' ') ?
				config->path_south = ft_get_texture_path(line + 3) : 0;
		(line[0] == 'W' && line[1] == 'E' && line[2] == ' ') ?
				config->path_west = ft_get_texture_path(line + 3) : 0;
		(line[0] == 'E' && line[1] == 'A' && line[2] == ' ') ?
				config->path_east = ft_get_texture_path(line + 3) : 0;
		(line[0] == 'S' && line[1] == ' ') ?
				config->path_sprite = ft_get_texture_path(line + 2) : 0;


		/* 
		---------------merge avec version maison---------------------------
		(line[0] == 'F' && line[1] == ' ') ? config->col_floor = ft_get_col(line) : 0;
		(line[0] == 'C' && line[1] == ' ') ? config->col_ceil = ft_get_col(line) : 0;
		(line[0] == '1') ? ft_get_map(config, &line, fd) : 0;
		*/
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
	// }*/
	(!config->path_east) ? config->error = PATH_EAST_ERROR : 0;
	(!config->path_west) ? config->error = PATH_WEST_ERROR : 0;
	(!config->path_north) ? config->error = PATH_NORTH_ERROR : 0;
	(!config->path_south) ? config->error = PATH_SOUTH_ERROR : 0;
	(!config->path_sprite) ? config->error = PATH_SPRITE_ERROR : 0;
	if (config->error)
		return (config->error);
	printf("\033[0;32m");
	printf("\n------configs are valid------\n");
	return (1);
}
