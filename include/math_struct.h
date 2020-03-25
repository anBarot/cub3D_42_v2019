#ifndef MATH_STRUCT_H 
# define MATH_STRUCT_H 
# include <math.h>
# define RAD(degree)	((degree) * (M_PI / 180))

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;
typedef struct		s_fcoord
{
	double			x;
	double			y;
}					t_fcoord;
#endif