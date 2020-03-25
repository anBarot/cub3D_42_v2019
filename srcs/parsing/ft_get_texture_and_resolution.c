/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_texture_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:46:29 by abarot            #+#    #+#             */
/*   Updated: 2020/01/31 13:29:42 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "initialize.h"

int		ft_is_valid_resolution(char *line)
{
	int 	i_line;
	int		n_repet;

	i_line = 1;
	n_repet = 2;
	while (line[i_line] == ' ')
		i_line++;
	while(n_repet--)
	{
		while (ft_isdigit(line[i_line]))
			i_line++;
		while (line[i_line] == ' ')
		{
			i_line++;
			if (i_line == 30)
				return (0);
		}
	}
	if (line[i_line])
		return (0);
	return (1);
}

int		ft_get_resolution(t_parse *parse, char *line)
{
	int 	i_line;

	i_line = 0;
	if (!ft_is_valid_resolution(line))
		return (RESOL_ERROR);
	while (!ft_isdigit(line[i_line]))
		i_line++;
	parse->resol.x = ft_atoi(line + i_line);
	while (ft_isdigit(line[i_line]))
		i_line++;
	while (line[i_line] == ' ')
		i_line++;
	parse->resol.y = ft_atoi(line + i_line);
	if (parse->resol.x > RESOL_MAX_X)
		parse->resol.x = RESOL_MAX_X;
	if (parse->resol.y > RESOL_MAX_Y)
		parse->resol.y = RESOL_MAX_Y;
	return (NO_ERROR);
}

int		ft_get_texture_path(t_parse *parse, char *line)
{
	char	*path;
	int 	fd;
	int		i_line;

	path = ft_remove_in_str(line + 2, " ");
	if ((fd = open(path, O_RDWR)) == -1)
		return (INVALID_PATH_ERROR);
	close(fd);
	i_line = ft_strlen(line) - 1;
	while (line[i_line] != '.' && i_line)
		i_line--;
	if (ft_strncmp(line + i_line, ".xpm", 4))
		return (IMG_EXTENSION_ERROR);
	if (line [0] == 'N')
		parse->path_set.north = path;
	else if (line [0] == 'W')
		parse->path_set.west = path;
	else if (line [0] == 'E')
		parse->path_set.east = path;
	else if (line [0] == 'S' && line[1] == 'O')
		parse->path_set.south = path;
	else if (line [0] == 'S')
		parse->path_set.sprite = path;
	return (NO_ERROR);
}
