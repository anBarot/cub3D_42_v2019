/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:15:09 by abarot            #+#    #+#             */
/*   Updated: 2019/10/18 16:31:01 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *p, int c, size_t n)
{
	size_t		i;
	char		*b;

	b = (char *)p;
	i = 0;
	while (i < n)
	{
		b[i] = c;
		i++;
	}
	return (p);
}
