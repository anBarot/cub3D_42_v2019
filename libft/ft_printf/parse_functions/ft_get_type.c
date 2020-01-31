/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:31:49 by abarot            #+#    #+#             */
/*   Updated: 2020/01/31 10:06:16 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_get_type(const char *str, t_spec *spec)
{
	int	i_str;

	i_str = 0;
	while (str[i_str] && spec->type == ERROR)
	{
		(str[i_str] == 'c') ? spec->type = CHAR : 0;
		(str[i_str] == 'i' || str[i_str] == 'd') ? spec->type = SIGNED_INT : 0;
		(str[i_str] == 'X') ? spec->type = CAP_HEXADEC : 0;
		(str[i_str] == 'x') ? spec->type = HEXADEC : 0;
		(str[i_str] == 'p') ? spec->type = ADDRESS : 0;
		(str[i_str] == 'u') ? spec->type = UNSIGNED_INT : 0;
		(str[i_str] == '%') ? spec->type = PERC : 0;
		(str[i_str] == 's') ? spec->type = STRING : 0;
		i_str++;
	}
}
