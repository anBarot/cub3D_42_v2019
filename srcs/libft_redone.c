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

#include "../include/cub3D.h"

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcat(char *s1, char *s2, int r_v, int var_free)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	;
	if (!(res = (char *)malloc((ft_strlen((char *)s1) + r_v + 1) * sizeof(char))))
		return (0);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (j < r_v)
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	if ((var_free == 1 && s1) || (var_free == 3 && s1))
		free(s1);
	if ((var_free == 2 && s2) || (var_free == 3 && s2))
		free(s2);
	return (res);
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