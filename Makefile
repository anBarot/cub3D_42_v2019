# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarot <abarot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/29 13:40:59 by abarot            #+#    #+#              #
#    Updated: 2019/11/29 14:47:27 by abarot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Cub3D

SRCS	=	srcs/main.c srcs/ft_check_map.c srcs/ft_get_spec.c srcs/get_next_line.c \
			srcs/libft_redone.c

INCL	=	include/cub3D.h 

OBJS	=	$(SRCS:.c=.o)

OBJS_ARCH	=	objs.a

LIB_MLX		=	minilibx_opengl_20191021/libmlx.a

CFLAGS	=	-Wall -Wextra

RM	=	rm -f
			
%.o : %.c
		clang $(FLAGS) -c $< -o $@ 

all	:	
		make -C minilibx_opengl_20191021/ && make $(NAME)
		ar -rc $(OBJS_ARCH) $(OBJS)
		clang $(FLAGS) $(OBJS_ARCH) $(LIB_MLX) -o $(NAME)

$(NAME)	: $(OBJS) 

clean	:
		$(RM) $(OBJS) $(OBJS_ARCH)

fclean	:	clean
		$(RM) $(NAME) 

re	:	fclean all