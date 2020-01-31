/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_is_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:19:02 by abarot            #+#    #+#             */
/*   Updated: 2020/01/20 16:32:39 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_spec_is_valid(const char *str)
{
	int	i_str;

	i_str = 0;
	while (str[i_str] && !ft_is_printf_type(str[i_str]))
	{
		if (!ft_is_printf_option(str[i_str]))
			return (0);
		i_str++;
	}
	return (1);
}
