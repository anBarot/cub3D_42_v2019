/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:19:14 by abarot            #+#    #+#             */
/*   Updated: 2020/01/25 12:56:28 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_llitoa(long long n)
{
	char				*res;
	int					i;
	unsigned long long	nbr;

	if (!n)
		return (ft_char_to_str('0'));
	if (!(res = (char*)ft_calloc(sizeof(char), 21)))
		return (0);
	i = 0;
	nbr = n;
	if (n < 0)
	{
		res[i++] = '-';
		nbr = -n;
	}
	while (nbr >= 1)
	{
		res[i] = (nbr % 10) + 48;
		nbr = nbr / 10;
		i++;
	}
	return (ft_reverse_string(res));
}
