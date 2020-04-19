/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_no_flag.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 11:21:55 by abarot            #+#    #+#             */
/*   Updated: 2020/04/19 11:34:32 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_apply_no_flag(t_spec *spec)
{
	if (spec->type == CHAR_IS_ZERO)
		spec->width--;
	while (spec->width > (int)ft_strlen(spec->arg_str))
		spec->arg_str = ft_strjoin(ft_strdup(" "), spec->arg_str);
}
