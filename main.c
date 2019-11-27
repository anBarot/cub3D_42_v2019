/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:17:50 by abarot            #+#    #+#             */
/*   Updated: 2019/11/27 16:23:08 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		errno;



int 	main(int ac, char **av)
{
	void	*mlx_ptr;
	t_spec	*spec;
	int		fd;
	
	ft_initialyze(spec);
	if (ac != 2 || (fd = open(av[1], O_RDONLY)) == -1 || !mlx_init())
	{	
		perror("ERROR\n");
		return (0);
	}
	if (!ft_get_spec(spec, fd))
		return (0);
	if (!mlx_new_window(mlx_ptr, w_size->x, w_size->y, char *title))
	

	return (0);
}

int		ft_get_spec(t_spec *spec, int fd)
{
	char	**line;
	int		res;

	if (!(line = (char **)malloc(sizeof(char *))))
		return (0);

	while ((res =ft_get_next_line(fd, line)) == 1)
	{
		(line[0][0] == 'R' && line[0][1] == ' ') ? ft_get_res(spec, *line) : 0;
		(line[0][0] == 'N' && line[0][1] == 'O' && line[0][2] == ' ') ?
				ft_get_path_no(spec, *line) : 0;
		(line[0][0] == 'S' && line[0][1] == 'O' && line[0][2] == ' ') ?
				ft_get_path_so(spec, *line) : 0;
		(line[0][0] == 'W' && line[0][1] == 'E' && line[0][2] == ' ') ?
				ft_get_path_we(spec, *line) : 0;
		(line[0][0] == 'E' && line[0][1] == 'A' && line[0][2] == ' ') ?
				ft_get_path_ea(spec, *line) : 0;
		(line[0][0] == 'S' && line[0][1] == ' ') ? ft_get_sprite(spec, *line) : 0;
		(line[0][0] == 'F' && line[0][1] == ' ') ? ft_get_floor(spec, *line) : 0;
		(line[0][0] == 'C' && line[0][1] == ' ') ? ft_get_ceiling(spec, *line) : 0;
		(line[0][0] == '1') ? ft_get_map(spec, *line, fd) : 0;
	}
	return (1);
}

void	ft_get_res(t_spec *spec, char *line)
(





)

void	ft_get_path_no(t_spec *spec, char *line)
()

void	ft_get_path_so(t_spec *spec, char *line)
()

void	ft_get_path_we(t_spec *spec, char *line)
()

void	ft_get_path_ea(t_spec *spec, char *line)
()

void	ft_get_sprite(t_spec *spec, char *line)
()

void	ft_get_floor(t_spec *spec, char *line)
()

void	ft_get_ceiling(t_spec *spec, char *line)
()
