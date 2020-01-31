# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarot <abarot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/29 13:40:59 by abarot            #+#    #+#              #
#    Updated: 2020/01/31 12:11:00 by abarot           ###   ########.fr        #
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
			srcs/parse_functions/ft_parse_file.c 
			# srcs/event_management/ft_move_backward.c  \
			# srcs/event_management/ft_move_forward.c \
			# srcs/event_management/ft_move_lat_left.c  \
			# srcs/event_management/ft_move_lat_rigth.c  \
			# srcs/event_management/ft_receive_events.c  \
			# srcs/event_management/ft_turn_left.c  \
			# srcs/event_management/ft_turn_rigth.c \
			# srcs/event_management/key_manage.c \
			srcs/display_functions/ft_display_screen.c  \
			# srcs/raycasting/ft_calc_magnitude.c \
			# srcs/raycasting/ft_get_crosscoor_horizontal.c \
			# srcs/raycasting/ft_get_crosscoor_special_angle.c \
			# srcs/raycasting/ft_get_crosscoor_vertical.c \
			# srcs/raycasting/ft_get_dist_to_wall.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-Wall -Wextra #-Werror

INCL	=	include

FRAMEWORK = -framework OpenGL -framework AppKit 

LIB 	= -lmlx -llibft #-lm -lXext -lX11  

LIB_PATH	=	-L/usr/local/lib

RM	=	rm -f
			
%.o : %.c
		gcc $(CFLAGS) -c $< -o $@ -I$(INCL)

all	:	
		make $(NAME)		

$(NAME)	: $(OBJS) 
			gcc libft.a $(OBJS) $(FRAMEWORK) -o $(NAME) -I$(INCL)
			
clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME) 

re	:	fclean all
