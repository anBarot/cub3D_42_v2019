/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_hashtag.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 11:21:17 by abarot            #+#    #+#             */
/*   Updated: 2020/04/19 11:34:09 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_apply_hashtag(t_spec *spec)
{
	if (spec->type == HEXADEC)
		spec->arg_str = ft_strjoin(ft_strdup("0x"), spec->arg_str);
	else if (spec->type == CAP_HEXADEC)
		spec->arg_str = ft_strjoin(ft_strdup("0X"), spec->arg_str);
}
