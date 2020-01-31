/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lutoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 11:28:24 by abarot            #+#    #+#             */
/*   Updated: 2020/01/25 11:40:51 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_lutoa(long unsigned n)
{
	char			*res;
	int				i;

	if (!(res = (char*)ft_calloc(sizeof(char), 12)))
		return (0);
	i = 0;
	if (n == 0)
		res[i++] = 48;
	if (n > 4294967295)
		n = 4294967295;
	while (n >= 1)
	{
		res[i] = (n % 10) + 48;
		n = n / 10;
		i++;
	}
	return (ft_reverse_string(res));
}
