#include "cub3D.h"

void	ft_create_screenshot(t_config *config)
{
	int	fd;
	char *file_name;
	int		i_win;

	i_win = 0;
	file_name = "save.xpm";
	fd = open(file_name, O_WRONLY | O_APPEND | O_CREAT, 744);
	while ((config->win_ptr))
	{
		write(fd, config->win_ptr, 1);
		config->win_ptr++;
	}
}