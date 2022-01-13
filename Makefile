SRCS		= 

OBJS		= $(SRCS:.c=.o)

LIB			= ./libft/libft.a

CC			= gcc
RM			= rm -f
MLX			= -lmlx -framework OpenGl -framework AppKit
CFLAGS		= -Wall -Wextra -Werror $(MLX) -c -I./includes

NAME		= fdf

all:		$(NAME)

.o:			
			$(CC) $(CFLAGS) $< -o ${<.c=.o}

$(NAME):	$(OBJS)
			$(MAKE) -C ./libft
			$(CC) $(LIB) $(OBJS) -o $(NAME)

clean:		
			$(RM) $(OBJS)
			$(MAKE) clean -C ./libft

fclean:		clean
			$(RM) $(LIB) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re
