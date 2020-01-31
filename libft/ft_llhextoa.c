/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llhextoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 11:25:46 by abarot            #+#    #+#             */
/*   Updated: 2020/01/25 13:46:30 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_llhextoa(long long unsigned n)
{
	char	*res;
	int		i;
	char	*hexchar;

	hexchar = "0123456789abcdef";
	if (!(res = (char*)calloc(sizeof(char), 21)))
		return (0);
	i = 0;
	if (n == 0)
		res[i++] = 48;
	while (n >= 1)
	{
		res[i] = hexchar[(n % 16)];
		n = n / 16;
		i++;
	}
	res[i] = '\0';
	return (ft_reverse_string(res));
}
