/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarot <abarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 13:19:04 by abarot            #+#    #+#             */
/*   Updated: 2020/04/12 18:51:53 by abarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include "libft.h"

typedef struct			s_spec
{
	int					type;
	int					zero_less_flag;
	int					space_plus_flag;
	int					hashtag_flag;
	int					width;
	int					precision;
	int					size;
	char				*arg_str;
}						t_spec;
enum					e_zero_less_flag
{
	NO_FLAG_ZERO_LESS,
	ZERO,
	LESS,
};
enum					e_space_plus_flag
{
	NO_FLAG_SPACE_PLUS,
	SPACE,
	PLUS
};
enum					e_type
{
	ERROR,
	CHAR,
	CHAR_IS_ZERO,
	STRING,
	ADDRESS,
	HEXADEC,
	CAP_HEXADEC,
	SIGNED_INT,
	UNSIGNED_INT,
	PERC,
};
int						ft_printf(const char *str, ...);
int						ft_formated_string(const char *str, va_list arg_lst);
void					ft_initialyse_spec(t_spec *spec);
int						ft_spec_is_valid(const char *str);
int						ft_apply_not_valid(char *str, t_spec *spec);
void					ft_get_type(const char *str, t_spec *spec);
void					ft_get_flags(const char *str, t_spec *spec);
void					ft_get_width(const char *str, va_list lst,
						t_spec *spec);
void					ft_get_precision_and_size(const char *str, va_list lst,
						t_spec *spec);
void					ft_get_arg_as_a_string(va_list lst, t_spec *spec);
void					ft_apply_spec(t_spec *spec);
void					ft_apply_no_flag(t_spec *spec);
void					ft_apply_hashtag(t_spec *spec);
void					ft_apply_less(t_spec *spec);
void					ft_apply_plus(t_spec *spec);
void					ft_apply_space(t_spec *spec);
void					ft_apply_zero(t_spec *spec);
void					ft_apply_precision(t_spec *spec);
void					ft_apply_precision_address(t_spec *spec);
void					ft_apply_precision_number(t_spec *spec);
void					ft_apply_precision_string(t_spec *spec);
void					ft_display_char_is_zero(t_spec *spec);
int						ft_is_printf_type(char c);
int						ft_is_printf_option(char c);
#endif
