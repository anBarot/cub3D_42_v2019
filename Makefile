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
			srcs/initialysation/ft_error_msg.c \
			srcs/initialysation/ft_initialyse_config.c \
			srcs/initialysation/ft_is_valid_arg.c \
			srcs/parse_functions/ft_get_cf_colors.c \
			srcs/parse_functions/ft_get_map.c \
			srcs/parse_functions/ft_get_player_coor.c \
			srcs/parse_functions/ft_get_resolution.c \
			srcs/parse_functions/ft_get_texture_path.c \
			srcs/parse_functions/ft_parse_file.c \
			srcs/event_management/ft_receive_events.c \
			srcs/event_management/ft_pressed_key.c \
			srcs/event_management/moves.c  
			# srcs/display_functions/ft_display_screen.c \
			srcs/raycasting/ft_get_crosscoor_horizontal.c \
			srcs/raycasting/ft_get_crosscoor_special_angle.c \
			srcs/raycasting/ft_get_crosscoor_vertical.c \
			srcs/raycasting/ft_get_dist_to_wall.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-Wall -Wextra #-Werror

INCL	=	include

FRAMEWORK = #-framework OpenGL -framework AppKit 

LIB 	= -lmlx  -lm -lXext -lX11  

LIB_PATH	=	-L/usr/local/lib

RM	=	rm -f
			
%.o : %.c
		gcc $(CFLAGS) -c $< -o $@ -I$(INCL)

all	:	
		make -C libft
		make $(NAME)

$(NAME)	: $(OBJS) 
			gcc  $(OBJS) $(FRAMEWORK) libft.a $(LIBPATH) $(LIB) -o $(NAME) -I$(INCL)
			
clean	:
		$(RM) $(OBJS) && make -C libft fclean

fclean	:	clean
		$(RM) $(NAME) 

re	:	fclean all
