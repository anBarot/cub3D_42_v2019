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

char	*ft_get_texture_path(char *line)
{
	char	*path;
	int 	fd;
	int		i_line;

	path = ft_remove_in_str(ft_strdup(line), " ");
	if ((fd = open(path, O_RDONLY)) == -1)
		return (0);
	close(fd);
	i_line = ft_strlen(line) - 1;
	while (line[i_line] != '.' && i_line)
		i_line--;
	if (ft_strncmp(line + i_line, ".jpg", 5) &&
		ft_strncmp(line + i_line, ".jpeg", 5) &&
		ft_strncmp(line + i_line, ".gif", 5) &&
		ft_strncmp(line + i_line, ".bmp", 5))
		return (0);
	else
		return (path);
}
