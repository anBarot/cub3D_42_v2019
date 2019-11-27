/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:17:50 by abarot            #+#    #+#             */
/*   Updated: 2019/11/27 19:03:13 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		errno;

int 	main(int ac, char **av)
{
	t_spec	*spec;
	int		fd;
	
	ft_initialyze(spec);
	if (ac != 2 || (fd = open(av[1], O_RDONLY)) == -1 || !ft_get_spec(spec, fd))
	{	
		perror("ERROR\n");
		return (0);
	}
	// if (!mlx_new_window(mlx_ptr, w_size->x, w_size->y, char *title))
	free(spec);
	return (0);
}

void	ft_initialyze(t_spec *spec)
{
	spec->resol->x = 0;
	spec->resol->y = 0;
	spec->col_ceil->R = 0;
	spec->col_ceil->G = 0;
	spec->col_ceil->B = 0;
	spec->col_floor->R = 0;
	spec->col_floor->G = 0;
	spec->col_floor->B = 0;
	spec->path_north = 0;
	spec->path_west = 0;
	spec->path_east = 0;
	spec->path_south = 0;
	spec->path_sprite = 0;
	spec->map = 0;
}
