/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_spec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 11:20:00 by abarot            #+#    #+#             */
/*   Updated: 2020/01/27 11:12:04 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_apply_spec(t_spec *spec)
{
	(spec->space_plus_flag == PLUS) ? ft_apply_plus(spec) : 0;
	(spec->space_plus_flag == SPACE) ? ft_apply_space(spec) : 0;
	(spec->precision) ? ft_apply_precision(spec) : 0;
	(spec->zero_less_flag == ZERO) ? ft_apply_zero(spec) : 0;
	(spec->hashtag_flag) ? ft_apply_hashtag(spec) : 0;
	(spec->zero_less_flag == LESS) ? ft_apply_less(spec) : 0;
	(!spec->zero_less_flag) ? ft_apply_no_flag(spec) : 0;
}

void	ft_apply_precision(t_spec *spec)
{
	(spec->type == STRING) ? ft_apply_precision_string(spec) : 0;
	(spec->type == ADDRESS) ? ft_apply_precision_address(spec) : 0;
	(spec->type == UNSIGNED_INT || spec->type == SIGNED_INT ||
		spec->type == HEXADEC || spec->type == CAP_HEXADEC) ?
		ft_apply_precision_number(spec) : 0;
}
