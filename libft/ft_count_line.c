/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 17:01:33 by abarot            #+#    #+#             */
/*   Updated: 2020/04/14 17:01:49 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_line(char **map)
{
	int	line;

	line = 0;
	while (map[line])
		line++;
	return (line);
}