/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_redone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:38:02 by abarot            #+#    #+#             */
/*   Updated: 2019/11/29 13:50:55 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc((ft_strlen((char *)s) + 1) * sizeof(char));
	if (dest == 0)
		return (0);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

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

int	ft_check_in_set_char(char to_test, char *dataset)
{
	int	i_dataset;

	i_dataset = 0;
	while (dataset[i_dataset] && dataset[i_dataset] != to_test)
		i_dataset++;
	if (dataset[i_dataset] == '\0')
		return (0);
	return (1);
}