# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarot <abarot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 12:18:43 by abarot            #+#    #+#              #
#    Updated: 2020/01/31 12:14:53 by abarot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	../libft.a

SRCS	=	ft_addtoa.c ft_atoi.c ft_bzero.c ft_calloc.c ft_char_to_str.c \
			ft_hextoa.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
			ft_isprint.c ft_itoa.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
			ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
			ft_putnbr_fd.c ft_putstr_fd.c ft_remove_in_str.c ft_reverse_string.c \
			ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c \
			ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
			ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
			ft_toupper.c ft_toupper_string.c ft_utoa.c get_next_line.c \
			ft_is_char_in_set.c \
			ft_printf/ft_is_printf_option.c  \
			ft_printf/ft_is_printf_type.c \
			ft_printf/ft_printf.c \
			ft_printf/initialyse_and_apply_spec/apply_spec.c \
			ft_printf/initialyse_and_apply_spec/create_formated_string.c \
			ft_printf/initialyse_and_apply_spec/ft_display_char_is_zero.c \
			ft_printf/initialyse_and_apply_spec/ft_initialyse_spec.c \
			ft_printf/initialyse_and_apply_spec/ft_spec_is_valid.c \
			ft_printf/parse_functions/ft_get_arg_as_a_string.c \
			ft_printf/parse_functions/ft_get_flags.c \
			ft_printf/parse_functions/ft_get_precision_and_size.c \
			ft_printf/parse_functions/ft_get_type.c \
			ft_printf/parse_functions/ft_get_width.c \
			ft_printf/precision/ft_apply_precision_address.c \
			ft_printf/precision/ft_apply_precision_number.c \
			ft_printf/precision/ft_apply_precision_string.c \
			ft_printf/width_and_flag/ft_apply_hashtag.c \
			ft_printf/width_and_flag/ft_apply_less.c \
			ft_printf/width_and_flag/ft_apply_no_flag.c \
			ft_printf/width_and_flag/ft_apply_plus.c \
			ft_printf/width_and_flag/ft_apply_space.c \
			ft_printf/width_and_flag/ft_apply_zero.c 

OBJS	=	$(SRCS:.c=.o)

INCLUDE	=	../include

CFLAGS	=	-Werror -Wall -Wextra

RM	=	rm -f

%.o : %.c
	gcc -c $< -o $@ -I$(INCLUDE)

all	:
		make $(NAME)

$(NAME) :	$(OBJS)
			ar -rc $@ $(OBJS)
			ranlib $@

clean	:
		$(RM) $(OBJS) 

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all