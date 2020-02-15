/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:11:39 by abarot            #+#    #+#             */
/*   Updated: 2020/01/31 14:51:23 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

int		ft_error_msg(int error_value)
{
	(error_value == INVALID_ARG_NBR_ERROR) ? ft_printf
	("Error\nYou have too many or too few arguments, only the name of the file .cub followed by -save are allowed\n") : 0;
	(error_value == INVALID_ARG_ERROR) ? ft_printf
	("Error\nThe file you are trying to read is not valid, check the extension '.cub'\n") : 0;
	(error_value == INIT_ERROR) ? ft_printf
	("Error\nThe programm initialyzation is not possible\n") : 0;
	(error_value == OPEN_FILE_ERROR) ? ft_printf
	("Error\nThe program can't be oppened, check if you have the appropriate rights\n") : 0;
	(error_value == MAP_ERROR) ? ft_printf
	("Error\nYour map is not valid, check the values or the border of the map\n") : 0;
	(error_value == RESOL_ERROR) ? ft_printf
	("Error\nThe resolution is not in the right format : try 'R XXXX YYYY'\n") : 0;
	(error_value == C_COLOR_ERROR) ? ft_printf
	("Error\nThe ceiling color is not in the right format, try 'C RRR,GGG,BBB' with values between 0 to 255\n") : 0;
	(error_value == F_COLOR_ERROR) ? ft_printf
	("Error\nThe floor color is not in the right format, try 'F RRR,GGG,BBB' with values between 0 to 255\n") : 0;
	(error_value == MULTIPLAYER_ERROR) ? ft_printf
	("Error\nNo multiplayer mode!\n") : 0;
	(error_value == NO_PLAYER_ERROR) ? ft_printf
	("Error\nThere is no player!\n") : 0;
	(error_value == N_PATH_ERROR) ? ft_printf
	("Error\nYour north texture file can't be found, check if it has the appropriate extension .xpm or path\n") : 0;
	(error_value == W_PATH_ERROR) ? ft_printf
	("Error\nYour west texture file can't be found, check if it has the appropriate extension .xpm or path\n") : 0;
	(error_value == SO_PATH_ERROR) ? ft_printf
	("Error\nYour south texture file can't be found, check if it has the appropriate extension .xpm or path\n") : 0;
	(error_value == E_PATH_ERROR) ? ft_printf
	("Error\nYour east texture file can't be found, check if it has the appropriate extension .xpm or path\n") : 0;
	(error_value == SP_PATH_ERROR) ? ft_printf
	("Error\nYour sprite file can't be found, check if it has the appropriate extension .xpm or path\n") : 0;
	return (0);
}
