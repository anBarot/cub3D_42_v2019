# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarot <abarot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/29 13:40:59 by abarot            #+#    #+#              #
#    Updated: 2020/01/06 13:17:36 by abarot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Cub3D

SRCS	=	srcs/main.c \
			srcs/xtract/ft_check_map.c srcs/xtract/ft_get_spec.c \
			srcs/toolbox/get_next_line.c srcs/toolbox/libft_redone.c \
			srcs/event_management/key_manage.c srcs/event_management/ray_casting.c\

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-Wall -Wextra #-Werror

INCL	=	include

FRAMEWORK = -framework OpenGL -framework AppKit 

LIB 	= -lmlx 

LIB_PATH	=	-L/usr/local/lib

RM	=	rm -f
			
%.o : %.c
		gcc $(CFLAGS) -c $< -o $@ -I$(INCL)

all	:	
		make $(NAME)		

$(NAME)	: $(OBJS) 
			gcc   $(OBJS) $(FRAMEWORK) $(LIB_PATH) $(LIB) -o $(NAME) -I$(INCL)
			
clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME) 

re	:	fclean all
