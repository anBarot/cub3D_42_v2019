/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:17:50 by abarot            #+#    #+#             */
/*   Updated: 2020/04/14 20:19:17 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_screen(t_config *config)
{
	ft_create_texture(config->mlx_ptr, &config->img_set,
	config->parse.path_set);
	ft_create_screen(config->mlx_ptr, &config->img_set.screen,
	config->parse.resol);
	ft_initialize_screen(&config->img_set.screen, config->parse.col_ceil,
	config->parse.col_floor);
	ft_draw_walls(config);
	ft_draw_sprites(config);
}

int		ft_is_valid_arg(const char *av_1, const char *av_2)
{
	int		i_ext;

	i_ext = ft_strlen(av_1) - 4;
	if (av_2)
		if (ft_strncmp(av_2, "--save", 6))
			return (0);
	if (i_ext < 1 || ft_strncmp(av_1 + i_ext, ".cub", 4))
		return (0);
	return (1);
}

int		main(int ac, char **av)
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
	if ((error_value = ft_init_parsing(&config->parse, av[1])))
		return (ft_error_msg(error_value));
	config->mlx_ptr = mlx_init();
	ft_get_screen(config);
	if (ac == 3)
	{
		ft_create_screenshot(config, av[1]);
		ft_escape_game(config);
	}
	config->win_ptr = mlx_new_window(config->mlx_ptr, config->parse.resol.x,
	config->parse.resol.y, av[1]);
	return (ft_receive_events(config));
}
