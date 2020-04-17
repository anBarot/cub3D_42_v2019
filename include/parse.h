/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:35:04 by abarot            #+#    #+#             */
/*   Updated: 2020/04/17 16:19:15 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include "libft.h"
# include <X11/Xlib.h>
# include "mlx_img_treatment.h"
# include "math_struct.h"
# define RESMIN_X	70
# define RESMIN_Y	70

typedef struct		s_path_set
{
	char			*north;
	char			*west;
	char			*east;
	char			*south;
	char			*sprite;
}					t_path_set;

typedef struct		s_map
{
	char			**map;
	t_coord			p_coord;
	int				cam_angle;
}					t_map;
typedef struct		s_parse
{
	t_coord			resol;
	t_color			col_ceil;
	t_color			col_floor;
	t_path_set		path_set;
	t_map			map_elt;
	void			*mlx_ptr;
}					t_parse;
enum				e_direction
{
	UP,
	DOWN,
	RIGHT,
	LEFT,
};

int					ft_init_parsing(t_parse *parse, char *cub_file);
int					ft_get_resolution(t_parse *parse, char *line);
int					ft_get_texture_path(t_parse *parse, char *line);
int					ft_get_color(char *line, t_parse *parse, int error_value);
int					ft_get_map(t_map *map_elt, char **line, int fd);
int					ft_get_player_coor(t_map *map_elt);
int					ft_ckeck_map_border(char **map);
int					ft_check_map_value(char **map);
#endif
