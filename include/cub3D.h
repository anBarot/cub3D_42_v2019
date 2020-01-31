/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:35:04 by abarot            #+#    #+#             */
/*   Updated: 2020/01/31 13:54:24 by abarot           ###   ########.fr       */
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

#ifndef CUB3D_H
# define CUB3D_H
# include <mlx.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "libft.h"
# include "libftprintf.h"
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
	void			*mlx_ptr;
	void			*win_ptr;
	double			*resol;
	int				col_ceil;
	int				col_floor;
	char			*path_north_texture;
	char			*path_west_texture;
	char			*path_east_texture;
	char			*path_south_texture;
	char			*path_sprite;
	char			**map;
	int				*player_coord;
	double			cam_angle;
}					t_config;
enum				e_error
{
	NO_ERROR,
	INVALID_ARG_NBR_ERROR,
	INVALID_ARG_ERROR,
	INIT_ERROR,
	OPEN_FILE_ERROR,
	MAP_ERROR,
	RESOL_ERROR,
	COORD_ERROR,
	MULTIPLAYER_ERROR,
	NO_PLAYER_ERROR,
	C_COLOR_ERROR,
	F_COLOR_ERROR,
	N_PATH_ERROR,
	SO_PATH_ERROR,
	W_PATH_ERROR,
	E_PATH_ERROR,
	SP_PATH_ERROR
};
int			ft_error_msg(int error_value);
int			ft_initialyse_config(t_config *config);
int			ft_is_valid_arg(const char *av_1, const char *av_2);
int			ft_parse_file(t_config *config, char *cub_file);
int			ft_get_color(char *line);
void 		ft_get_map(t_config *config, char **line, int fd);
int			ft_get_player_coor(t_config *config);
double		*ft_get_resolution(char *line);
char		*ft_get_texture_path(char *line);
int			ft_receive_events(t_config *config, char *title);
int			ft_pressed_key(int keycode, t_config *config);
void		ft_move_backward(t_config *config);
void		ft_move_forward(t_config *config);
void		ft_turn_left(t_config *config);
void		ft_turn_right(t_config *config);
#endif