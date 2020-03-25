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

#ifndef INITIALIZE_H
# define INITIALIZE_H
# include "parse.h"
# include "libft.h"
# include "mlx_img_treatment.h"
# include "math_struct.h"

enum				e_error
{
	NO_ERROR,
	INVALID_ARG_NBR_ERROR,
	INVALID_ARG_ERROR,
	INIT_ERROR,
	OPEN_FILE_ERROR,
	IMG_EXTENSION_ERROR,
	MAP_VALUE_ERROR,
	MAP_BORDER_ERROR,
	MAP_OVERFLOW,
	RESOL_ERROR,
	COORD_ERROR,
	MULTIPLAYER_ERROR,
	NO_PLAYER_ERROR,
	C_COLOR_ERROR,
	F_COLOR_ERROR,
	INVALID_PATH_ERROR,
	NO_RESOL_ERROR,
	NO_C_COLOR_ERROR,
	NO_F_COLOR_ERROR,
	NO_N_PATH_ERROR,
	NO_SO_PATH_ERROR,
	NO_W_PATH_ERROR,
	NO_E_PATH_ERROR,
	NO_SP_PATH_ERROR,
};

typedef	struct		s_img_set
{
	t_img			screen;
	t_img			north;
	t_img			south;
	t_img			west;
	t_img			east;
	t_img			sprite;
}					t_img_set;
typedef struct		s_config
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_parse			parse;
	t_img_set		img_set;
}					t_config;

int			ft_initialyse_config(t_config *config);
int			ft_error_msg(int error_value);
void		ft_create_texture(void *mlx_ptr, t_img_set *img, t_path_set path);
void		ft_create_screen(void *mlx_ptr, t_img *screen, t_coord resol);
void		ft_initialize_screen(t_img *screen, t_color c_color, t_color f_color);
void		ft_create_screenshot(t_img screen);
#endif