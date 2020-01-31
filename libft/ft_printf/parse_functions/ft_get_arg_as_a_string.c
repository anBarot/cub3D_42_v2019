/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_as_a_string.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:27:34 by abarot            #+#    #+#             */
/*   Updated: 2020/01/31 10:10:43 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_get_arg_as_a_string(va_list lst, t_spec *spec)
{
	(spec->type == CHAR) ? spec->arg_str = ft_char_to_str(va_arg(lst, int)) : 0;
	(spec->type == STRING) ? spec->arg_str = ft_strdup(va_arg(lst, char *)) : 0;
	(spec->type == SIGNED_INT) ? spec->arg_str = ft_itoa(va_arg(lst, int)) : 0;
	if (spec->type == UNSIGNED_INT)
		spec->arg_str = ft_utoa(va_arg(lst, unsigned int));
	if (spec->type == CAP_HEXADEC)
		spec->arg_str = ft_toupper_string(ft_hextoa(va_arg(lst, unsigned int)));
	if (spec->type == HEXADEC)
		spec->arg_str = ft_hextoa(va_arg(lst, unsigned int));
	if (spec->type == ADDRESS)
		spec->arg_str = ft_addtoa(va_arg(lst, unsigned long));
	(spec->type == PERC) ? spec->arg_str = ft_char_to_str('%') : 0;
	if ((spec->type == CAP_HEXADEC || spec->type == HEXADEC) &&
			spec->hashtag_flag == 1 && *spec->arg_str == '0')
		spec->hashtag_flag = 0;
	if (spec->type == CHAR && *spec->arg_str == 0)
		spec->type = CHAR_IS_ZERO;
	if (spec->type == STRING && spec->arg_str == 0)
		spec->arg_str = ft_strdup("(null)");
	if (spec->type == SIGNED_INT && spec->arg_str[0] == '-')
		spec->space_plus_flag = NO_FLAG_SPACE_PLUS;
}
