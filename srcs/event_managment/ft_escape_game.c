/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_escape_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 09:49:32 by abarot            #+#    #+#             */
/*   Updated: 2020/04/19 10:07:12 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_destroy_images(t_config *config)
{
	mlx_destroy_image(config->mlx_ptr, config->img_set.west.img_ptr);
	mlx_destroy_image(config->mlx_ptr, config->img_set.east.img_ptr);
	mlx_destroy_image(config->mlx_ptr, config->img_set.north.img_ptr);
	mlx_destroy_image(config->mlx_ptr, config->img_set.south.img_ptr);
	mlx_destroy_image(config->mlx_ptr, config->img_set.sprite.img_ptr);
	mlx_destroy_image(config->mlx_ptr, config->img_set.screen.img_ptr);
	mlx_destroy_image(config->mlx_ptr, config->img_set.background.img_ptr);
	free(config->parse.path_set.north);
	free(config->parse.path_set.east);
	free(config->parse.path_set.south);
	free(config->parse.path_set.west);
	free(config->parse.path_set.sprite);
}

int		ft_escape_game(t_config *config)
{
	int line;

	line = 0;
	if (config->win_ptr)
		mlx_destroy_window(config->mlx_ptr, config->win_ptr);
	ft_destroy_images(config);
	while (config->parse.map_elt.map[line])
	{
		free(config->parse.map_elt.map[line]);
		line++;
	}
	free(config->mlx_ptr);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
