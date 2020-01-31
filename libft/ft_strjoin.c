/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:48:55 by abarot            #+#    #+#             */
/*   Updated: 2020/01/31 10:35:36 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2, int to_free)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(res = (char *)ft_calloc((ft_strlen((char *)s1) +
	ft_strlen((char *)s2) + 1), sizeof(char))) || !s1 || !s2)
		return (0);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	(to_free == 1 || to_free == 3) ? free(s1) : 0;
	(to_free == 2 || to_free == 3) ? free(s2) : 0;
	return (res);
}
