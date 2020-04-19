/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 11:22:25 by abarot            #+#    #+#             */
/*   Updated: 2020/04/19 11:34:59 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_apply_space(t_spec *spec)
{
	if (spec->arg_str[0] != '-' && spec->type == SIGNED_INT)
		spec->arg_str = ft_strjoin(ft_strdup(" "), spec->arg_str);
}
