/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_redone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:38:02 by abarot            #+#    #+#             */
/*   Updated: 2020/01/29 15:37:15 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub3D.h"

// size_t	ft_strlen(const char *s)
// {
// 	int i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// int	ft_isdigit(int c)
// {
// 	if (c >= '0' && c <= '9')
// 		return (1);
// 	return (0);
// }

// char	*ft_strdup(const char *s)
// {
// 	char	*dest;
// 	int		i;

// 	i = 0;
// 	dest = (char *)malloc((ft_strlen((char *)s) + 1) * sizeof(char));
// 	if (dest == 0)
// 		return (0);
// 	while (s[i])
// 	{
// 		dest[i] = s[i];
// 		i++;
// 	}
// 	dest[i] = '\0';
// 	return (dest);
// }

// int	ft_atoi(const char *s)
// {
// 	int i;
// 	int sign;
// 	int nbr;

// 	i = 0;
// 	sign = 1;
// 	nbr = 0;
// 	while (ft_isdigit(s[i]) == 0)
// 	{
// 		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n' && s[i] != '\r' &&
// 				s[i] != '\v' && s[i] != '\f' && s[i] != '-' && s[i] != '+')
// 			return (0);
// 		if ((s[i] == '-' && (ft_isdigit(s[i + 1]) == 0)) ||
// 		(s[i] == '+' && (ft_isdigit(s[i + 1]) == 0)))
// 			return (0);
// 		else if (s[i] == '-')
// 			sign = -1;
// 		i++;
// 	}
// 	while (s[i] >= '0' && s[i] <= '9')
// 	{
// 		nbr = nbr * 10 + (s[i] - 48);
// 		i++;
// 	}
// 	return (sign * nbr);
// }

// int	ft_check_in_set_char(char to_test, char *dataset)
// {
// 	int	i_dataset;

// 	i_dataset = 0;
// 	while (dataset[i_dataset] && dataset[i_dataset] != to_test)
// 		i_dataset++;
// 	if (dataset[i_dataset] == '\0')
// 		return (0);
// 	return (1);
// }

char	*ft_remove_in_str(char *str, char *char_set)
{
	int		i_str;
	int		in_str;
	int		i_char_set;
	char	*n_str;
	
	in_str = 0;
	i_str = 0;
	i_char_set = 0;
	if (!(n_str = calloc(sizeof(char), strlen(str))) || !str || !char_set)
		return (0);
	while (str[i_str])
	{
		while (char_set[i_char_set] && str[i_str])
		{
			if (str[i_str] == char_set[i_char_set])
			{
				i_str++;
				i_char_set = 0;
			}
			else
				i_char_set++;
		}
		n_str[in_str] = str[i_str];
		if (str[i_str])
			i_str++;
		in_str++;
		i_char_set = 0;
	}
	return (n_str);
}
