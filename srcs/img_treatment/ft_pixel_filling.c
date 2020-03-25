#include "mlx_img_treatment.h"

void	ft_pixel_filling(char *mlx_to_fill, char *mlx_to_extract)
{
	mlx_to_fill[0] = (unsigned int)mlx_to_extract[0];
	mlx_to_fill[1] = (unsigned int)mlx_to_extract[1];
	mlx_to_fill[2] = (unsigned int)mlx_to_extract[2];
	mlx_to_fill[3] = (unsigned int)mlx_to_extract[3];
}
