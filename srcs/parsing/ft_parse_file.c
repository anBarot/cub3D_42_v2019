/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:43:39 by abarot            #+#    #+#             */
/*   Updated: 2020/04/14 17:59:32 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "initialize.h"

int		ft_check_missing_elt(t_parse parse)
{
	int error_value;

	error_value = 0;
	(!(parse.resol.x) || !(parse.resol.y)) ? error_value = NO_RESOL_ERROR : 0;
	(parse.col_ceil.r == -1) ? error_value = NO_C_COLOR_ERROR : 0;
	(parse.col_floor.r == -1) ? error_value = NO_F_COLOR_ERROR : 0;
	(!(parse.path_set.north)) ? error_value = NO_N_PATH_ERROR : 0;
	(!(parse.path_set.west)) ? error_value = NO_W_PATH_ERROR : 0;
	(!(parse.path_set.east)) ? error_value = NO_E_PATH_ERROR : 0;
	(!(parse.path_set.south)) ? error_value = NO_SO_PATH_ERROR : 0;
	(!(parse.path_set.sprite)) ? error_value = NO_SP_PATH_ERROR : 0;
	return (error_value);
}

void	ft_parse_condition(char *line, t_parse *parse, char *tmp,
							int *error_value)
{
	if (line[0] == 'R' && line[1] == ' ')
		*error_value = ft_get_resolution(parse, line);
	else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		*error_value = ft_get_texture_path(parse, line);
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		*error_value = ft_get_texture_path(parse, line);
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		*error_value = ft_get_texture_path(parse, line);
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		*error_value = ft_get_texture_path(parse, line);
	else if (line[0] == 'S' && line[1] == ' ')
		*error_value = ft_get_texture_path(parse, line);
	else if (line[0] == 'F' && line[1] == ' ')
		*error_value = ft_get_color(line, parse);
	else if (line[0] == 'C' && line[1] == ' ')
		*error_value = ft_get_color(line, parse);
	else if (tmp[0] != '1' && tmp[0] != '\0')
		*error_value = BAD_LINE_ERROR;
}

int		ft_parse_file(int fd, t_parse *parse)
{
	char	*line;
	char	*tmp;
	int		error_value;

	error_value = 0;
	while (get_next_line(fd, &line) == 1 && !error_value)
	{
		tmp = ft_strtrim(line, " ");
		ft_parse_condition(line, parse, tmp, &error_value);
		if (tmp[0] == '1')
		{
			free(tmp);
			break ;
		}
		free(tmp);
		free(line);
	}
	if (error_value)
		return (error_value);
	if (!(error_value = ft_check_missing_elt(*parse)))
		error_value = ft_get_map(parse, &line, fd);
	return (error_value);
}

int		ft_init_parsing(t_parse *parse, char *cub_file)
{
	int		fd;
	int		error_value;

	error_value = NO_ERROR;
	if ((fd = open(cub_file, O_RDONLY)) == -1)
		return (OPEN_FILE_ERROR);
	if ((error_value = ft_parse_file(fd, parse)))
		return (error_value);
	if ((error_value = ft_get_player_coor(parse)))
		return (error_value);
	close(fd);
	return (error_value);
}
