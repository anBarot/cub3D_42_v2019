/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:35:04 by abarot            #+#    #+#             */
/*   Updated: 2019/11/28 15:02:30 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# define BUFFER_SIZE 100
typedef struct		s_resol
{
	unsigned int	x;
	unsigned int	y;
}					t_resol;
typedef struct		s_col
{
	unsigned int	R;
	unsigned int	G;
	unsigned int	B;
}					t_col;
typedef struct		s_spec
{
	t_resol			*resol;
	t_col			*col_ceil;
	t_col			*col_floor;
	char			*path_north;
	char			*path_west;
	char			*path_east;
	char			*path_south;
	char			*path_sprite;
	char			**map;
}					t_spec;
int					get_next_line(int fd, char **line);
int					ft_hasnewline(char *str);
size_t				ft_strlen(const char *s);
void				ft_putstr_fd(char *s, int fd);
void				ft_putchar_fd(char c, int fd);
char				*ft_strcat(char *s1, char *s2, int read_value, int var_free);
void				ft_createkeep(char *keep, char *line);
void				ft_get_res(t_resol *resol, char *line);
int					ft_get_spec(t_spec *spec, int fd);
void				ft_get_col(t_col *col, char *line);
void				ft_get_map(char **map, char **line, int fd);
int					ft_spec_initialyze(t_spec *spec);
int					ft_check_map_border(char **map);
int					ft_check_in_set_char(char to_test, char *dataset);
int					ft_check_map_content_and_size(char **map);
int					ft_spec_isvalid(t_spec *spec);
int					ft_isdigit(int c);
char				*ft_strdup(const char *s);
int					ft_atoi(const char *s);
#endif