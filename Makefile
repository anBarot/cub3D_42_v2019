# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarot <abarot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/29 13:40:59 by abarot            #+#    #+#              #
#    Updated: 2020/01/27 14:48:09 by abarot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Cub3D

SRCS	=	srcs/main.c \
			srcs/parse_functions/ft_check_map.c srcs/parse_functions/ft_get_spec.c \
			srcs/toolbox/get_next_line.c srcs/toolbox/libft_redone.c \
			srcs/event_management/key_manage.c srcs/event_management/ray_casting.c\
			srcs/event_management/ft_display_screen.c 

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
