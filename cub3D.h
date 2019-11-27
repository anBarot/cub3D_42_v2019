/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:35:04 by abarot            #+#    #+#             */
/*   Updated: 2019/11/27 16:22:37 by abarot           ###   ########.fr       */
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
typedef struct		s_spec
{
	t_resol			*resol;
	t_color			*color;
	char			*path_north;
	char			*path_west;
	char			*path_east;
	char			*path_south;
	char			*path_sprite;
	int				**map;
}					t_spec;
typedef struct		s_resol
{
	unsigned int	x;
	unsigned int	y;
}					t_resol;
typedef struct		s_color
{
	unsigned int	R;
	unsigned int	G;
	unsigned int	B;
}					t_color;
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
int		get_next_line(int fd, char **line);
int		ft_hasnewline(char *str);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
char	*ft_strcatfree(char *s1, char *s2, int read_value, int var_free);
void	ft_createkeep(char *keep, char *line);
#endif