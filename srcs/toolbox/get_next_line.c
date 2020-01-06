/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:57:29 by abarot            #+#    #+#             */
/*   Updated: 2020/01/06 13:37:42 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
	(*to_keep) ? *line = ft_strjoinfree(to_keep, *line, 2) : 0;
	while (ft_hasnewline(*line) != 1)
	{
		read_value = read(fd, buffer_str, BUFFER_SIZE);
		*line = ft_strjoinfree(*line, buffer_str, 1);
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

char	*ft_strjoinfree(char *s1, char *s2, int var_free)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	printf("\ns1 : %s\ns2 : %s\n", s1, s2);
	if (!s1 || !s2 || !(res = (char *)malloc((ft_strlen(s1) + BUFFER_SIZE + 1) * sizeof(char))))
		return (0);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	if ((var_free == 1 && s1) || (var_free == 3 && s1))
		free(s1);
	if ((var_free == 2 && s2) || (var_free == 3 && s2))
		free(s2);
	return (res);
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

void	*ft_calloc(size_t num, size_t size)
{
	char			*dest;
	size_t			tot_size;
	unsigned int	i;

	i = 0;
	tot_size = num * size;
	if (tot_size == 0)
	{
		num = 1;
		size = 1;
	}
	if (!(dest = (char *)malloc(tot_size)))
		return (0);
	while (i < tot_size)
	{
		dest[i] = '\0';
		i++;
	}
	return ((void *)dest);
}