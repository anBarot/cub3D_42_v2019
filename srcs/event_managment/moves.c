/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:37:44 by abarot            #+#    #+#             */
/*   Updated: 2020/04/15 17:52:17 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_backandforth(char **map, t_coord *p_c, int agl, int val)
{
	if ((agl >= 45 && agl < 135) && map[p_c->x - val][p_c->y] == '0')
		p_c->x -= val;
	else if ((agl >= 315 || agl < 45) && map[p_c->x][p_c->y - val] == '0')
		p_c->y -= val;
	else if ((agl >= 225 && agl < 315) && map[p_c->x + val][p_c->y] == '0')
		p_c->x += val;
	else if ((agl >= 135 && agl < 225) && map[p_c->x][p_c->y + val] == '0')
		p_c->y += val;
}

void	ft_move_lateral(char **map, t_coord *p_c, int agl, int val)
{
	if ((agl >= 45 && agl < 135) && map[p_c->x][p_c->y + val] == '0')
		p_c->y += val;
	else if ((agl >= 315 || agl < 45) && map[p_c->x - val][p_c->y] == '0')
		p_c->x -= val;
	else if ((agl >= 225 && agl < 315) && map[p_c->x][p_c->y - val] == '0')
		p_c->y -= val;
	else if ((agl >= 135 && agl < 225) && map[p_c->x + val][p_c->y] == '0')
		p_c->x += val;
}

void	ft_turn(int *angle, int value)
{
	*angle = *angle + value;
	if (*angle < 0)
		*angle = *angle + 360;
	if (*angle > 360)
		*angle = *angle - 360;
}
