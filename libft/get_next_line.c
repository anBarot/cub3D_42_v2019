/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:57:29 by abarot            #+#    #+#             */
/*   Updated: 2020/01/31 10:38:32 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

int		get_next_line(int fd, char **line)
{
	char		*buffer_str;
	static char to_keep[BUFFER_SIZE + 1];
	int			read_value;

	if (!(buffer_str = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1)) ||
	!(*line = (char *)ft_calloc(sizeof(char), 1)))
		return (-1);
	if (fd < 0 || !BUFFER_SIZE || !line)
		return (-1);
	(*to_keep) ? *line = ft_strjoin(to_keep, *line, 2) : 0;
	while (ft_hasnewline(*line) != 1)
	{
		read_value = read(fd, buffer_str, BUFFER_SIZE);
		*line = ft_strjoin(*line, buffer_str, 1);
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
