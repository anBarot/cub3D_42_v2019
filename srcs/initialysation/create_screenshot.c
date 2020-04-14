#include "initialize.h"

typedef struct s_header
{
	int		size; 
	int		reserved; 
	int		offset_bits; 
	int		header_bytes; 
	int		planes;
}			t_header;

void	ft_initialyze_bmp_header(t_config *config, t_header *head)
{
	head->size = 4 * config->parse.resol.x * config->parse.resol.y;
	head->reserved = 0;
	head->offset_bits = 54;
	head->header_bytes = 40;
	head->planes = 1;
}

void	ft_create_mlx_string(t_config *config, int fd)
{
	int col;
	int line;
	int	d_towrite;

	col = config->parse.resol.x;
	line = config->parse.resol.y;
	d_towrite = 0;
	while (line > 0)
	{
		while (col > 0)
		{
			d_towrite = col * 4 + line * config->img_set.screen.size_line;
			write(fd, config->img_set.screen.mlx + d_towrite, 4);
			col--;
		}
		col = config->parse.resol.x;
		line--;
	}
}

void	ft_create_screenshot(t_config *config)
{
	int		fd;
	char	*file_name;
	t_header head;
	int count;

	count = 6;
	file_name = "screenshot.bmp";
	fd = open(file_name, O_WRONLY | O_APPEND | O_CREAT, 0644);
	ft_initialyze_bmp_header(config, &head);
	write(fd, "BM", 2);
	write(fd, &head.size, 4);
	write(fd, &head.reserved, 4);
	write(fd, &head.offset_bits, 4);
	write(fd, &head.header_bytes, 4);
	write(fd, &config->parse.resol.x, 4);
	write(fd, &config->parse.resol.y, 4);
	write(fd, &head.planes, 2);
	write(fd, &config->img_set.screen.bpp, 2);
	while (count)
	{
		write(fd, &head.reserved, 4);
		count--;
	}
	ft_create_mlx_string(config, fd);
	close(fd);
	printf("\nquitting screenshot function\n");
}