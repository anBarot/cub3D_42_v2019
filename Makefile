# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarot <abarot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/29 13:40:59 by abarot            #+#    #+#              #
#    Updated: 2020/01/30 11:51:47 by abarot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Cub3D

SRCS	=	srcs/main.c \
			srcs/initialysation/ft_error_msg.c \
			srcs/initialysation/ft_initialyse_config.c \
			srcs/initialysation/ft_is_valid_arg.c \
			srcs/parse_functions/ft_get_cf_colors.c \
			srcs/parse_functions/ft_get_map.c \
			srcs/parse_functions/ft_get_player_coor.c \
			srcs/parse_functions/ft_get_resolution.c \
			srcs/parse_functions/ft_get_texture_path.c \
			srcs/parse_functions/ft_parse_file.c \
			srcs/toolbox/get_next_line.c \
			srcs/toolbox/libft_redone.c \
			srcs/event_management/ft_display_screen.c \
			srcs/event_management/ft_move_backward.c \
			srcs/event_management/ft_move_forward.c \
			srcs/event_management/ft_move_lat_left.c \
			srcs/event_management/ft_move_lat_rigth.c \
			srcs/event_management/ft_receive_events.c \
			srcs/event_management/ft_turn_left.c \
			srcs/event_management/ft_turn_rigth.c \
			srcs/event_management/key_manage.c \
			srcs/event_management/ray_casting.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-Wall -Wextra #-Werror

INCL	=	include

FRAMEWORK = -framework OpenGL -framework AppKit 

LIB 	= -lmlx #-lm -lXext -lX11

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
