#include "initialize.h"

void	ft_create_screenshot(t_img screen)
{
	int		fd;
	char	*file_name;

	file_name = "screenshot.xpm";
	fd = open(file_name, O_WRONLY | O_APPEND | O_CREAT, 774);
	close(fd);
	printf("\nquitting screenshot function\n");
}