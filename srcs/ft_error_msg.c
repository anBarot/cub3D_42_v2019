/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:11:39 by abarot            #+#    #+#             */
/*   Updated: 2020/01/29 17:11:43 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

int		ft_error_msg(int error_value)
{
	(error_value == INVALID_ARG_NBR_ERROR) ? ft_printf
	("Error\nYou have too many arguments, only the name of the file .cub followed by -save are allowed\n") : 0;
	(error_value == INVALID_ARG_ERROR) ? ft_printf
	("Error\nThe file you are trying to read is not valid, check the extension '"'.cub'"'\n") : 0;
	(error_value == INIT_ERROR) ? ft_printf
	("Error\nThe programm initialyzation is not possible\n") : 0;
	(error_value == OPEN_FILE_ERROR) ? ft_printf
	("Error\nThe program can't be oppened, check if you have the appropriate rights\n") : 0;
	(error_value == MAP_VALUE_ERROR) ? ft_printf
	("Error\nTheir is an unauthorized value in the map\n") : 0;
	(error_value == MAP_BORDER_ERROR) ? ft_printf
	("Error\nHo no! You can escape!\n") : 0;
	(error_value == MAP_SIZE_ERROR) ? ft_printf
	("Error\nThe map isn't rectangular\n") : 0;
	(error_value == RESOL_ERROR) ? ft_printf
	("Error\nThe resolution is not in the right format : try '"'R XXXX YYYY'"'\n") : 0;
	(error_value == CF_COLOR_ERROR) ? ft_printf
	("Error\nThe color is not in the right format, try '"'C RRR,GGG,BBB'"' or '"'F RRR,GGG,BBB'"'") : 0;
	(error_value == MULTIPLAYER_ERROR) ? ft_printf
	("Error\nOnly one player can play the game") : 0;
	(error_value == PATH_NORTH_ERROR) ? ft_printf
	("Error\nYour north texture file can't be found, check if it has the appropriate extension or path") : 0;
	(error_value == PATH_WEST_ERROR) ? ft_printf
	("Error\nYour west texture file can't be found, check if it has the appropriate extension or path") : 0;
	(error_value == PATH_SOUTH_ERROR) ? ft_printf
	("Error\nYour south texture file can't be found, check if it has the appropriate extension or path") : 0;
	(error_value == PATH_EAST_ERROR) ? ft_printf
	("Error\nYour east texture file can't be found, check if it has the appropriate extension or path") : 0;
	(error_value == PATH_SPRITE_ERROR) ? ft_printf
	("Error\nYour sprite file can't be found, check if it has the appropriate extension or path") : 0;
	return (0);
}
