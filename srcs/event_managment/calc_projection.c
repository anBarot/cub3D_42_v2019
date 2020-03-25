#include "cub3D.h"

int	ft_calc_projection(int dist_obj, double tmp_angle, int cam_angle, int resol_x)
{
	int			prop_cste;
	double		center_angle;
	int			obj_proj;

	center_angle = cam_angle + (FOV / 2);
	if (center_angle > 360)
		center_angle -= 360;
	prop_cste = ((WALL_SIZE / 2) * ((resol_x /2) / tan(RAD(FOV / 2))));
	obj_proj = (prop_cste / (dist_obj * cos(RAD(fabs(center_angle - tmp_angle)))));
	return (obj_proj);
}