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
	return (0);
}
