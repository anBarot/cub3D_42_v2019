/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:17:50 by abarot            #+#    #+#             */
/*   Updated: 2020/01/31 14:11:15 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int 	main(int ac, char **av)
{
	t_config	*config;
	int			error_value;
	
	printf("\n-----checking arguments nbr-----\n");
	error_value = NO_ERROR;
	if (ac > 3 || ac == 1)
		return (ft_error_msg(INVALID_ARG_NBR_ERROR));
	printf("\n-----checking arguments valid-----\n");
	if ((ac == 3 && !ft_is_valid_arg(av[1], av[2])) ||
		!ft_is_valid_arg(av[1], 0))
		return (ft_error_msg(INVALID_ARG_ERROR));
	printf("\n-----initialyze config-----\n");
	if (!(config = ft_calloc(sizeof(t_config), 1)) ||
		!(ft_initialyse_config(config)))
		return (ft_error_msg(INIT_ERROR));
	if ((error_value = ft_parse_file(config, av[1])))
		return (ft_error_msg(error_value));
	printf("\n----.cub is valid----\n");
	ft_receive_events(config, av[1]);
	/*ft_free_struct(config);*/
	return (0);
}
