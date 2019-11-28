/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:17:50 by abarot            #+#    #+#             */
/*   Updated: 2019/11/28 16:54:29 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		errno;

int 	main(int ac, char **av)
{
	printf("\n-----entering main------\n");
	t_spec	*spec;
	int		fd;
	
	if (!(spec = (t_spec *)malloc(sizeof(t_spec))) || !(ft_spec_initialyze(spec)))
		return (0);
	if (ac != 2 || (fd = open(av[1], O_RDONLY)) == -1 || !ft_get_spec(spec, fd) || !ft_spec_isvalid(spec))
	{
		perror("ERROR\n");
		return (0);
	}
	// if (!mlx_new_window(mlx_ptr, w_size->x, w_size->y, char *title))
	free(spec);
	printf("\n------quitting main------\n");
	return (0);
}

int	ft_spec_initialyze(t_spec *spec)
{
	printf("\n-----entering spec initialyze------\n");
	if (!(spec->resol = (t_resol *)malloc(sizeof(t_resol))) || !(spec->col_ceil = (t_col *)malloc(sizeof(t_col)))
		|| !(spec->col_floor = (t_col *)malloc(sizeof(t_col))) || !(spec->map = (char **)malloc(sizeof(char*) * 1000000)))
		return (0);
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
	printf("\n------quitting spec initialize------\n");
	return (1);
}
