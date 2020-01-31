/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llutoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 11:28:24 by abarot            #+#    #+#             */
/*   Updated: 2020/01/25 13:20:56 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_llutoa(unsigned long long n)
{
	char			*res;
	int				i;

	if (!(res = (char*)ft_calloc(sizeof(char), 21)))
		return (0);
	i = 0;
	if (!n)
		res[i++] = 48;
	while (n >= 1)
	{
		res[i] = (n % 10) + 48;
		n = n / 10;
		i++;
	}
	return (ft_reverse_string(res));
}
