/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_precision_number.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 11:24:16 by abarot            #+#    #+#             */
/*   Updated: 2020/04/19 11:33:34 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_apply_precision_number(t_spec *spec)
{
	if (spec->zero_less_flag == ZERO)
		spec->zero_less_flag = NO_FLAG_ZERO_LESS;
	if (spec->size == 0 && (spec->arg_str[0] == '0' ||
		((spec->arg_str[0] == '+' || spec->arg_str[0] == ' ')
		&& spec->arg_str[1] == '0')))
	{
		if (spec->arg_str[0] == '+' || spec->arg_str[0] == ' ')
			spec->arg_str[1] = '\0';
		else
			spec->arg_str[0] = '\0';
		return ;
	}
	else if ((spec->type == SIGNED_INT || spec->type == HEXADEC ||
		spec->type == CAP_HEXADEC) && (spec->arg_str[0] == '-'
		|| spec->arg_str[0] == '+' || spec->arg_str[0] == ' '))
	{
		spec->arg_str[0] = '0';
		while (spec->size > (int)ft_strlen(spec->arg_str) - 1)
			spec->arg_str = ft_strjoin(ft_strdup("0"), spec->arg_str);
		(!spec->space_plus_flag) ? spec->arg_str[0] = '-' : 0;
		(spec->space_plus_flag == SPACE) ? spec->arg_str[0] = ' ' : 0;
		(spec->space_plus_flag == PLUS) ? spec->arg_str[0] = '+' : 0;
	}
	while (spec->size > (int)ft_strlen(spec->arg_str))
		spec->arg_str = ft_strjoin(ft_strdup("0"), spec->arg_str);
}
