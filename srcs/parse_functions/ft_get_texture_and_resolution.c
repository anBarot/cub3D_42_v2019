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

#include "cub3D.h"

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

void		ft_get_resolution(t_config *config, char *line)
{
	int 	i_line;

	i_line = 0;
	if (!ft_is_valid_resolution(line))
		return ;
	while (!ft_isdigit(line[i_line]))
		i_line++;
	config->resol.x = ft_atoi(line + i_line);
	while (ft_isdigit(line[i_line]))
		i_line++;
	while (line[i_line] == ' ')
		i_line++;
	config->resol.y = ft_atoi(line + i_line);
	if (config->resol.x > RESOL_MAX_X)
		config->resol.x = RESOL_MAX_X;
	if (config->resol.y > RESOL_MAX_Y)
		config->resol.y = RESOL_MAX_Y;
}

char	*ft_get_texture_path(char *line)
{
	char	*path;
	int 	fd;
	int		i_line;

	path = ft_remove_in_str(line, " ");
	if ((fd = open(path, O_RDWR)) == -1)
		return (0);
	close(fd);
	i_line = ft_strlen(line) - 1;
	while (line[i_line] != '.' && i_line)
		i_line--;
	if (ft_strncmp(line + i_line, ".xpm", 4))
		return (0);
	else
		return (path);
}
