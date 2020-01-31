/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_formated_string.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:30:39 by abarot            #+#    #+#             */
/*   Updated: 2020/01/25 14:59:21 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_get_spec(const char *str, va_list arg_lst, t_spec *spec)
{
	ft_get_flags(str, spec);
	ft_get_width(str, arg_lst, spec);
	ft_get_precision_and_size(str, arg_lst, spec);
	ft_get_type(str, spec);
	ft_get_arg_as_a_string(arg_lst, spec);
}

int		ft_formated_string(const char *str, va_list arg_lst)
{
	t_spec	*spec;
	int		to_return;

	to_return = 0;
	if (!(spec = (t_spec *)ft_calloc(sizeof(t_spec), 1)))
		return (0);
	ft_initialyse_spec(spec);
	ft_get_spec(str, arg_lst, spec);
	ft_apply_spec(spec);
	to_return = ft_strlen(spec->arg_str);
	if (spec->type == CHAR_IS_ZERO)
	{
		ft_display_char_is_zero(spec);
		to_return++;
	}
	else
		ft_putstr_fd(spec->arg_str, 1);
	free(spec->arg_str);
	free(spec);
	return (to_return);
}
