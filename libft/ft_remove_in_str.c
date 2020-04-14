/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_in_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:38:02 by abarot            #+#    #+#             */
/*   Updated: 2020/04/14 13:14:48 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_check_in_charset(char c, char *char_set)
{
	int i_char_set;

	i_char_set = 0;
	while (char_set[i_char_set])
	{
		if (c == char_set[i_char_set])
		{
			i_char_set = 0;
			return (1);
		}
		else
			i_char_set++;
	}
	return (0);
}

char	*ft_remove_in_str(char *str, char *char_set)
{
	int		i_str;
	int		in_str;
	char	*n_str;

	in_str = 0;
	i_str = 0;
	if (!(n_str = calloc(sizeof(char), strlen(str) + 1)) || !str || !char_set)
		return (0);
	while (str[i_str])
	{
		if (ft_check_in_charset(str[i_str], char_set) == 1)
			i_str++;
		else
		{
			n_str[in_str] = str[i_str];
			in_str++;
			i_str++;
		}
	}
	n_str[in_str] = '\0';
	return (n_str);
}
