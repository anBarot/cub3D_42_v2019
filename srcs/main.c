/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:17:50 by abarot            #+#    #+#             */
/*   Updated: 2020/01/29 17:27:00 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int 	main(int ac, char **av)
{
	t_config	*config;
<<<<<<< HEAD
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
=======
	int			error_value;
	
	if (ac > 3 || ac == 1)
		return (ft_error_msg(INVALID_ARG_NBR_ERROR));
	if (!ft_is_valid_arg(av[1]))
		return (ft_error_msg(INVALID_ARG_ERROR));
	if (!(config = ft_calloc(sizeof(t_config), 1)) || !(ft_initialyse_config(config)))
		return (ft_error_msg(INIT_ERROR));
	if (error_value = ft_parse_file(config, av[1]) ||
		error_value = ft_receive_events(config, av[1]))
		return (ft_error_msg(error_value));
>>>>>>> origin/cub3D_v2020_01_29
	return (0);
}
