#ifndef MLX_IMG_TREATMENT_H
# define MLX_IMG_TREATMENT_H
# include <mlx.h>
# include "libft.h"
# include "raycast.h"
typedef struct 		s_img
{
	void			*img_ptr;
	char			*mlx;
	int				width;
	int				height;
	int				size_line;
	int				bpp;
	int				endian;
}					t_img;
typedef struct		s_color 
{
	int				R;
	int				G;
	int				B;
	int				alpha;
}					t_color;
void		ft_pixel_filling(char *mlx_to_fill, char *mlx_to_extract);
t_img		ft_scalling(void *mlx_ptr, t_img img_to_scale, int width, int height);
void		ft_put_img_to_screen(t_img screen, t_img img, int start_x, int start_y);
void		ft_put_sprite_to_screen(t_img screen, t_img sprite, int start_x, int start_y);
void		ft_fill_img_with_color(t_img *img, t_color color, t_coord starting_point, t_coord dim);
t_img		ft_shift_img(void *mlx_ptr, t_img img, int x, int y);
#endif