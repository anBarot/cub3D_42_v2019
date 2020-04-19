/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_precision_address.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 11:23:53 by abarot            #+#    #+#             */
/*   Updated: 2020/04/19 11:32:52 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_apply_precision_address(t_spec *spec)
{
	char	*tmp;

	if (spec->size == 0 && spec->arg_str[3] == '\0')
	{
		spec->arg_str[2] = '\0';
		return ;
	}
	spec->arg_str[1] = '0';
	while (spec->size > (int)ft_strlen(spec->arg_str) - 2)
	{
		tmp = spec->arg_str;
		spec->arg_str = ft_strjoin(ft_strdup("0x0"), ft_strdup(spec->arg_str + 2));
		free(tmp);
	}
	spec->arg_str[1] = 'x';
}
