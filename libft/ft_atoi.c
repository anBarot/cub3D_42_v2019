/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:37:03 by abarot            #+#    #+#             */
/*   Updated: 2019/10/15 10:55:17 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int i;
	int sign;
	int nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while (ft_isdigit(s[i]) == 0)
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n' && s[i] != '\r' &&
				s[i] != '\v' && s[i] != '\f' && s[i] != '-' && s[i] != '+')
			return (0);
		if ((s[i] == '-' && (ft_isdigit(s[i + 1]) == 0)) ||
		(s[i] == '+' && (ft_isdigit(s[i + 1]) == 0)))
			return (0);
		else if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		nbr = nbr * 10 + (s[i] - 48);
		i++;
	}
	return (sign * nbr);
}
