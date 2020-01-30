/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:17:50 by abarot            #+#    #+#             */
/*   Updated: 2020/01/30 11:01:39 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		ft_is_valid_arg(const char *av_1, const char *av_2)
{
	int		i_ext;

	i_ext = ft_strlen(av_1) - 5;
	if (!av_2)
		if (ft_strncmp(av_2, "-save", 5))
			return (0);
	if (i_ext < 1 || ft_strncmp(av_1, ".cub", 4))
		return (0);
	return (1);
}
