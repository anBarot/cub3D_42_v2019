/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 11:19:30 by abarot            #+#    #+#             */
/*   Updated: 2020/04/19 11:35:28 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_apply_zero(t_spec *spec)
{
	if ((spec->type == HEXADEC || spec->type == CAP_HEXADEC) &&
		spec->hashtag_flag)
		spec->width -= 2;
	if (spec->type == ADDRESS)
		ft_apply_no_flag(spec);
	if (spec->type == SIGNED_INT && (spec->arg_str[0] == '-' ||
		spec->arg_str[0] == '+' || spec->arg_str[0] == ' '))
	{
		spec->arg_str[0] = '0';
		while (spec->width > (int)ft_strlen(spec->arg_str))
			spec->arg_str = ft_strjoin(ft_strdup("0"), spec->arg_str);
		(spec->space_plus_flag == PLUS) ? spec->arg_str[0] = '+' : 0;
		(spec->space_plus_flag == SPACE) ? spec->arg_str[0] = ' ' : 0;
		(!spec->space_plus_flag) ? spec->arg_str[0] = '-' : 0;
	}
	while (spec->width > (int)ft_strlen(spec->arg_str))
		spec->arg_str = ft_strjoin(ft_strdup("0"), spec->arg_str);
}
