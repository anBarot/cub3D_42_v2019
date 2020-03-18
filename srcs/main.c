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

int		ft_is_valid_arg(const char *av_1, const char *av_2)
{
	int		i_ext;

	i_ext = ft_strlen(av_1) - 4;
	if (av_2)
		if (ft_strncmp(av_2, "-save", 6))
			return (0);
	if (i_ext < 1 || ft_strncmp(av_1 + i_ext, ".cub", 4))
		return (0);
	return (1);
}

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
	if ((error_value = ft_init_parsing(config, av[1])))
		return (ft_error_msg(error_value));

	// test parse
	printf("\n----.cub is valid----\n");
	printf("\nresolution : %dx%d\ncolor : F %d%d%d, C %d%d%d\npaths : \nN : %s\nE : %s\nW : %s\nS : %s\nSp : %s\n",
	config->resol.x, config->resol.y, config->col_floor.R, config->col_floor.G, config->col_floor.B,
	config->col_ceil.R, config->col_ceil.G, config->col_ceil.B,
	config->path_north, config->path_east, config->path_west, 
	config->path_south, config->path_sprite);
	int i = 0;
	while (config->map[i])
	{
		printf("\nmap %2d  : %s", i, config->map[i]);
		i++;
	}
	printf("\ncoor : %d,%d\n", config->player_coord.x, config->player_coord.y);
	// fin test parse

	config->mlx_ptr = mlx_init();
	config->win_ptr = mlx_new_window(config->mlx_ptr, config->resol.x, config->resol.y, av[1]);
	ft_create_texture(config);
	ft_create_screen(config);
	if (ac == 3)
	{
		ft_display_wall(config);
		ft_display_sprites(config);
		ft_create_screenshot(config);
		ft_escape_game(config);
		return (0);
	}
	ft_receive_events(config);
	return (0);
}
