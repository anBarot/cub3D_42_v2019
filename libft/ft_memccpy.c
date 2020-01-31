/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:44:55 by abarot            #+#    #+#             */
/*   Updated: 2019/10/18 10:09:09 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t		i;
	char		*p;
	const char	*q;

	i = 0;
	p = (char *)dest;
	q = (const char *)src;
	while (i < n)
	{
		p[i] = q[i];
		if (q[i] == c)
			return (dest + i + 1);
		i++;
	}
	return (0);
}
