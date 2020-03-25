/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:35:04 by abarot            #+#    #+#             */
/*   Updated: 2020/01/31 15:10:11 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// todos :
// 	- corriger put sprite to screen function : image a droite passe a gauche
// 	- corriger le deplacement des sprites avec deplacment du joueur

#ifndef CUB3D_H
# define CUB3D_H
# include "initialize.h"
# include "parse.h"
# include "mlx_img_treatment.h"
# include "raycast.h"
# include <mlx.h>
# include "libft.h"
# define WALL_SIZE				64
# define FOV 					60
# define NORTH_DIR(value)		((value >= 45 && value < 135) ? 1 : 0)
# define EAST_DIR(value)		((value >= 135 && value < 225) ? 1 : 0)
# define SOUTH_DIR(value)		((value >= 225 && value < 315) ? 1 : 0)
# define WEST_DIR(value)		((value >= 315 || value < 45) ? 1 : 0)
# define LEFT_LAT_KEY(value)	((value == 113) ? 1 : 0)
# define RIGHT_LAT_KEY(value) 	((value == 100) ? 1 : 0)
# define LEFTKEY(value)			((value ==  65361) ? 1 : 0)
# define RIGHTKEY(value)		((value == 65363) ? 1 : 0)
# define UPKEY(value)			((value == 65362 || value == 122) ? 1 : 0)
# define DOWNKEY(value)			((value == 65364 || value == 115) ? 1 : 0)
# define ESCAPEKEY(value)		((value == 65307) ? 1 : 0)

int			ft_receive_events(t_config *config);
void		ft_move_backandforth(char **map, t_coord *p_coord, int angle, int mv_value);
void		ft_move_lateral(char **map, t_coord *p_coord, int angle, int mv_value);
void		ft_turn(int *angle, int value);
void		ft_draw_walls(t_config *config);
void		ft_draw_sprites(t_config *config);
int			ft_calc_projection(int dist_obj, double tmp_angle, int cam_angle, int resol_x);
void		ft_escape_game(t_config *config);
#endif