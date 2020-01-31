/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:31:24 by abarot            #+#    #+#             */
/*   Updated: 2020/01/27 12:32:15 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_get_flags(const char *str, t_spec *spec)
{
	int i_str;

	i_str = 0;
	while (!ft_is_printf_type(str[i_str]) && str[i_str] && str[i_str] != '.')
	{
		if (str[i_str] == '0')
		{
			(spec->zero_less_flag != LESS) ? spec->zero_less_flag = ZERO : 0;
			while (str[i_str] == '0')
				i_str++;
		}
		(str[i_str] == '-') ? spec->zero_less_flag = LESS : 0;
		(str[i_str] == '+') ? spec->space_plus_flag = PLUS : 0;
		if (str[i_str] == ' ')
			(!spec->space_plus_flag) ? spec->space_plus_flag = SPACE : 0;
		(str[i_str] == '#') ? spec->hashtag_flag = 1 : 0;
		while (ft_isdigit(str[i_str]))
			i_str++;
		if (str[i_str] && str[i_str] != '.' && !ft_is_printf_type(str[i_str]))
			i_str++;
	}
}
