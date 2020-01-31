/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:14:54 by abarot            #+#    #+#             */
/*   Updated: 2019/10/18 16:30:36 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	char			*p;
	const char		*q;

	i = 0;
	p = (char *)dest;
	q = (const char *)src;
	while (i < n)
	{
		p[i] = q[i];
		i++;
	}
	return (dest);
}
