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

#include "initialize.h"

int		ft_error_msg_3(int error_value)
{
	(error_value == NO_C_COLOR_ERROR) ?
	ft_printf("Error\nThe ceiling color is missing, add the line \
'C RRR,GGG,BBB'\n") : 0;
	(error_value == NO_F_COLOR_ERROR) ?
	ft_printf("Error\nThe floor color is missing, add the line \
'F RRR,GGG,BBB'\n") : 0;
	(error_value == NO_N_PATH_ERROR) ?
	ft_printf("Error\nThe path to the north texture is missing, add the \
line 'NO ./path/to/the/north'\n") : 0;
	(error_value == NO_SO_PATH_ERROR) ?
	ft_printf("Error\nThe path to the south texture is missing, add the \
line 'SO ./path/to/the/south'\n") : 0;
	(error_value == NO_W_PATH_ERROR) ?
	ft_printf("Error\nThe path to the west texture is missing, add the \
line 'WE ./path/to/the/west'\n") : 0;
	(error_value == NO_E_PATH_ERROR) ? 
	ft_printf("Error\nThe path to the east texture is missing, add the \
line 'EA ./path/to/the/east'\n") : 0;
	(error_value == NO_SP_PATH_ERROR) ?
	ft_printf("Error\nThe path to the sprite is missing, add the line \
'S ./path/to/the/sprite'\n") : 0;
	return (0);
}

int		ft_error_msg_2(int error_value)
{
	(error_value == IMG_EXTENSION_ERROR) ?
	ft_printf("Error\nYour image isn't an XPM image\n") : 0;
	(error_value == C_COLOR_ERROR) ?
	ft_printf("Error\nThe ceiling color is not in the right format, try \
'C RRR,GGG,BBB' with values between 0 to 255\n") : 0;
	(error_value == F_COLOR_ERROR) ?
	ft_printf("Error\nThe floor color is not in the right format, try \
'F RRR,GGG,BBB' with values between 0 to 255\n") : 0;
	(error_value == MULTIPLAYER_ERROR) ? 
	ft_printf("Error\nNo multiplayer mode!\n") : 0;
	(error_value == NO_PLAYER_ERROR) ?
	ft_printf("Error\nThere is no player!\n") : 0;
	(error_value == INVALID_PATH_ERROR) ?
	ft_printf("Error\nYour file can't be found, check if it has the \
appropriate extension .xpm or path\n") : 0;
	(error_value == NO_RESOL_ERROR) ?
	ft_printf("Error\nThe resolution is missing, add the line \
'R XXXX YYYY'\n") : 0;
	return (ft_error_msg_3(error_value));
}

int		ft_error_msg(int error_value)
{
	(error_value == INVALID_ARG_NBR_ERROR) ? 
	ft_printf("Error\nYou have too many or too few arguments, only the \
name of the file .cub followed by -save are allowed\n") : 0;
	(error_value == INVALID_ARG_ERROR) ? 
	ft_printf("Error\nThe file you are trying to read is not valid, check \
the extension '.cub' or the argument '-save'\n") : 0;
	(error_value == INIT_ERROR) ? 
	ft_printf("Error\nThe programm initialyzation is not possible\n") : 0;
	(error_value == OPEN_FILE_ERROR) ?
	ft_printf("Error\nThe program can't be oppened, check if you have the \
appropriate rights\n") : 0;
	(error_value == MAP_VALUE_ERROR) ? 
	ft_printf("Error\nThere is an invalid value in your map, the valid values are ->\
'012NESW'\n") : 0;
	(error_value == MAP_BORDER_ERROR) ? 
	ft_printf ("Error\nThere is a leack in your wall!\n") : 0;
	(error_value == MAP_OVERFLOW) ? 
	ft_printf("Error\nYour map is over 1 million lines, try to get a \
smaller one\n") : 0;
	(error_value == RESOL_ERROR) ?
	ft_printf("Error\nThe resolution is not in the right format : try \
'R XXXX YYYY'\n") : 0;
	return (ft_error_msg_2(error_value));
}
