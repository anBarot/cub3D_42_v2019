/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:17:50 by abarot            #+#    #+#             */
/*   Updated: 2020/01/27 15:29:08 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

int		errno;

int 	main(int ac, char **av)
{
	t_spec	*spec;
	int		fd;
	
	if (!(spec = (t_spec *)malloc(sizeof(t_spec))))
		return (0);
	if (ac != 2 || (fd = open(av[1], O_RDONLY)) == -1 || !ft_get_spec(spec, fd) 
		|| !(spec->mlx_ptr = mlx_init()) || 
		!(spec->win_ptr = mlx_new_window(spec->mlx_ptr, spec->resol[0], spec->resol[1], av[1])))
	{
		perror("ERROR\n");
		return (0);
	}
	close(fd);
	ft_display_screen(spec);
	mlx_key_hook(spec->win_ptr, &(ft_key_pressed), spec);
	mlx_loop(spec->mlx_ptr);
	free(spec);
	printf("\n------quitting main------\n");
	return (0);
}
