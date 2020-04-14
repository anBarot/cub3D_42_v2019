/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:37:44 by abarot            #+#    #+#             */
/*   Updated: 2020/04/14 12:31:55 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_backandforth(char **map, t_coord *p_coor, int angle, int value)
{
	if (NORTH_DIR(angle) && map[p_coor->x - value][p_coor->y] == '0')
		p_coor->x -= value;
	else if (WEST_DIR(angle) && map[p_coor->x][p_coor->y - value] == '0')
		p_coor->y -= value;
	else if (SOUTH_DIR(angle) && map[p_coor->x + value][p_coor->y] == '0')
		p_coor->x += value;
	else if	(EAST_DIR(angle) && map[p_coor->x][p_coor->y + value] == '0')
		p_coor->y += value;
}

void	ft_move_lateral(char **map, t_coord *p_coord, int angle, int mv_value)
{
	if (NORTH_DIR(angle) && map[p_coord->x][p_coord->y + mv_value] == '0')
		p_coord->y += mv_value;
	else if (WEST_DIR(angle) && map[p_coord->x - mv_value][p_coord->y] == '0')
		p_coord->x -= mv_value;
	else if (SOUTH_DIR(angle) && map[p_coord->x][p_coord->y - mv_value] == '0')
		p_coord->y -= mv_value;
	else if	(EAST_DIR(angle) && map[p_coord->x + mv_value][p_coord->y] == '0')
		p_coord->x += mv_value;
}

void	ft_turn(int *angle, int value)
{
	*angle = *angle + value;
	if (*angle < 0)
		*angle = *angle + 360;
	if (*angle > 360)
		*angle = *angle - 360;
}
