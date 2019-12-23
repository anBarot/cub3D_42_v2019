# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarot <abarot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/29 13:40:59 by abarot            #+#    #+#              #
#    Updated: 2019/12/11 18:29:06 by abarot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Cub3D

SRCS	=	srcs/main.c \
			srcs/xtract/ft_check_map.c srcs/xtract/ft_get_spec.c \
			srcs/toolbox/get_next_line.c srcs/toolbox/libft_redone.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-Wall -Wextra #-Werror

INCL	=	include

FRAMEWORK = -framework OpenGL -framework AppKit 

LIB 	= -lmlx -lXext -lX11 

LIB_PATH	=	-L/usr/local/lib

RM	=	rm -f
			
%.o : %.c
		gcc $(CFLAGS) -c $< -o $@ -I$(INCL)

all	:	
		make $(NAME)		

$(NAME)	: $(OBJS) 
			gcc   $(OBJS) $(LIB_PATH) $(LIB) -o $(NAME) -I$(INCL)
			
clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME) 

re	:	fclean all
