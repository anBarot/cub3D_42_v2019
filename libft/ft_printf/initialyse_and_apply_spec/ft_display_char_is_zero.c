/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_char_is_zero.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:17:46 by abarot            #+#    #+#             */
/*   Updated: 2020/01/22 16:18:28 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_display_char_is_zero(t_spec *spec)
{
	spec->width ? spec->width-- : 0;
	if (spec->zero_less_flag == LESS)
	{
		ft_putchar_fd(0, 1);
		ft_putstr_fd(spec->arg_str, 1);
	}
	else
	{
		ft_putstr_fd(spec->arg_str, 1);
		ft_putchar_fd(0, 1);
	}
}
