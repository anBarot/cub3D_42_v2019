/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:35:04 by abarot            #+#    #+#             */
/*   Updated: 2020/04/14 14:32:14 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# define RESOL_MAX_X	2560
# define RESOL_MAX_Y	1440
# include "libft.h"
# include "mlx_img_treatment.h"
# include "math_struct.h"

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
}					t_parse;

int					ft_init_parsing(t_parse *parse, char *cub_file);
int					ft_get_resolution(t_parse *parse, char *line);
int					ft_get_texture_path(t_parse *parse, char *line);
int					ft_get_color(char *line, t_parse *parse);
int					ft_get_map(t_parse *parse, char **line, int fd);
int					ft_get_player_coor(t_parse *parse);
#endif
