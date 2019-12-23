/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:17:50 by abarot            #+#    #+#             */
/*   Updated: 2019/12/11 18:55:23 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

int		errno;

int	ft_key_pressed(int keycode, t_spec *spec)
{
	if (keycode == 65362 || keycode == 122)
	{
		printf("\nmove forward\n");
		ft_move_forward(spec);
	}
	if (keycode == 65364 || keycode == 115)
	{
		printf("\nmove backward\n");
		ft_move_backward(spec);
	}
	if (keycode == 65361 || keycode == 113)
	{	
		printf("\nturn left\n");
		ft_turn_left(spec);
	}
	if (keycode == 65363 || keycode == 100)
	{	
		printf("\nturn rigth\n");
		ft_turn_right(spec);
	}
	if (keycode == 65307)
	{	
		printf("\nescape programm\n");
		mlx_destroy_window (spec->mlx_ptr, spec->win_ptr);
		return (0);
	}
	printf("\ncoor playeur : \nline : %d\ncol : %d\ndir : %c\n", spec->coord_player[0], spec->coord_player[1], spec->dir[0]);
	return (1);
}

void	ft_move_forward(t_spec *spec)
{
	if (*spec->dir == 'N' && spec->map[spec->coord_player[0] - 1][spec->coord_player[1]] != '1')
		spec->coord_player[0] -= 1;
	else if (*spec->dir == 'W' && spec->map[spec->coord_player[0]][spec->coord_player[1] - 1] != '1')
		spec->coord_player[1] -= 1;
	else if (*spec->dir == 'S' && spec->map[spec->coord_player[0] + 1][spec->coord_player[1]] != '1')
		spec->coord_player[0] += 1;
	else if (*spec->dir == 'E' && spec->map[spec->coord_player[0]][spec->coord_player[1] + 1] != '1')
		spec->coord_player[1] += 1;
}

void	ft_move_backward(t_spec *spec)
{
	if (*spec->dir == 'N' && spec->map[spec->coord_player[0] + 1][spec->coord_player[1]] != '1')
		spec->coord_player[0] += 1;
	else if (*spec->dir == 'W' && spec->map[spec->coord_player[0]][spec->coord_player[1] + 1] != '1')
		spec->coord_player[1] += 1;
	else if (*spec->dir == 'S' && spec->map[spec->coord_player[0] - 1][spec->coord_player[1]] != '1')
		spec->coord_player[0] -= 1;
	else if (*spec->dir == 'E' && spec->map[spec->coord_player[0]][spec->coord_player[1] - 1] != '1')
		spec->coord_player[1] -= 1;
}

void	ft_turn_left(t_spec *spec)
{
	if (*(spec->dir) == 'N')
		*(spec->dir) = 'W';
	else if (*(spec->dir) == 'W')
		*(spec->dir) = 'S';
	else if (*(spec->dir) == 'S')
		*(spec->dir) = 'E';
	else if (*(spec->dir) == 'E')
		*(spec->dir) = 'N';
}

void	ft_turn_right(t_spec *spec)
{
	if (*(spec->dir) == 'N')
		*(spec->dir) = 'E';
	else if (*(spec->dir) == 'W')
		*(spec->dir) = 'N';
	else if (*(spec->dir) == 'S')
		*(spec->dir) = 'W';
	else if (*(spec->dir) == 'E')
		*(spec->dir) = 'S';
}

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
	while (mlx_key_hook(spec->win_ptr, &(ft_key_pressed), spec))
		mlx_loop(spec->mlx_ptr);
	// free(spec);
	printf("\n------quitting main------\n");
	return (0);
}

//to dos :

//- struc raycast;

//- functions :
// calc 
// 
