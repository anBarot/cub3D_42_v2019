/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:35:04 by abarot            #+#    #+#             */
/*   Updated: 2019/12/11 19:00:02 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "toolbox.h"
# include "mlx.h"
# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# define H_WALL		64
# define l_WALL		64
# define L_WALL		64
# define VIEW_ANGLE 60

//ajout struc s_raycast

typedef struct		s_spec
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				*resol;
	int				*col_ceil;
	int				*col_floor;
	char			*path_north;
	char			*path_west;
	char			*path_east;
	char			*path_south;
	char			*path_sprite;
	char			**map;
	int				*coord_player;
	char			*dir;
}					t_spec;

int					*ft_get_res(char *line);
int					ft_get_spec(t_spec *spec, int fd);
int					*ft_get_col(char *line);
void				ft_get_map(t_spec *spec, char **line, int fd);
int					ft_check_map_border(char **map);
int					ft_check_map_content_and_size(char **map);
int					ft_get_coord(t_spec *spec);
int					ft_key_pressed(int keycode, t_spec *spec);
void				ft_move_forward(t_spec *spec);
void				ft_move_backward(t_spec *spec);
void				ft_turn_left(t_spec *spec);
void				ft_turn_right(t_spec *spec);
#endif