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

int	ft_check_missing_elt(t_config *config)
{
	int error_value;

	error_value = 0;
	(!(config->resol.x) || !(config->resol.y)) ? error_value = NO_RESOL_ERROR : 0;
	(config->col_ceil.R == -1) ? error_value = NO_C_COLOR_ERROR : 0;
	(config->col_floor.R == -1) ? error_value = NO_F_COLOR_ERROR : 0;
	(!(config->path_north)) ? error_value = NO_N_PATH_ERROR : 0;
	(!(config->path_west)) ? error_value = NO_W_PATH_ERROR : 0;
	(!(config->path_east)) ? error_value = NO_E_PATH_ERROR : 0;
	(!(config->path_south)) ? error_value = NO_SO_PATH_ERROR : 0;
	(!(config->path_sprite)) ? error_value = NO_SP_PATH_ERROR : 0;
	return (error_value);
}

int		ft_parse_file(int fd, t_config *config)
{
	char	*line;
	int		error_value;

	error_value = 0;
	while (get_next_line(fd, &line) == 1 && config->map && !error_value)
	{
		if (line[0] == 'R' && line[1] == ' ')
			error_value = ft_get_resolution(config, line);
		else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
			error_value = ft_get_texture_path(config, line);
		else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
			error_value = ft_get_texture_path(config, line);
		else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
			error_value = ft_get_texture_path(config, line);
		else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
			error_value = ft_get_texture_path(config, line);
		else if (line[0] == 'S' && line[1] == ' ')
			error_value = ft_get_texture_path(config, line);
		else if (line[0] == 'F' && line[1] == ' ')
			error_value = ft_get_color(line, config);
		else if (line[0] == 'C' && line[1] == ' ')
			error_value = ft_get_color(line, config);
		else
			break;
		free(line);
	}
	if (error_value)
		return (error_value);
	if (!(error_value = ft_check_missing_elt(config)))
		error_value = ft_get_map(config, &line, fd);
	return (error_value);
}

int		ft_init_parsing(t_config *config, char *cub_file)
{
	int		fd;
	int		error_value;

	error_value = NO_ERROR;
	if ((fd = open(cub_file, O_RDONLY)) == -1)
		return (OPEN_FILE_ERROR);
	if ((error_value = ft_parse_file(fd, config)))
		return (error_value);
	if ((error_value = ft_get_player_coor(config)))
		return (error_value);
	close(fd);
	return (error_value);
}
