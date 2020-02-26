# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarot <abarot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/29 13:40:59 by abarot            #+#    #+#              #
#    Updated: 2020/01/31 15:17:02 by abarot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Cub3D

SRCS	=	srcs/main.c \
			srcs/display/ft_display_sprites.c \
			srcs/display/ft_display_wall.c \
			srcs/event_management/ft_receive_events.c \
			srcs/event_management/moves.c \
			srcs/initialysation/ft_error_msg.c \
			srcs/initialysation/ft_initialyse_config.c \
			srcs/initialysation/ft_initialyse_img.c \
			srcs/parse_functions/ft_get_cf_colors.c \
			srcs/parse_functions/ft_get_map_and_pcoor.c \
			srcs/parse_functions/ft_get_texture_and_resolution.c \
			srcs/parse_functions/ft_parse_file.c \
			srcs/raycast/ft_raycast.c 

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-Wall -Wextra #-Werror

INCL	=	include

FRAMEWORK = #-framework OpenGL -framework AppKit 

LIB 	= -lmlx  -lm -lXext -lX11  -lbsd

LIB_PATH	=	-L/usr/local/lib

RM	=	rm -f
			
%.o : %.c
		gcc -g $(CFLAGS) -c $< -o $@ -I$(INCL)

all	:	
		make -C libft
		make $(NAME)

$(NAME)	: $(OBJS) 
			gcc -g  $(OBJS) $(FRAMEWORK) libft.a $(LIBPATH) $(LIB) -o $(NAME) -I$(INCL)
			
clean	:
		$(RM) $(OBJS) && make -C libft fclean

fclean	:	clean
		$(RM) $(NAME) 

re	:	fclean all
