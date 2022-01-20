# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/13 19:57:00 by bregneau          #+#    #+#              #
#    Updated: 2022/01/20 21:13:16 by bregneau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	srcs/get_next_line.c \
				srcs/ft_draw_line.c \
				srcs/ft_parsing.c \
				srcs/ft_puterror.c \
				srcs/ft_destroy.c \
				srcs/ft_init.c \
				srcs/ft_image.c \
				srcs/ft_map.c \
				main.c

OBJS		= $(SRCS:.c=.o)

LIB			= ./libft/libft.a

CC			= gcc
RM			= rm -f
MLX			= -lmlx -framework OpenGl -framework AppKit
CFLAGS		= -Wall -Wextra -Werror -I./includes -g

NAME		= fdf

all:		$(NAME)

%.o: %.c
			@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(LIB) $(OBJS)
			@$(CC) -fsanitize=address -g3 $(MLX) $(LIB) $(OBJS) -o $(NAME)
			@echo "fdf executable created"

$(LIB):	
			@echo "Compiling libft..."
			@make -C libft
			@make clean -C libft

clean:		
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(LIB) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re
