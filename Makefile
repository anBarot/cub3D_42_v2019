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
			srcs/event_managment/ft_draw_sprites.c \
			srcs/event_managment/ft_draw_walls.c \
			srcs/event_managment/calc_projection.c \
			srcs/event_managment/ft_receive_events.c \
			srcs/event_managment/moves.c \
			srcs/img_treatment/ft_fill_img_with_color.c \
			srcs/img_treatment/ft_pixel_filling.c \
			srcs/img_treatment/ft_put_img_to_screen.c \
			srcs/img_treatment/ft_put_sprite_to_screen.c \
			srcs/img_treatment/ft_scalling.c \
			srcs/img_treatment/ft_shift_img.c \
			srcs/initialysation/create_screenshot.c \
			srcs/initialysation/ft_error_msg.c \
			srcs/initialysation/ft_initialyse_config.c \
			srcs/initialysation/initialyse_images.c \
			srcs/parsing/ft_get_cf_colors.c \
			srcs/parsing/ft_get_map_and_pcoor.c \
			srcs/parsing/ft_get_texture_and_resolution.c \
			srcs/parsing/ft_parse_file.c \
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
