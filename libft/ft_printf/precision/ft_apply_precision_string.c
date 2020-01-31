/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_precision_string.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 11:24:34 by abarot            #+#    #+#             */
/*   Updated: 2020/01/22 14:36:34 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_apply_precision_string(t_spec *spec)
{
	if (!spec->size || !spec->arg_str)
	{
		(spec->arg_str) ? free(spec->arg_str) : 0;
		spec->arg_str = ft_strdup("\0");
	}
	else
		spec->arg_str[spec->size] = '\0';
}
