/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_forward.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:37:19 by abarot            #+#    #+#             */
/*   Updated: 2020/01/29 17:37:29 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_move_forward(t_config *config)
{
	if (config->dir == 'N' && config->map[config->map_player_coord[0] - 1][config->map_player_coord[1]] != '1')
		config->map_player_coord[0] -= 1;
	else if (config->dir == 'W' && config->map[config->map_player_coord[0]][config->map_player_coord[1] - 1] != '1')
		config->map_player_coord[1] -= 1;
	else if (config->dir == 'S' && config->map[config->map_player_coord[0] + 1][config->map_player_coord[1]] != '1')
		config->map_player_coord[0] += 1;
	else if	(config->dir == 'E' && config->map[config->map_player_coord[0]][config->map_player_coord[1] + 1] != '1')
		config->map_player_coord[1] += 1;
}