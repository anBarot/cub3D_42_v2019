/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_plus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 11:22:05 by abarot            #+#    #+#             */
/*   Updated: 2020/04/19 11:34:46 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_apply_plus(t_spec *spec)
{
	if (spec->arg_str[0] != '-' && (spec->type == SIGNED_INT))
		spec->arg_str = ft_strjoin(ft_strdup("+"), spec->arg_str);
}
