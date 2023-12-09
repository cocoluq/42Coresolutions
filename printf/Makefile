# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luqli <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 12:50:24 by luqli             #+#    #+#              #
#    Updated: 2023/11/27 12:50:26 by luqli            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SCRS = ft_printf.c\
		ft_putchar.c ft_putstr.c ft_putptr.c ft_puthex_low.c\
		ft_puthex_up.c ft_putun.c ft_putnbr.c
OBJS = $(SCRS:.c=.o)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -r $(OBJS)

fclean: clean
	rm -r $(NAME)

re: fclean all
.PHONY: all, clean, fclean, re