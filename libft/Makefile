# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarot <abarot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 12:18:43 by abarot            #+#    #+#              #
#    Updated: 2020/01/25 11:37:17 by abarot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCS	=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
			ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c \
			ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
			ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c   \
			ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c   \
			ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c    \
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c   \
			ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c  \
			ft_putendl_fd.c ft_putnbr_fd.c ft_toupper_string.c \
			ft_reverse_string.c ft_hextoa.c ft_addtoa.c ft_char_to_str.c \
			ft_is_printf_option.c ft_is_printf_type.c \
			ft_utoa.c ft_ftoa.c ft_scinottoa.c \
			ft_litoa.c ft_lhextoa.c ft_lutoa.c \
			ft_llitoa.c ft_llhextoa.c ft_llutoa.c 

OBJS	=	$(SRCS:.c=.o)

INCLUDE	=	../include

CFLAGS	=	-Werror -Wall -Wextra

RM	=	rm -f

%.o : %.c
	gcc $(FLAGS) -c $< -o $@ -I$(INCLUDE)

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