/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:53:03 by abarot            #+#    #+#             */
/*   Updated: 2019/10/18 16:28:13 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	char		*s;
	char		*lasts;
	char		*lastd;

	d = (char *)dest;
	s = (char *)src;
	lasts = s + (n - 1);
	lastd = d + (n - 1);
	if (d < s)
		while (n--)
			*d++ = *s++;
	else
		while (n--)
			*lastd-- = *lasts--;
	return (dest);
}
