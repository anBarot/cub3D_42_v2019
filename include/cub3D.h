/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:35:04 by abarot            #+#    #+#             */
/*   Updated: 2020/01/29 18:02:06 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* to do list : 
		-	tester fonction remove in str,
		-	gerer les parses error,
		-	gerer erreurs de color : creer struct col R,G,B 
		-	creer maps test,
		-	faire un main de test automatique ou makefile (pr tous projet adaptable),
		-	ft_calloc des l initialisation,
		-	ajout libft : printf + getnext
		-	algo img : img base C + F
*/

<<<<<<< HEAD
=======
/*
--------a merger------

	-parse color,
	-parse resol,
	-parse map,
*/

>>>>>>> origin/cub3D_v2020_01_29
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
# define RESOL_MAX_X			2560
# define RESOL_MAX_Y			1440
# define VALID_MAP_VALUE(value)	((value == '0' || value == '1' || value == '2' \
								|| value == 'N' || value == 'E' || value == 'S'\
								|| value == 'W') ? 1 : 0)
# define WALL_SIZE				64
# define FOV 					60
# define LEFT_LAT_KEY(value)	((value == 1) ? 1 : 0)
# define RIGHT_LAT_KEY(value) 	((value == 1) ? 1 : 0)
# define LEFTKEY(value)			((value == 123 || value == 0) ? 1 : 0)
# define RIGHTKEY(value)		((value == 124 || value == 2) ? 1 : 0)
# define UPKEY(value)			((value == 126 || value == 13) ? 1 : 0)
# define DOWNKEY(value)			((value == 125 || value == 1) ? 1 : 0)
# define ESCAPEKEY(value)		((value == 53) ? 1 : 0)
# define RAD(degree)			((degree) * (M_PI / 180))

typedef struct		s_config
{
<<<<<<< HEAD
	void			*mlx;
	void			*win_ptr;
	int				error_type;
=======
	void			*mlx_ptr;
	void			*win_ptr;
>>>>>>> origin/cub3D_v2020_01_29
	double			*resol;
	int				col_ceil;
	int				col_floor;
	char			*path_north_texture;
	char			*path_west_texture;
	char			*path_east_texture;
	char			*path_south_texture;
	char			*path_sprite;
	char			**map;
}					t_config;
<<<<<<< HEAD
typedef struct		s_player_coor
=======
typedef struct		s_player_coord
>>>>>>> origin/cub3D_v2020_01_29
{
	int				*map_player_coord;
	char			dir;
	double			cam_angle;
}					t_player_coor;
enum				e_error
{
	NO_ERROR,
	INVALID_ARG_NBR_ERROR,
	INVALID_ARG_ERROR,
	INIT_ERROR,
	OPEN_FILE_ERROR,
	MAP_VALUE_ERROR,
	MAP_BORDER_ERROR,
	MAP_SIZE_ERROR,
	RESOL_ERROR,
	COORD_ERROR,
	FC_COLOR_ERROR,
	MULTIPLAYER_ERROR,
<<<<<<< HEAD
	N_PATH_ERROR,
	S_PATH_ERROR,
	W_PATH_ERROR,
	E_PATH_ERROR,
	S_PATH_ERROR
=======
	PATH_NORTH_ERROR,
	PATH_WEST_ERROR,
	PATH_SOUTH_ERROR,
	PATH_EAST_ERROR,
	PATH_SPRITE_ERROR
>>>>>>> origin/cub3D_v2020_01_29
};
double				*ft_get_res(char *line);
int					ft_get_config(t_config *config, int fd);
int					ft_get_col(char *line);
void				ft_get_map(t_config *config, char **line, int fd);
int					ft_check_map_border(char **map);
int					ft_check_map_content_and_size(char **map);
int					ft_get_coord(t_config *config);
int					ft_get_camangle(t_config *config);
int					ft_key_pressed(int keycode, t_config *config);
void				ft_move_forward(t_config *config);
void				ft_move_backward(t_config *config);
void				ft_turn_left(t_config *config);
void				ft_turn_right(t_config *config);
void				ft_display_screen(t_config *config);
double				ft_cast_ray(t_config *config);
void				ft_get_crosscoord_line(t_config *config, t_raycast *raycast);
void				ft_get_crosscoord_col(t_config *config, t_raycast *raycast);
void				ft_get_configialangle_coord(t_config *config, t_raycast *raycast);
double				ft_magnitude(double *in_coord, double *fin_coord);
double				ft_get_distortion_correction(double angle);
#endif