/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_plus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 11:22:05 by abarot            #+#    #+#             */
/*   Updated: 2020/01/31 10:07:10 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_apply_plus(t_spec *spec)
{
	if (spec->arg_str[0] != '-' && (spec->type == SIGNED_INT))
		spec->arg_str = ft_strjoin("+", spec->arg_str, 2);
}
