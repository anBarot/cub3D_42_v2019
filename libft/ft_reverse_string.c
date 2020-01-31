/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 11:26:21 by abarot            #+#    #+#             */
/*   Updated: 2020/01/25 12:57:17 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_reverse_string(char *s)
{
	int		start;
	int		end;
	char	tmp;

	if (!s)
		return (0);
	start = 0;
	if (s[0] == '-')
		start++;
	end = ft_strlen(s) - 1;
	tmp = 0;
	while (end > start)
	{
		tmp = s[start];
		s[start] = s[end];
		s[end] = tmp;
		end--;
		start++;
	}
	return (s);
}
