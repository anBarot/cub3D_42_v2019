/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_char_in_set.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:38:02 by abarot            #+#    #+#             */
/*   Updated: 2020/01/31 12:15:53 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_char_in_set(char c, char *char_set)
{
	int	i_set;

	i_set = 0;
	if (!c)
		return (1);
	if (!char_set)
		return (0);
	while (char_set[i_set])
	{
		if (char_set[i_set] == c)
			return (1);
		else
			i_set++;
	}
	return (0);
}
