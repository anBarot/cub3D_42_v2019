/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:58:10 by abarot            #+#    #+#             */
/*   Updated: 2019/11/28 18:40:29 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_check_map_content_and_size(char **map)
{
	size_t	size;
	int		i_line;
	int		i_col;
	int		nbr_player;

	nbr_player = 0;
	size = ft_strlen(map[0]);
	i_line = 0;
	i_col = 0;
	while (map[i_line])
	{
		if (ft_strlen(map[i_line]) != size)
			return (0);
		while (map[i_line][i_col])
		{
			if (ft_check_in_set_char(map[i_line][i_col], "012NEWS\0") == 0)
				return (0);
			(ft_check_in_set_char(map[i_line][i_col], "NEWS\0") == 1) ? nbr_player++ : 0;
			i_col++;
		}
		i_line++;
		i_col = 0;
	}
	if (nbr_player == 0 || nbr_player > 1)
		return (0);
	return (1);
}

int	ft_check_in_set_char(char to_test, char *dataset)
{
	int	i_dataset;

	i_dataset = 0;
	while (dataset[i_dataset] && dataset[i_dataset] != to_test)
		i_dataset++;
	if (dataset[i_dataset] == '\0')
		return (0);
	return (1);
}

int		ft_check_map_border(char **map)
{
	int		i_line;
	int		i_col;
	int		nbr_line;
	int		nbr_col;

	i_line = 0;
	i_col = 0;
	nbr_col = ft_strlen(map[0]) - 1;
	nbr_line = 0;
	while (map[nbr_line])
		nbr_line++;
	nbr_line--;
	while (i_col <= nbr_col)
	{
		if (map[0][i_col] != '1' || map[nbr_line][i_col] != '1')
			return (0);
		i_col++;
	}
	while (i_line <= nbr_line)
	{
		if (map[i_line][0] != '1' || map[i_line][nbr_col] != '1')
			return (0);
		i_line++;
	}
	return (1);
}
