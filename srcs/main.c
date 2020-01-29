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
	t_config	*config;
	int		fd;

	ft_initialyse_	
	if (!(config = (t_config *)malloc(sizeof(t_config))))
		return (0);
	if (ac != 2 || (fd = open(av[1], O_RDONLY)) == -1 || !ft_get_config(config, fd) 
		|| !(config->mlx_ptr = mlx_init()) || 
		!(config->win_ptr = mlx_new_window(config->mlx_ptr, config->resol[0], config->resol[1], av[1])))
	{
		perror("ERROR\n");
		return (0);
	}
	close(fd);
	ft_display_screen(config);
	mlx_key_hook(config->win_ptr, &(ft_key_pressed), config);
	mlx_loop(config->mlx_ptr);
	free(config);
	printf("\n------quitting main------\n");
	return (0);
}
