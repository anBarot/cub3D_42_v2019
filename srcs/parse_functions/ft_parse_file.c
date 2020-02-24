/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:43:39 by abarot            #+#    #+#             */
/*   Updated: 2020/01/31 14:09:38 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		ft_is_config_valid(t_config *config)
{
	int		error_value;

	error_value = NO_ERROR;
	(!config->path_east) ? error_value = E_PATH_ERROR : 0;
	(!config->path_west) ? error_value = W_PATH_ERROR : 0;
	(!config->path_north) ? error_value = N_PATH_ERROR : 0;
	(!config->path_south) ? error_value = SO_PATH_ERROR : 0;
	(!config->path_sprite) ? error_value = SP_PATH_ERROR : 0;
	(config->col_ceil.R == -1) ? error_value = C_COLOR_ERROR : 0;
	(config->col_floor.R == -1) ? error_value = F_COLOR_ERROR : 0;
	(!config->resol.x) ? error_value = RESOL_ERROR : 0;
	(!config->resol.y) ? error_value = RESOL_ERROR : 0;
	(!config->map) ? error_value = MAP_ERROR : 0;
	return (error_value);
}


void	ft_parse_file(int fd, t_config *config)
{
	char	*line;

	while (get_next_line(fd, &line) == 1 && config->map)
	{
		(line[0] == 'R' && line[1] == ' ') ?
			ft_get_resolution(config, line) : 0;
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
		(line[0] == 'F' && line[1] == ' ') ? ft_get_color(line, config) : 0;
		(line[0] == 'C' && line[1] == ' ') ? ft_get_color(line, config) : 0;
		(line[0] == '1') ? ft_get_map(config, &line, fd) : 0;
		free(line);
	}
}

int		ft_init_parsing(t_config *config, char *cub_file)
{
	int		fd;
	int		error_value;

	error_value = 0;
	if ((fd = open(cub_file, O_RDONLY)) == -1)
		return (OPEN_FILE_ERROR);
	ft_parse_file(fd, config);
	if (!config->map)
		return (error_value = MAP_ERROR);
	if ((error_value = ft_get_player_coor(config)))
		return (error_value);
	close(fd);
	return (ft_is_config_valid(config));
}
