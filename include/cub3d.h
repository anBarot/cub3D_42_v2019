/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:35:04 by abarot            #+#    #+#             */
/*   Updated: 2020/04/14 12:32:08 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# define LEFT_LAT_KEY	        113
# define RIGHT_LAT_KEY      	100
# define LEFTKEY			    65361
# define RIGHTKEY		        65363
# define UPKEY1			        65362
# define UPKEY2			        122
# define DOWNKEY1			    65364
# define DOWNKEY2			    115
# define ESCAPEKEY		        65307

int			ft_receive_events(t_config *config);
void		ft_move_backandforth(char **map, t_coord *p_coord,
			int angle, int mv_value);
void		ft_move_lateral(char **map, t_coord *p_coord, int angle,
			int mv_value);
void		ft_turn(int *angle, int value);
void		ft_draw_walls(t_config *config);
void		ft_draw_sprites(t_config *config);
int			ft_calc_projection(int dist_obj, double tmp_angle, int cam_angle,
			int resol_x);
void		ft_escape_game(t_config *config);
#endif
