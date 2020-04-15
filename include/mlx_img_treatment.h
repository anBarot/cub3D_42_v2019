/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img_treatment.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 12:44:39 by abarot            #+#    #+#             */
/*   Updated: 2020/04/15 16:19:35 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_IMG_TREATMENT_H
# define MLX_IMG_TREATMENT_H
# include <mlx.h>
# include "libft.h"
# include "raycast.h"

typedef struct		s_img_2
{
	void			*img_ptr;
	char			*mlx;
	int				width;
	int				height;
	int				size_line;
	int				bpp;
	int				endian;
}					t_img_2;
typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
	int				alpha;
}					t_color;
void				ft_pixel_filling(char *mlx_to_fill, char *mlx_to_extract);
t_img_2				ft_scalling(void *mlx_ptr, t_img_2 img_to_scale, int width,
					int height);
void				ft_put_img_to_screen(t_img_2 screen, t_img_2 img,
					int start_x, int start_y);
void				ft_put_sprite_to_screen(t_img_2 screen, t_img_2 sprite,
					int start_x, int start_y);
void				ft_draw_square(t_img_2 *img, t_color color,
					t_coord starting_point, t_coord dim);
#endif
