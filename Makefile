# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaewonki <jaewonki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/28 14:41:15 by jaewonki          #+#    #+#              #
#    Updated: 2022/02/28 14:41:15 by jaewonki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libftprintf.a

SRCS 		= ft_printf.c \
			  parse_arg.c \
			  check_format.c \
			  print_char.c \
			  print_nbr.c \
			  print_str.c \
			  utils.c

OBJS		= $(SRCS:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

$(NAME)	: $(OBJS)
	ar rcs $(NAME) $(OBJS)

all : $(NAME)

clean	:
	rm -f $(OBJS)

fclean	: clean
	rm -f $(NAME)

re		: fclean all

.PHONY	: all clean fclean re