/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:17:50 by abarot            #+#    #+#             */
/*   Updated: 2020/01/31 14:58:41 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int 	main(int ac, char **av)
{
	t_config	*config;
	int			error_value;
	
	error_value = NO_ERROR;
	if (ac > 3 || ac == 1)
		return (ft_error_msg(INVALID_ARG_NBR_ERROR));
	if ((ac == 3 && !ft_is_valid_arg(av[1], av[2])) ||
		!ft_is_valid_arg(av[1], 0))
		return (ft_error_msg(INVALID_ARG_ERROR));
	if (!(config = ft_calloc(sizeof(t_config), 1)) ||
		!(ft_initialyse_config(config)))
		return (ft_error_msg(INIT_ERROR));
	if ((error_value = ft_parse_file(config, av[1])))
		return (ft_error_msg(error_value));
	// test parse
	printf("\n----.cub is valid----\n");
	printf("\nresolution : %dx%d\ncolor : F %d, C %d\npaths : \nN : %s\nE : %s\nW : %s\nS : %s\nSp : %s\n",
	config->resol.x, config->resol.y, config->col_floor, config->col_ceil, config->path_north_texture,
	config->path_east_texture, config->path_west_texture, config->path_south_texture, config->path_sprite);
	int i = 0;
	while (config->map[i])
	{
		printf("\nmap %d : %s", i, config->map[i]);
		i++;
	}
	printf("\ncoor : %d,%d\n", config->player_coord.x, config->player_coord.y);
	// fin test parse
	ft_receive_events(config, av[1]);
	return (0);
}
