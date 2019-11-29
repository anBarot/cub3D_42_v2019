/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:57:29 by abarot            #+#    #+#             */
/*   Updated: 2019/11/29 13:50:58 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int		get_next_line(int fd, char **line)
{
	char		*buffer_str;
	static char to_keep[BUFFER_SIZE + 1];
	int			read_value;

	read_value = BUFFER_SIZE;
	if (!(buffer_str = (char *)malloc(sizeof(char) * read_value + 1)) ||
	!(*line = (char *)malloc(sizeof(char) * 1)))
		return (-1);
	if (fd < 0 || !read_value || !line)
		return (-1);
	(*to_keep) ? *line = ft_strcat(to_keep, *line, read_value, 2) : 0;
	while (ft_hasnewline(*line) != 1)
	{
		if ((read_value = read(fd, buffer_str, BUFFER_SIZE)) < 0)
		{	
			free(buffer_str);
			return (-1);
		}
		*line = ft_strcat(*line, buffer_str, read_value, 1);
		if (read_value < BUFFER_SIZE && ft_hasnewline(*line) != 1)
		{
			free(buffer_str);
			return (0);
		}
	}
	ft_createkeep(to_keep, *line);
	free(buffer_str);
	return (1);
}

void	ft_createkeep(char *keep, char *line)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (line[i] != '\n')
		i++;
	line[i] = '\0';
	if (line[i + 1])
		i++;
	while (line[i + j])
	{
		keep[j] = line[i + j];
		j++;
	}
	keep[j] = '\0';
}

int		ft_hasnewline(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
