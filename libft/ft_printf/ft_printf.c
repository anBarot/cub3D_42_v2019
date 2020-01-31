/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 13:16:56 by abarot            #+#    #+#             */
/*   Updated: 2020/01/31 10:40:34 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_get_formatstr(const char *str, int *i_str, va_list arg_lst, int *rtr)
{
	*i_str += 1;
	*rtr += ft_formated_string(str + *i_str, arg_lst);
	while (str[*i_str] && !ft_is_printf_type(str[*i_str]))
		*i_str += 1;
}

int		ft_printf(const char *str, ...)
{
	va_list		arg_lst;
	int			to_return;
	int			i_str;

	va_start(arg_lst, str);
	i_str = 0;
	to_return = 0;
	while (str[i_str])
	{
		if (str[i_str] != '%' && str[i_str])
		{
			ft_putchar_fd(str[i_str], 1);
			to_return++;
		}
		else if (str[i_str] && ft_spec_is_valid(str + i_str + 1))
			ft_get_formatstr(str, &i_str, arg_lst, &to_return);
		else
			while (str[i_str] && ft_is_printf_option(str[i_str + 1]))
				i_str++;
		(str[i_str]) ? i_str++ : 0;
	}
	va_end(arg_lst);
	return (to_return);
}
