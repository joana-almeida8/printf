# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jreis-de <jreis-de@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/09 18:42:28 by jreis-de          #+#    #+#              #
#    Updated: 2025/11/09 18:42:28 by jreis-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprinf.a

SRCS = ft_printf.c ft_printf_utils.c ft_printf_utilz.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I Includes
AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) *.o

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
