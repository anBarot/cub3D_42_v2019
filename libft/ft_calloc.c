/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:22:59 by abarot            #+#    #+#             */
/*   Updated: 2019/10/18 14:45:30 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void *dest;

	if (num * size == 0)
	{
		num = 1;
		size = 1;
	}
	dest = malloc(num * size);
	if (dest == 0)
		return (0);
	ft_bzero(dest, (size * num));
	return (dest);
}
