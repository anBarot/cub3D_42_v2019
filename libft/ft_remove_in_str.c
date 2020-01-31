/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_in_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:38:02 by abarot            #+#    #+#             */
/*   Updated: 2020/01/31 10:14:46 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*ft_remove_in_str(char *str, char *char_set)
{
	int		i_str;
	int		in_str;
	int		i_char_set;
	char	*n_str;

	in_str = 0;
	i_str = 0;
	i_char_set = 0;
	if (!(n_str = calloc(sizeof(char), strlen(str))) || !str || !char_set)
		return (0);
	while (str[i_str])
	{
		while (char_set[i_char_set] && str[i_str])
		{
			if (str[i_str] == char_set[i_char_set])
			{
				i_str++;
				i_char_set = 0;
			}
			else
				i_char_set++;
		}
		n_str[in_str] = str[i_str];
		if (str[i_str])
			i_str++;
		in_str++;
		i_char_set = 0;
	}
	return (n_str);
}
