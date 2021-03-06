/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_screenshot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 17:16:31 by abarot            #+#    #+#             */
/*   Updated: 2020/04/19 15:28:11 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialize.h"

void	ft_create_bmp_header(t_config *config, int fd)
{
	int			count;
	t_header	head;

	count = 7;
	head.size = 4 * config->parse.resol.x * config->parse.resol.y;
	head.reserved = 0;
	head.offset_bits = 54;
	head.header_bytes = 40;
	head.planes = 1;
	write(fd, "BM", 2);
	write(fd, &head.size, 4);
	write(fd, &head.reserved, 4);
	write(fd, &head.offset_bits, 4);
	write(fd, &head.header_bytes, 4);
	write(fd, &config->parse.resol.x, 4);
	write(fd, &config->parse.resol.y, 4);
	write(fd, &head.planes, 2);
	write(fd, &config->img_set.screen.bpp, 2);
	while (count--)
		write(fd, &head.reserved, 4);
}

void	ft_copy_mlx_string(t_config *config, int fd)
{
	int		col;
	int		line;
	int		i_towrite;

	col = 0;
	line = config->parse.resol.y;
	i_towrite = 0;
	while (line > 0)
	{
		while (col < config->parse.resol.x)
		{
			i_towrite = col * 4 + line * config->img_set.screen.size_line;
			write(fd, config->img_set.screen.mlx + i_towrite, 4);
			col++;
		}
		col = 0;
		line--;
	}
}

void	ft_create_screenshot(t_config *config, char *av1)
{
	int		fd;
	char	*file_name;
	char	*tmp;
	char	*tmp2;

	tmp = ft_substr(av1, 4, 10);
	tmp2 = ft_strtrim(tmp, ".cub");
	free(tmp);
	file_name = ft_strjoin(tmp2, ft_strdup(".bmp"));
	fd = open(file_name, O_WRONLY | O_CREAT, 0644);
	ft_create_bmp_header(config, fd);
	ft_copy_mlx_string(config, fd);
	free(file_name);
	close(fd);
}
