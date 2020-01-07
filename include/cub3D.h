/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:35:04 by abarot            #+#    #+#             */
/*   Updated: 2020/01/07 14:46:21 by abarot           ###   ########.fr       */
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
# define WALL_SIZE			64
# define FOV 				60
# define LEFTKEY(value)		((value == 123 || value == 0) ? 1 : 0)
# define RIGHTKEY(value)	((value == 124 || value == 2) ? 1 : 0)
# define UPKEY(value)		((value == 126 || value == 13) ? 1 : 0)
# define DOWNKEY(value)		((value == 125 || value == 1) ? 1 : 0)
# define ESCAPEKEY(value)	((value == 53) ? 1 : 0)
# define RAD(degree)		((degree) * (M_PI / 180))

typedef struct		s_spec
{
	void			*mlx_ptr;
	void			*win_ptr;
	double			*resol;
	int				col_ceil;
	int				col_floor;
	char			*path_north;
	char			*path_west;
	char			*path_east;
	char			*path_south;
	char			*path_sprite;
	char			**map;
	int				*map_player_coord;
	char			dir;
	double			cam_angle;
}					t_spec;
typedef struct		s_raycast
{
	double			*cube_player_coord;
	double			*wall_coord_line;
	double			*wall_coord_col;
}					t_raycast;
double				*ft_get_res(char *line);
int					ft_get_spec(t_spec *spec, int fd);
int					ft_get_col(char *line);
void				ft_get_map(t_spec *spec, char **line, int fd);
int					ft_check_map_border(char **map);
int					ft_check_map_content_and_size(char **map);
int					ft_get_coord(t_spec *spec);
int					ft_get_camangle(t_spec *spec);
int					ft_key_pressed(int keycode, t_spec *spec);
void				ft_move_forward(t_spec *spec);
void				ft_move_backward(t_spec *spec);
void				ft_turn_left(t_spec *spec);
void				ft_turn_right(t_spec *spec);
void				ft_display_screen(t_spec *spec);
double				ft_cast_ray(t_spec *spec);
void				ft_get_crosscoord_line(t_spec *spec, t_raycast *raycast);
void				ft_get_crosscoord_col(t_spec *spec, t_raycast *raycast);
void				ft_get_specialangle_coord(t_spec *spec, t_raycast *raycast);
double				ft_magnitude(double *in_coord, double *fin_coord);
double				ft_get_distortion_correction(double angle);
#endif