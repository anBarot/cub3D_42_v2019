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

// to_dos :
	// - ft_create_sprite_img
	// - quitter la enêtre de manière clean
	// - réparer murs apparaissent en décaler
	// - ne pas traverser les sprites

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
# define WALL_SIZE				64
# define FOV 					60
# define VALID_MAP_VALUE(value)	((value == '0' || value == '1' || value == '2' \
								|| value == 'N' || value == 'E' || value == 'S'\
								|| value == 'W') ? 1 : 0)
# define IS_WALL_SPRITE(value)	((value == '1' || value == '2') ? 1 : 0)
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
# define RAD(degree)			((degree) * (M_PI / 180))

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;
typedef struct		s_fcoord
{
	double			x;
	double			y;
}					t_fcoord;
typedef struct		s_raycast
{
	double			prop_cste;
	t_fcoord		p_coor;
	double			dist_obj;
	int				obj_proj;
	char			nesw_path;

}					t_raycast;
typedef struct 		s_img_spec
{
	void			*img_ptr;
	char			*mlx;
	int				width;
	int				height;
	int				size_line;
}					t_img;
typedef	struct		s_mlx_img
{
	t_img		ceiling;
	t_img		floor;
	t_img		north;
	t_img		south;
	t_img		west;
	t_img		east;
	t_img		sprite;
	int				bpp;
	int				endian;
}					t_mlx_img;
typedef struct		s_color 
{
	int				R;
	int				G;
	int				B;
}					t_color;
typedef struct		s_config
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_coord			resol;
	t_color			col_ceil;
	t_color			col_floor;
	char			*path_north;
	char			*path_west;
	char			*path_east;
	char			*path_south;
	char			*path_sprite;
	char			**map;
	t_coord			player_coord;
	int				cam_angle;
	t_mlx_img		img;
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
void		ft_initialyse_ray(t_raycast *ray);
int			ft_init_parsing(t_config *config, char *cub_file);
void		ft_get_resolution(t_config *config, char *line);
char		*ft_get_texture_path(char *line);
void		ft_get_color(char *line, t_config *config);
void 		ft_get_map(t_config *config, char **line, int fd);
int			ft_get_player_coor(t_config *config);
void		ft_create_background(t_config *config);
void		ft_create_texture(t_config *config);
void		ft_pixel_filling(char *mlx_to_fill, char *mlx_to_extract);
int			ft_receive_events(t_config *config);
void		ft_move_backandforth(t_config *config, int mv_value);
void		ft_move_lateral(t_config *config, int mv_value);
void		ft_turn(t_config *config, int angle_value);
void		ft_display_wall(t_config *config);
void		ft_raycast(t_config *config, t_raycast *ray, double angle, char obj);
t_img		ft_scalling(void *mlx_ptr, t_img img_to_scale, int width, int height);
void		ft_display_sprites(t_config *config);
#endif