/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_less.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 11:21:33 by abarot            #+#    #+#             */
/*   Updated: 2020/04/19 11:34:20 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_apply_less(t_spec *spec)
{
	if (spec->type == CHAR_IS_ZERO)
		spec->width--;
	while (spec->width > (int)ft_strlen(spec->arg_str))
		spec->arg_str = ft_strjoin(spec->arg_str, ft_strdup(" "));
}
